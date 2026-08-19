// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridContributorTerrain.h"

AGridContributorTerrain::AGridContributorTerrain()
{
	PrimaryActorTick.bCanEverTick = false;
	GridContributorType = EGridContributorType::Terrain;
}

void AGridContributorTerrain::BeginPlay()
{
	Super::BeginPlay();
}

TArray<FIntVector> AGridContributorTerrain::GetAffectedCellCoords()
{
	return Super::GetAffectedCellCoords();
}

bool AGridContributorTerrain::Apply()
{
	return true;
}

