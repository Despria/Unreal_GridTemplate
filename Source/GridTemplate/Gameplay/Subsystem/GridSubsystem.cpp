// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/Subsystem/GridSubsystem.h"
#include "Gameplay/Grid/GridSettings.h"
#include "Algo/Reverse.h"
#include "Kismet/GameplayStatics.h"

void UGridSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	InitializeGrid();
}

void UGridSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UGridSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UGridSubsystem::InitializeGrid()
{
	if (AActor* Actor = UGameplayStatics::GetActorOfClass(GetWorld(), AGridSettings::StaticClass()))
	{
		AGridSettings* GridSettings = Cast<AGridSettings>(Actor);
		CellSize = GridSettings->GetCellSize();
		GridXLength = GridSettings->GetGridXLength();
		GridYLength = GridSettings->GetGridYLength();
		GridOrigin = GridSettings->GetGridOrigin();
		GridCells = GridSettings->GetGridCellData();
		if (GridCells.IsEmpty())
		{
			UE_LOG(LogTemp, Error, TEXT("UGridSubsystem::GridCells is Not Properly Initiailized!!"));
		}
		LayerBaseHeights = GridSettings->GetLayerBaseHeights();
		
		UE_LOG(LogTemp, Warning, TEXT("GridCells Length: %d"), GridCells.Num());
		
		OnInitializedGrid.Broadcast();
		bIsGridInitialized = true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UGridSubsystem::GridSetting Not FOUND!!"));
	}
}

#pragma region Cell Properties
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

bool UGridSubsystem::IsValidLayer(int32 Layer) const
{
	return LayerBaseHeights.Find(Layer);
}
#pragma endregion 

#pragma region A* Pathfinding
/**
 * Find Path(FIntVector Array) From StartCoord to EndCoord.
 * @param StartCoord Starting Point
 * @param TargetCoord Target Point
 * @param bIsDiagonal Defines whether it is Euclidean Distance(Allow Diagonal Movement) or Manhattan Distance(Only Straight Movement).
 * @return Path from StartCoord to EndCoord. Empty TArray if no Path found.
 */
TArray<FIntVector> UGridSubsystem::GetAlphaStarPathToTargetCoord(FIntVector StartCoord, FIntVector TargetCoord, const FGridTraversalParams& TraversalParams)
{
	// If TargetCoord is Unstoppable, No need to find Path
	if (!IsCellStoppable(TargetCoord, TraversalParams))
	{
		return TArray<FIntVector>();
	}
	
	TMap<FIntVector, FGridCellPathfindData> PathfindCells = TMap<FIntVector, FGridCellPathfindData>();
	TSet<FIntVector> OpenCellCoords = TSet<FIntVector>();
	TSet<FIntVector> ClosedCellCoords = TSet<FIntVector>();
	
	FIntVector SearchCellCoord = StartCoord;
	FGridCellPathfindData StartCellPathfindData = FGridCellPathfindData();
	StartCellPathfindData.CellCoord = SearchCellCoord;
	PathfindCells.Add(SearchCellCoord, StartCellPathfindData);
	OpenCellCoords.Add(SearchCellCoord);
	
	PathfindCells[StartCoord].GCost = 0;
	PathfindCells[StartCoord].HCost = CalculateHCost(SearchCellCoord, TargetCoord, TraversalParams.bIsDiagonal);
	PathfindCells[StartCoord].FCost = PathfindCells[SearchCellCoord].GCost + PathfindCells[SearchCellCoord].HCost;
	
	while (!OpenCellCoords.IsEmpty())
	{
		SearchCellCoord = GetLowestFCostCellCoord(OpenCellCoords, PathfindCells);
		if (IsTargetCoord(SearchCellCoord, TargetCoord))
		{
			FIntVector RouteCellCoord = TargetCoord;
			
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
		
		TMap<FIntVector, int32> NeighborCellCoords = GetReachableCellCoords(SearchCellCoord, TraversalParams);
		for (const TPair<FIntVector, int32>& Neighbor : NeighborCellCoords)
		{
			if (ClosedCellCoords.Contains(Neighbor.Key)) continue;
			
			FGridCellPathfindData NewCellPathfindData = FGridCellPathfindData();
			NewCellPathfindData.CellCoord = Neighbor.Key;
			NewCellPathfindData.FromCell = SearchCellCoord;
			NewCellPathfindData.GCost = PathfindCells[SearchCellCoord].GCost + Neighbor.Value;
			
			bool bIsNewCell = !OpenCellCoords.Contains(Neighbor.Key);
			if (bIsNewCell || NewCellPathfindData.GCost < PathfindCells[Neighbor.Key].GCost)
			{
				NewCellPathfindData.HCost = CalculateHCost(Neighbor.Key, TargetCoord, TraversalParams.bIsDiagonal);
				NewCellPathfindData.FCost = NewCellPathfindData.GCost + NewCellPathfindData.HCost;
				PathfindCells.Add(Neighbor.Key, NewCellPathfindData);
				if (!OpenCellCoords.Contains(Neighbor.Key))
				{
					OpenCellCoords.Add(Neighbor.Key);
				}
			}
		}
	}
	
	// No path found until OpenCellCoords become empty, which means there is no path to TargetCoord.
	return TArray<FIntVector>();
}

/**
 * Get Movable Range from certain point with Movement Point
 * @param StartCoord Starting Point
 * @param MovementPoint Movement Point (Each cell has its Movement Costs which consumes this point.)
 * @param bIsDiagonal Defines whether it is Euclidean Distance(Allow Diagonal Movement) or Manhattan Distance(Only Straight Movement).
 * @return Movable Range. Empty if no movable range found.
 */
TArray<FIntVector> UGridSubsystem::GetMovableRangeCellCoords(FIntVector StartCoord, int32 MovementPoint, const FGridTraversalParams& TraversalParams)
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
		
		TMap<FIntVector, int32> NeighborCellCoords = GetReachableCellCoords(SearchCellCoord, TraversalParams);
		for (const TPair<FIntVector, int32>& Neighbor : NeighborCellCoords)
		{
			if (ClosedCellCoords.Contains(Neighbor.Key)) continue;
    
			FGridCellPathfindData NewCellPathfindData = FGridCellPathfindData();
			NewCellPathfindData.CellCoord = Neighbor.Key;
			NewCellPathfindData.FromCell = SearchCellCoord;
			NewCellPathfindData.GCost = PathfindCells[SearchCellCoord].GCost + Neighbor.Value;  // ← 동일하게 변경
			NewCellPathfindData.FCost = NewCellPathfindData.GCost;
    
			bool bIsNewCell = !OpenCellCoords.Contains(Neighbor.Key);
			if (NewCellPathfindData.GCost <= MovementPoint &&
				(bIsNewCell || NewCellPathfindData.GCost < PathfindCells[Neighbor.Key].GCost))
			{
				PathfindCells.Add(Neighbor.Key, NewCellPathfindData);
				if (!OpenCellCoords.Contains(Neighbor.Key))
				{
					OpenCellCoords.Add(Neighbor.Key);
				}
			}
		}
	}
	
	// 반환 직전: 정지 가능한 칸만 필터링. StartCoord(유닛 본인 위치)는 예외적으로 항상 포함.
	TArray<FIntVector> StoppableCells;
	for (const FIntVector& Cell : ClosedCellCoords)
	{
		if (Cell == StartCoord || IsCellStoppable(Cell, TraversalParams))
		{
			StoppableCells.Add(Cell);
		}
	}
	return StoppableCells;
}

/**
 * Get All Neighboring CellCoords of CellCoord. Neglects if Neighboring CellCoord does not exist or unreachable.
 * @param CellCoord CellCoord to find its neighbors.
 * @param bIsDiagonal Defines whether it is Euclidean Distance(Allow Diagonal Movement) or Manhattan Distance(Only Straight Movement).
 * @return 
 */
TMap<FIntVector, int32> UGridSubsystem::GetReachableCellCoords(FIntVector CellCoord, const FGridTraversalParams& TraversalParams)
{
	TMap<FIntVector, int32> NeighborCells;
	
	// 1. ExtraMovableCells
	for (const TPair<FIntVector, int32>& ExtraMovable : GridCells[CellCoord].ExtraMovableCells)
	{
		if (IsCellTraversable(ExtraMovable.Key, TraversalParams))
		{
			NeighborCells.Add(ExtraMovable.Key, ExtraMovable.Value);
		}
	}
	
	// 2. Get NeighborCells
	static const TArray<FIntVector> StraightNeighborCellCoords = 
	{
		FIntVector(1, 0, 0), FIntVector(0, 1, 0),
		FIntVector(-1, 0, 0), FIntVector(0, -1, 0)
	};
	for (int i = 0; i < StraightNeighborCellCoords.Num(); i++)
	{
		const FIntVector Neighbor = CellCoord + StraightNeighborCellCoords[i];
		if (IsCellTraversable(Neighbor, TraversalParams))
		{
			NeighborCells.Add(Neighbor, GridCells[Neighbor].MovementCost);
		}
	}
	
	// NeighborCell (Diagonal)
	if (TraversalParams.bIsDiagonal)
	{
		static const TArray<FIntVector> DiagonalNeighborCellCoords = 
		{
			FIntVector(1, 1, 0), FIntVector(1, -1, 0),
			FIntVector(-1, 1, 0), FIntVector(-1, -1, 0)
		};
		for (int i = 0; i < DiagonalNeighborCellCoords.Num(); i++)
		{
			const FIntVector Neighbor = CellCoord + DiagonalNeighborCellCoords[i];
			if (IsCellTraversable(Neighbor, TraversalParams))
			{
				NeighborCells.Add(Neighbor, GridCells[Neighbor].MovementCost);
			}
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
 * 
 * @param CellCoord 
 * @param TraversalParams 
 * @return 
 */
bool UGridSubsystem::IsCellTraversable(FIntVector CellCoord, const FGridTraversalParams& TraversalParams) const
{
	if (!IsValidCell(CellCoord)) return false;
	
	const FGridCellData& CellData = GridCells[CellCoord];
	
	if (!CellData.bIsWalkable) return false;
	
	const int32 CellTerrainBit = 1 << static_cast<int32>(CellData.TerrainType);
	if ((TraversalParams.TraversableTerrainMask & CellTerrainBit) == 0) return false;
	
	if (CellData.bIsOccupied && !TraversalParams.bCanPassOccupied) return false;
	
	return true;
}

/**
 * Find if CellCoord is Stoppable. Even if Unit can pass through occupied Cell, it cannot Stop on occupied Cell.
 * @param CellCoord 
 * @param TraversalParams 
 * @return 
 */
bool UGridSubsystem::IsCellStoppable(FIntVector CellCoord, const FGridTraversalParams& TraversalParams) const
{
	if (!IsCellTraversable(CellCoord, TraversalParams)) return false;
	if (GridCells[CellCoord].bIsOccupied) return false;
    
	return true;
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
		// Cross, Random은 현재 매개변수 하나가 하드코딩 되어 있어 수정 작업 필요.
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
		case EEffectRangeType::Diamond:
			return GetDiamondEffectRange(EffectRangeData.EffectOriginCellCoord, EffectRangeData.EffectXLength);
		case EEffectRangeType::Star:
			return GetStarEffectRange(EffectRangeData.EffectOriginCellCoord, EffectRangeData.EffectXLength);
		case EEffectRangeType::Cross:
			return GetCrossEffectRange(EffectRangeData.EffectOriginCellCoord, EffectRangeData.EffectXLength, false);
		case EEffectRangeType::Random:
			return GetRandomEffectRange(EffectRangeData.EffectOriginCellCoord, EffectRangeData.EffectXLength, 10);
		default:
			UE_LOG(LogTemp, Warning, TEXT("Unknown EffectRangeType"));
			return TArray<FIntVector>();
	}
}

TArray<FIntVector> UGridSubsystem::GetLineEffectRange(FIntVector OriginCellCoord, int32 EffectDistance, EEffectRangeDirection EffectRangeDirection)
{
	TArray<FIntVector> EffectRangeCellCoords;
	
	// 짝수일 때 양의 방향(오른쪽/위쪽)에 한 칸을 더 배정
	const int32 LowerOffset = -((EffectDistance - 1) / 2);
	const int32 UpperOffset = EffectDistance / 2;
	FIntVector CellDirection = EffectRangeDirection == EEffectRangeDirection::Vertical ? 
		FIntVector(0, 1, 0) : FIntVector(1, 0, 0); 
	
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
