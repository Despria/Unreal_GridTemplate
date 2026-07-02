// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Subsystem/GridSubsystem.h"

void UGridSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UGridSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UGridSubsystem::InitializeGrid_Implementation()
{
	
}

FVector2D UGridSubsystem::WorldToGrid_Implementation(FVector WorldLocation) const
{
	return FVector2D(0,0);
}

FVector UGridSubsystem::GridToWorldCenter_Implementation(FVector2D GridCoord) const
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
