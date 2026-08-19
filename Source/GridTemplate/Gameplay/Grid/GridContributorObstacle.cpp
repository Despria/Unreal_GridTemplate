// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridContributorObstacle.h"

AGridContributorObstacle::AGridContributorObstacle()
{
	PrimaryActorTick.bCanEverTick = false;
	GridContributorType = EGridContributorType::Obstacle;
}

void AGridContributorObstacle::BeginPlay()
{
	Super::BeginPlay();
}

TArray<FIntVector> AGridContributorObstacle::GetAffectedCellCoords()
{
	return Super::GetAffectedCellCoords();
}

bool AGridContributorObstacle::Apply()
{
	return true;
}
