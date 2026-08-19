// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridUnitBase.h"

#include "AITypes.h"
#include "GridMath.h"
#include "Gameplay/Subsystem/GridSubsystem.h"

AGridUnitBase::AGridUnitBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGridUnitBase::BeginPlay()
{
	Super::BeginPlay();
	InitializeUnit();
}

void AGridUnitBase::InitializeUnit()
{
	if (!UnitBaseStatDataAsset)
	{
		UE_LOG(LogTemp, Error, TEXT("GridUnitBase::UnitBaseStatDataAsset IS NULL!!"))
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("GridUnitBaseStatDataAsset IS NULL!!"));
		Destroy();
	}
	UnitBaseStatData.InitializeFromBaseStat(UnitBaseStatDataAsset);
}

FIntVector AGridUnitBase::GetCellCoord() const
{
	UGridSubsystem* GridSubsystem = GetWorld()->GetSubsystem<UGridSubsystem>();
	return UGridMath::WorldLocationToCellCoord(
		GetActorLocation(), GridSubsystem->GetGridOrigin(), GridSubsystem->GetCellSize(), GridSubsystem->GetActiveLayer());
}

int32 AGridUnitBase::GetMovementPoints() const
{
	return UnitBaseStatData.MovementPoint;
}

bool AGridUnitBase::IsDiagonalMovable() const
{
	return UnitBaseStatData.bIsDiagonal;
}

bool AGridUnitBase::IsInteractable() const
{
	return bIsInteractable;
}


