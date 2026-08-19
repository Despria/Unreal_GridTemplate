// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridContributorUnitSpawn.h"

AGridContributorUnitSpawn::AGridContributorUnitSpawn()
{
	PrimaryActorTick.bCanEverTick = false;
	GridContributorType = EGridContributorType::UnitSpawn;
}

void AGridContributorUnitSpawn::BeginPlay()
{
	Super::BeginPlay();
}

TArray<FIntVector> AGridContributorUnitSpawn::GetAffectedCellCoords()
{
	return Super::GetAffectedCellCoords();
}

bool AGridContributorUnitSpawn::Apply()
{
	return true;
}

