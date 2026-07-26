// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridEnemySpawn.h"

AGridEnemySpawn::AGridEnemySpawn()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGridEnemySpawn::BeginPlay()
{
	Super::BeginPlay();
}

TArray<FIntVector> AGridEnemySpawn::GetAffectedCellCoords()
{
	return TArray<FIntVector>();
}

bool AGridEnemySpawn::Apply()
{
	return true;
}

