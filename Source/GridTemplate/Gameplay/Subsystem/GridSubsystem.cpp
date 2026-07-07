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

void UGridSubsystem::InitializeGrid_Implementation()
{
	
}

FIntVector UGridSubsystem::WorldLocationToCellCoord_Implementation(FVector WorldLocation) const
{
	// 월드 좌표를 그리드 좌표로 변환
	int32 CoordX= FMath::FloorToInt((WorldLocation.X - GridOrigin.X) / CellSize);
	int32 CoordY= FMath::FloorToInt((WorldLocation.Y - GridOrigin.Y) / CellSize);
	
	return FIntVector(CoordY, CoordX, ActiveLayer);
}

FVector UGridSubsystem::CellCenterAsWorldLocation_Implementation(FIntVector GridCoord) const
{
	// 그리드의 중심 좌표를 월드 좌표로 변환
	return FVector(0, 0, 0);
}

FVector UGridSubsystem::CellCoordToWorldLocation_Implementation(FIntVector GridCoord) const
{
	// 그리드 좌표를 월드 좌표로 변환
	return FVector(0, 0, 0);
}

bool UGridSubsystem::IsValidCell_Implementation(FIntVector GridCoord) const
{
	// 유효한 셀인지 반환
	TArray<FGridCellData> GridCoords;
	GridCells.GenerateValueArray(GridCoords);
	
	for (int i = 0; i < GridCoords.Num(); i++)
	{
		if (GridCoords[i].CellGridCoord == GridCoord) return true;
	}
	return false;
}

TArray<FIntVector> UGridSubsystem::GetAllCellCoords_Implementation() const
{
	TArray<FGridCellData> GridCoords;
	TArray<FIntVector> AllCellCoords;
	for (int i = 0; i < GridCoords.Num(); i++)
	{
		AllCellCoords.Add(GridCoords[i].CellGridCoord);
	}
	return AllCellCoords;
}

void UGridSubsystem::SetActiveLayer_Implementation(int32 NewLayer)
{
	ActiveLayer = NewLayer;
}

void UGridSubsystem::SetCellHeightOffset(FIntVector GridCoord, float NewHeightOffset)
{
	
}

FVector UGridSubsystem::CalculateWorldCenter(int32 X, int32 Y, int32 Layer, float HeightOffset) const
{
	return FVector(0, 0, 0);
}

bool UGridSubsystem::IsValidLayer(int32 Layer) const
{
	return true;
}
