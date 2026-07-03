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

FVector2D UGridSubsystem::WorldLocationToCellCoord_Implementation(FVector WorldLocation) const
{
	return FVector2D(0,0);
}

FVector UGridSubsystem::CellCoordToWorldLocation_Implementation(FVector2D GridCoord) const
{
	return FVector(0, 0, 0);
}

bool UGridSubsystem::IsValidCell_Implementation(FVector2D GridCoord) const
{
	return true;
}

TArray<FVector2D> UGridSubsystem::GetAllCellCoords_Implementation() const
{
	return TArray<FVector2D>();
}

void UGridSubsystem::SetActiveLayer_Implementation(int32 NewLayer)
{
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
