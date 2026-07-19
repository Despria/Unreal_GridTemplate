// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Subsystem/GridSubsystem.h"

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
	
	for (int i = 0; i < GridHeight; i++)
	{
		for (int j = 0; j < GridWidth; j++)
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

FIntVector UGridSubsystem::WorldLocationToCellCoord(FVector WorldLocation) const
{
	// 월드 좌표를 그리드 좌표로 변환
	// 언리얼의 좌표계는 Y축이 좌/우, X축이 앞/뒤를 가리키므로, 서로 변환해서 반환해야 함.
	int32 CoordX= FMath::FloorToInt((WorldLocation.Y - GridOrigin.Y) / CellSize);
	int32 CoordY= FMath::FloorToInt((WorldLocation.X - GridOrigin.X) / CellSize);
	
	return FIntVector(CoordX, CoordY, ActiveLayer);
}

FVector UGridSubsystem::CellCenterAsWorldLocation(FIntVector GridCoord) const
{
	// 그리드 좌표를 월드 좌표로 변환
	const float* BaseHeight = LayerBaseHeights.Find(GridCoord.Z);
	const float LayerZ = BaseHeight ? *BaseHeight : 0.f;

	return FVector(
		// 언리얼의 좌표계는 Y축이 좌/우, X축이 앞/뒤를 가리키므로, 서로 변환해서 반환해야 함.
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
	// 유효한 셀인지 반환
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
	
}

bool UGridSubsystem::IsValidLayer(int32 Layer) const
{
	return LayerBaseHeights.Find(Layer);
}
