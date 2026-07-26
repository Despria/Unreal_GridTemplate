// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridObstacle.h"

AGridObstacle::AGridObstacle()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGridObstacle::BeginPlay()
{
	Super::BeginPlay();
}

TArray<FIntVector> AGridObstacle::GetAffectedCellCoords()
{
	return TArray<FIntVector>();
}

bool AGridObstacle::Apply()
{
	return true;
}
