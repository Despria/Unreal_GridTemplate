// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Subsystem/GridSubsystem.h"
#include "Algo/Reverse.h"

void UGridSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	InitializeGrid();
}

void UGridSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UGridSubsystem::InitializeGrid()
{
	if (!GridCells.IsEmpty()) GridCells.Empty();
	
	for (int i = 0; i < GridYLength; i++)
	{
		for (int j = 0; j < GridXLength; j++)
		{
			FGridCellData GridCellData = FGridCellData();
			GridCellData.CellGridCoord = FIntVector(j, i, ActiveLayer);
			
			// 추후 LayerBaseHeights 사용 시
			// GridCellData.CellWorldLocation = GridOrigin + FVector(j * CellSize, i * CellSize, LayerBaseHeights[ActiveLayer]);
			GridCellData.CellWorldLocation = GridOrigin + FVector(j * CellSize, i * CellSize, 0);
			GridCells.Add(FIntVector(j, i, ActiveLayer), GridCellData);
		}
	}
	OnInitializedGrid.Broadcast();
}

#pragma region Cell Properties
/**
 * Switch World Location into Cell Coordinate.
 * Unreal World Coordinate -> X Axis = Front/Back, Y Axis = Left/Right,
 * Need to Swap X <-> Y to make it looks like Standard X/Y Axis Coordinate.
 * @param WorldLocation FVector World Location to convert into Cell Coordinate.
 * @return CellCoord FIntVector
 */
FIntVector UGridSubsystem::WorldLocationToCellCoord(FVector WorldLocation) const
{
	int32 CoordX= FMath::FloorToInt((WorldLocation.Y - GridOrigin.Y) / CellSize);
	int32 CoordY= FMath::FloorToInt((WorldLocation.X - GridOrigin.X) / CellSize);
	
	return FIntVector(CoordX, CoordY, ActiveLayer);
}

/**
 * Switch Cell Coordinate into World Location.
 * Unreal World Coordinate -> X Axis = Front/Back, Y Axis = Left/Right,
 * Need to Swap X <-> Y to make it looks like Unreal X/Y Axis Coordinate.
 * @param GridCoord FIntVector Cell Coordinate to convert into World Location.
 * @return WorldLocation FVector
 */
FVector UGridSubsystem::CellCenterAsWorldLocation(FIntVector GridCoord) const
{
	const float* BaseHeight = LayerBaseHeights.Find(GridCoord.Z);
	const float LayerZ = BaseHeight ? *BaseHeight : 0.f;

	return FVector(
		GridOrigin.X + (GridCoord.Y * CellSize) + (CellSize * 0.5f),
		GridOrigin.Y + (GridCoord.X * CellSize) + (CellSize * 0.5f),
		GridOrigin.Z + LayerZ + 0.f  // HeightOffset은 SetCellHeightOffset으로 별도 설정
	);
}

FVector UGridSubsystem::CellCoordToWorldLocation(FIntVector GridCoord) const
{
	// 그리드 좌표를 월드 좌표로 변환
	const float* BaseHeight = LayerBaseHeights.Find(GridCoord.Z);
	const float LayerZ = BaseHeight ? *BaseHeight : 0.f;

	return FVector(
		// 언리얼의 좌표계는 Y축이 좌/우, X축이 앞/뒤를 가리키므로, 서로 변환해서 반환해야 함.
		GridOrigin.X + (GridCoord.Y * CellSize),
		GridOrigin.Y + (GridCoord.X * CellSize),
		GridOrigin.Z + LayerZ + 0.f  // HeightOffset은 SetCellHeightOffset으로 별도 설정
	);
}

bool UGridSubsystem::IsValidCell(FIntVector GridCoord) const
{
	return GridCells.Contains(GridCoord);
}

TArray<FIntVector> UGridSubsystem::GetAllCellCoords() const
{
	TArray<FIntVector> AllCellCoords;
	GridCells.GetKeys(AllCellCoords);
	return AllCellCoords;
}

void UGridSubsystem::SetActiveLayer(int32 NewLayer)
{
	ActiveLayer = NewLayer;
}

void UGridSubsystem::SetCellHeightOffset(FIntVector GridCoord, float NewHeightOffset)
{
	GridCells[GridCoord].HeightOffset = NewHeightOffset;
}

bool UGridSubsystem::IsValidLayer(int32 Layer) const
{
	return LayerBaseHeights.Find(Layer);
}
#pragma endregion 

#pragma region A* Pathfinding
/**
 * Find Path(FIntVector Array) From StartCoord to EndCoord.
 * @param StartCoord Starting Point
 * @param EndCoord Target Point
 * @param bIsDiagonal Defines whether it is Euclidean Distance(Allow Diagonal Movement) or Manhattan Distance(Only Straight Movement).
 * @return Path from StartCoord to EndCoord. Empty TArray if no Path found.
 */
TArray<FIntVector> UGridSubsystem::AlphaStarPathfinding(FIntVector StartCoord, FIntVector EndCoord, bool bIsDiagonal)
{
	// Initialize A* Pathfinding
	TMap<FIntVector, FGridCellPathfindData> PathfindCells = TMap<FIntVector, FGridCellPathfindData>();
	TSet<FIntVector> OpenCellCoords = TSet<FIntVector>();
	TSet<FIntVector> ClosedCellCoords = TSet<FIntVector>();
	
	FIntVector SearchCellCoord = StartCoord;
	FGridCellPathfindData StartCellPathfindData = FGridCellPathfindData();
	StartCellPathfindData.CellCoord = SearchCellCoord;
	PathfindCells.Add(SearchCellCoord, StartCellPathfindData);
	OpenCellCoords.Add(SearchCellCoord);
	
	PathfindCells[StartCoord].GCost = 0;
	PathfindCells[StartCoord].HCost = CalculateHCost(SearchCellCoord, EndCoord, bIsDiagonal);
	PathfindCells[StartCoord].FCost = PathfindCells[SearchCellCoord].GCost + PathfindCells[SearchCellCoord].HCost;
	
	// Search until path is found, or OpenCellCoords become empty.
	while (!OpenCellCoords.IsEmpty())
	{
		// Get LowestCellCoord from OpenCellCoords
		SearchCellCoord = GetLowestFCostCellCoord(OpenCellCoords, PathfindCells);
		if (IsTargetCoord(SearchCellCoord, EndCoord))
		{
			FIntVector RouteCellCoord = EndCoord;
			
			TArray<FIntVector> Path;
			Path.Add(RouteCellCoord);
			while (PathfindCells[RouteCellCoord].FromCell != FIntVector(INT_MIN, INT_MIN, INT_MIN))
			{
				RouteCellCoord = PathfindCells[RouteCellCoord].FromCell;
				Path.Add(RouteCellCoord);
			}
			Algo::Reverse(Path);
			return Path;
		}
		
		OpenCellCoords.Remove(SearchCellCoord);
		ClosedCellCoords.Add(SearchCellCoord);
		
		TArray<FIntVector> NeighborCellCoords = GetNeighborCellCoords(SearchCellCoord, bIsDiagonal);
		for (int i = 0; i < NeighborCellCoords.Num(); i++)
		{
			if (ClosedCellCoords.Contains(NeighborCellCoords[i])) continue;
			
			FGridCellPathfindData NewCellPathfindData = FGridCellPathfindData();
			NewCellPathfindData.CellCoord = NeighborCellCoords[i];
			NewCellPathfindData.FromCell = SearchCellCoord;
			NewCellPathfindData.GCost = PathfindCells[SearchCellCoord].GCost + GridCells[NeighborCellCoords[i]].MovementCost;
			
			bool bIsNewCell = !OpenCellCoords.Contains(NeighborCellCoords[i]);
			if (bIsNewCell || NewCellPathfindData.GCost < PathfindCells[NeighborCellCoords[i]].GCost)
			{
				NewCellPathfindData.HCost = CalculateHCost(NeighborCellCoords[i], EndCoord, bIsDiagonal);NewCellPathfindData.FCost = NewCellPathfindData.GCost + NewCellPathfindData.HCost;
				PathfindCells.Add(NeighborCellCoords[i], NewCellPathfindData);
				if (!OpenCellCoords.Contains(NeighborCellCoords[i]))
				{
					OpenCellCoords.Add(NeighborCellCoords[i]);
				}
			}
		}
	}
	
	// No path found until OpenCellCoords become empty, which means there is no path to EndCoord(TargetCoord).
	return TArray<FIntVector>();
}

/**
 * Get Movable Range from certain point with Movement Point
 * @param StartCoord Starting Point
 * @param MovementPoint Movement Point (Each cell has its Movement Costs which consumes this point.)
 * @param bIsDiagonal Defines whether it is Euclidean Distance(Allow Diagonal Movement) or Manhattan Distance(Only Straight Movement).
 * @return Movable Range. Empty if no movable range found.
 */
TArray<FIntVector> UGridSubsystem::GetMovableRangeCellCoords(FIntVector StartCoord, int32 MovementPoint,
                                                             bool bIsDiagonal)
{
	TMap<FIntVector, FGridCellPathfindData> PathfindCells = TMap<FIntVector, FGridCellPathfindData>();
	TSet<FIntVector> OpenCellCoords = TSet<FIntVector>();
	TSet<FIntVector> ClosedCellCoords = TSet<FIntVector>();
	
	FIntVector SearchCellCoord = StartCoord;
	FGridCellPathfindData StartCellPathfindData = FGridCellPathfindData();
	StartCellPathfindData.CellCoord = SearchCellCoord;
	PathfindCells.Add(SearchCellCoord, StartCellPathfindData);
	OpenCellCoords.Add(SearchCellCoord);
	PathfindCells[StartCoord].GCost = 0;
	PathfindCells[StartCoord].FCost = PathfindCells[StartCoord].GCost;
	
	// Gather Neighboring Cells within MovementPoint
	while (!OpenCellCoords.IsEmpty())
	{
		SearchCellCoord = GetLowestFCostCellCoord(OpenCellCoords, PathfindCells);
		OpenCellCoords.Remove(SearchCellCoord);
		ClosedCellCoords.Add(SearchCellCoord);
		
		TArray<FIntVector> NeighborCellCoords = GetNeighborCellCoords(SearchCellCoord, bIsDiagonal);
		for (int i = 0; i < NeighborCellCoords.Num(); i++)
		{
			if (ClosedCellCoords.Contains(NeighborCellCoords[i])) continue;
			
			FGridCellPathfindData NewCellPathfindData = FGridCellPathfindData();
			NewCellPathfindData.CellCoord = NeighborCellCoords[i];
			NewCellPathfindData.FromCell = SearchCellCoord;
			NewCellPathfindData.GCost = PathfindCells[SearchCellCoord].GCost + GridCells[NeighborCellCoords[i]].MovementCost;
			NewCellPathfindData.FCost = NewCellPathfindData.GCost;
			
			// 기존 경로보다 나은 지 비교해서 GCost를 갱신해주어야 범위 내의 Cell들을 정확히 반환할 수 있음.
			bool bIsNewCell = !OpenCellCoords.Contains(NeighborCellCoords[i]);
			if (NewCellPathfindData.GCost <= MovementPoint &&
				(bIsNewCell || NewCellPathfindData.GCost < PathfindCells[NeighborCellCoords[i]].GCost))
			{
				PathfindCells.Add(NeighborCellCoords[i], NewCellPathfindData);
				if (!OpenCellCoords.Contains(NeighborCellCoords[i]))
				{
					OpenCellCoords.Add(NeighborCellCoords[i]);
				}
			}
		}
	}
	return ClosedCellCoords.Array();
}

/**
 * Get All Neighboring CellCoords of CellCoord. Neglects if Neighboring CellCoord does not exist or unreachable.
 * @param CellCoord CellCoord to find its neighbors.
 * @param bIsDiagonal Defines whether it is Euclidean Distance(Allow Diagonal Movement) or Manhattan Distance(Only Straight Movement).
 * @return 
 */
TArray<FIntVector> UGridSubsystem::GetNeighborCellCoords(FIntVector CellCoord, bool bIsDiagonal)
{
	TArray<FIntVector> NeighborCells;
	static const TArray<FIntVector> StraightNeighborCellCoords = 
	{
		FIntVector(1, 0, 0), FIntVector(0, 1, 0),
		FIntVector(-1, 0, 0), FIntVector(0, -1, 0)
	};
	
	for (int i = 0; i < StraightNeighborCellCoords.Num(); i++)
	{
		if (IsValidCell(CellCoord + StraightNeighborCellCoords[i]))
		{
			NeighborCells.Add(CellCoord + StraightNeighborCellCoords[i]);
		}
	}
	if (!bIsDiagonal) return NeighborCells;
	
	static const TArray<FIntVector> DiagonalNeighborCellCoords = 
	{
		FIntVector(1, 1, 0), FIntVector(1, -1, 0),
		FIntVector(-1, 1, 0), FIntVector(-1, -1, 0)
	};
	
	for (int i = 0; i < DiagonalNeighborCellCoords.Num(); i++)
	{
		if (IsValidCell(CellCoord + DiagonalNeighborCellCoords[i]))
		{
			NeighborCells.Add(CellCoord + DiagonalNeighborCellCoords[i]);
		}
	}
	return NeighborCells;
}

/**
 * Calculate cost of shortest path from CellCoord to TargetCoord. 
 * Neglects any kinds of obstacle, calculate only distance with basic cost(Straight = 10, Diagonal = 14).
 * @param CellCoord Starting Point
 * @param TargetCoord Target Point
 * @param bIsDiagonal Define whether it is Euclidean Distance(Allow Diagonal Movement) or Manhattan Distance(Only Straight Movement).
 * @return H(Heuristic) Cost of CellCoord to TargetCoord. 
 */
int32 UGridSubsystem::CalculateHCost(FIntVector CellCoord, FIntVector TargetCoord, bool bIsDiagonal)
{
	int HeuristicCost;
	
	// Euclidean Distance (Diagonal)
	if (bIsDiagonal)
	{
		const int32 DiagonalX = FMath::Abs(TargetCoord.X - CellCoord.X);
		const int32 DiagonalY = FMath::Abs(TargetCoord.Y - CellCoord.Y);
		const int32 DiagonalDistance = FMath::Min(DiagonalX, DiagonalY);
		const int32 StraightDistance = FMath::Max(DiagonalX, DiagonalY);
		
		HeuristicCost = DiagonalDistance * 14 + (StraightDistance - DiagonalDistance) * 10;
		return HeuristicCost;
	}
	
	// Manhattan Distance (Not Diagonal)
	const FIntVector MoveCost = TargetCoord - CellCoord;
	HeuristicCost = FMath::Abs(MoveCost.X * 10) + FMath::Abs(MoveCost.Y * 10);
	return HeuristicCost;
}

/**
 * Get CellCoord with Lowest F Cost from OpenCellCoords
 * @param OpenCellCoords CellCoords which are not searched yet
 * @param PathfindCells PathfindData of searched/searching CellCoords
 * @return CellCoord with Lowest F Cost in OpenCellCoords
 */
FIntVector UGridSubsystem::GetLowestFCostCellCoord(TSet<FIntVector>& OpenCellCoords, TMap<FIntVector, FGridCellPathfindData>& PathfindCells)
{
	int32 LowestCost = INT_MAX;
	FIntVector LowestCellCoord;
	
	for (FIntVector CellCoord : OpenCellCoords)
	{
		if (PathfindCells[CellCoord].FCost < LowestCost)
		{
			LowestCost = PathfindCells[CellCoord].FCost;
			LowestCellCoord = CellCoord;
		}
	}
	return LowestCellCoord;
}

/**
 * Check if CellCoord is TargetCoord
 * @param CellCoord CellCoord to check
 * @param TargetCoord TargetCoord
 * @return True if CellCoord is TargetCoord, otherwise false
 */
bool UGridSubsystem::IsTargetCoord(FIntVector CellCoord, FIntVector TargetCoord)
{
	if (CellCoord == TargetCoord) return true;                                                   
	else return false;
}

/**
 * Get Effect Range from certain point with Effect Distance
 * @param EffectRangeData Data for EffectRange. Setup depends on EffectRangeType.\n
 * Every EffectRangeType needs EffectOriginCellCoord.\n
 * 
 * Point -> No other Setups needed.\n
 * Line -> XLength, EffectRangeDirection\n
 * Square, Cross -> XLength, YLength, EffectRangeDirection\n
 * Star -> XLength\n
 * @return Effect Range.
 */
TArray<FIntVector> UGridSubsystem::GetEffectRangeCellCoords(FEffectRangeData& EffectRangeData)
{
	EEffectRangeType RangeType = EffectRangeData.EffectRangeType;
	switch (RangeType)
	{
		case EEffectRangeType::Point:
			{
				TArray<FIntVector> EffectRangeCellCoords;
				EffectRangeCellCoords.Add(EffectRangeData.EffectOriginCellCoord);
				return EffectRangeCellCoords;
			}
		case EEffectRangeType::Line:
			return GetLineEffectRange(EffectRangeData.EffectOriginCellCoord, 
				EffectRangeData.EffectXLength, EffectRangeData.EffectRangeDirection);
		case EEffectRangeType::Square:
			return GetSquareEffectRange(EffectRangeData.EffectOriginCellCoord, EffectRangeData.EffectXLength);
		case EEffectRangeType::Star:
			return GetStarEffectRange(EffectRangeData.EffectOriginCellCoord, EffectRangeData.EffectXLength);
		case EEffectRangeType::Cross:
			return GetCrossEffectRange(EffectRangeData.EffectOriginCellCoord, EffectRangeData.EffectXLength, false);
		default:
			UE_LOG(LogTemp, Warning, TEXT("Unknown EffectRangeType"));
			return TArray<FIntVector>();
	}
}

TArray<FIntVector> UGridSubsystem::GetLineEffectRange(FIntVector OriginCellCoord, int32 EffectDistance, EEffectRangeDirection EffectRangeDirection)
{
	TArray<FIntVector> EffectRangeCellCoords;
	
	const int32 CellDistance = FMath::Floor(EffectDistance / 2);
	FIntVector CellDirection = EffectRangeDirection == EEffectRangeDirection::Vertical ? 
		FIntVector(0, 1, 0) : FIntVector(1, 0, 0); 
	
	// 짝수일 때 양의 방향(오른쪽/위쪽)에 한 칸을 더 배정
	const int32 LowerOffset = -((EffectDistance - 1) / 2);
	const int32 UpperOffset = EffectDistance / 2;

	for (int32 i = LowerOffset; i <= UpperOffset; i++)
	{
		const FIntVector Coord = OriginCellCoord + CellDirection * i;
		if (IsValidCell(Coord))
		{
			EffectRangeCellCoords.Add(Coord);
		}
	}
	return EffectRangeCellCoords;
}

TArray<FIntVector> UGridSubsystem::GetSquareEffectRange(FIntVector OriginCellCoord, int32 EffectDistance)
{
	TArray<FIntVector> EffectRangeCellCoords;

	// 짝수일 때 양의 방향(오른쪽/위쪽)에 한 칸을 더 배정
	const int32 LowerOffset = -((EffectDistance - 1) / 2);
	const int32 UpperOffset = EffectDistance / 2;

	for (int32 x = LowerOffset; x <= UpperOffset; x++)
	{
		for (int32 y = LowerOffset; y <= UpperOffset; y++)
		{
			const FIntVector Coord = OriginCellCoord + FIntVector(x, y, 0);
			if (IsValidCell(Coord))
			{
				EffectRangeCellCoords.Add(Coord);
			}
		}
	}
	return EffectRangeCellCoords;
}

TArray<FIntVector> UGridSubsystem::GetDiamondEffectRange(FIntVector OriginCellCoord, int32 EffectDistance)
{
	TArray<FIntVector> EffectRangeCellCoords;

	for (int32 x = -EffectDistance; x <= EffectDistance; x++)
	{
		const int32 RemainingY = EffectDistance - FMath::Abs(x);
		for (int32 y = -RemainingY; y <= RemainingY; y++)
		{
			const FIntVector Coord = OriginCellCoord + FIntVector(x, y, 0);
			if (IsValidCell(Coord))
			{
				EffectRangeCellCoords.Add(Coord);
			}
		}
	}
	return EffectRangeCellCoords;
}

TArray<FIntVector> UGridSubsystem::GetStarEffectRange(FIntVector OriginCellCoord, int32 EffectDistance)
{
	TSet<FIntVector> UniqueCells;

	constexpr int32 NumPoints = 5;
	for (int32 p = 0; p < NumPoints; p++)
	{
		// 90도(위쪽)에서 시작해 72도씩 회전하며 5개 꼭짓점 방향 계산
		const float AngleDeg = 90.f + p * (360.f / NumPoints);
		const float AngleRad = FMath::DegreesToRadians(AngleDeg);

		const int32 EndX = FMath::RoundToInt(FMath::Cos(AngleRad) * EffectDistance);
		const int32 EndY = FMath::RoundToInt(FMath::Sin(AngleRad) * EffectDistance);
		const FIntVector EndCoord = OriginCellCoord + FIntVector(EndX, EndY, 0);

		// 원점 → 꼭짓점까지 브레젠험 직선으로 이어서 끊김 방지
		TArray<FIntVector> RayCells = GetBresenhamLine(OriginCellCoord, EndCoord);
		for (const FIntVector& Cell : RayCells)
		{
			if (IsValidCell(Cell))
			{
				UniqueCells.Add(Cell);
			}
		}
	}

	return UniqueCells.Array();
}

TArray<FIntVector> UGridSubsystem::GetCrossEffectRange(FIntVector OriginCellCoord, int32 EffectDistance, bool bIsDiagonalCross)
{
	TArray<FIntVector> EffectRangeCellCoords;

	if (IsValidCell(OriginCellCoord))
	{
		EffectRangeCellCoords.Add(OriginCellCoord);
	}

	const int32 ArmLength = EffectDistance - 1;
	if (ArmLength <= 0)
	{
		return EffectRangeCellCoords;
	}

	static const TArray<FIntVector> PlusDirections = {
		FIntVector(1, 0, 0),
		FIntVector(-1, 0, 0),
		FIntVector(0, 1, 0),
		FIntVector(0, -1, 0)
	};

	static const TArray<FIntVector> XDirections = {
		FIntVector(1, 1, 0),
		FIntVector(1, -1, 0),
		FIntVector(-1, 1, 0),
		FIntVector(-1, -1, 0)
	};

	const TArray<FIntVector>& Directions = bIsDiagonalCross ? XDirections : PlusDirections;
	for (const FIntVector& Direction : Directions)
	{
		for (int32 i = 1; i <= ArmLength; i++)
		{
			const FIntVector Coord = OriginCellCoord + Direction * i;
			if (IsValidCell(Coord))
			{
				EffectRangeCellCoords.Add(Coord);
			}
		}
	}
	return EffectRangeCellCoords;
}

TArray<FIntVector> UGridSubsystem::GetRandomEffectRange(FIntVector OriginCellCoord, int32 EffectDistance, int Count)
{
	TArray<FIntVector> CandidateCoords = GetSquareEffectRange(OriginCellCoord, EffectDistance);

	const int32 PickCount = FMath::Min(Count, CandidateCoords.Num());

	// Partial Fisher-Yates shuffle: 앞에서부터 PickCount개만 무작위로 확정
	for (int32 i = 0; i < PickCount; i++)
	{
		const int32 SwapIndex = FMath::RandRange(i, CandidateCoords.Num() - 1);
		CandidateCoords.Swap(i, SwapIndex);
	}

	TArray<FIntVector> EffectRangeCellCoords;
	EffectRangeCellCoords.Reserve(PickCount);
	for (int32 i = 0; i < PickCount; i++)
	{
		EffectRangeCellCoords.Add(CandidateCoords[i]);
	}

	return EffectRangeCellCoords;
}

// 브레젠험 직선 알고리즘 — Start와 End 사이를 끊김 없이 잇는 셀들을 반환
TArray<FIntVector> UGridSubsystem::GetBresenhamLine(FIntVector Start, FIntVector End)
{
	TArray<FIntVector> Line;

	int32 X0 = Start.X;
	int32 Y0 = Start.Y;
	const int32 X1 = End.X;
	const int32 Y1 = End.Y;

	const int32 DX = FMath::Abs(X1 - X0);
	const int32 DY = -FMath::Abs(Y1 - Y0);
	const int32 SX = X0 < X1 ? 1 : -1;
	const int32 SY = Y0 < Y1 ? 1 : -1;
	int32 Err = DX + DY;

	while (true)
	{
		Line.Add(FIntVector(X0, Y0, Start.Z));
		if (X0 == X1 && Y0 == Y1) break;

		const int32 E2 = 2 * Err;
		if (E2 >= DY) { Err += DY; X0 += SX; }
		if (E2 <= DX) { Err += DX; Y0 += SY; }
	}

	return Line;
}
#pragma endregion 
