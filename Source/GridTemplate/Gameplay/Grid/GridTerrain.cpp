// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridTerrain.h"

AGridTerrain::AGridTerrain()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGridTerrain::BeginPlay()
{
	Super::BeginPlay();
	
}

TArray<FIntVector> AGridTerrain::GetAffectedCellCoords()
{
	return TArray<FIntVector>();
}

bool AGridTerrain::Apply()
{
	return true;
}

