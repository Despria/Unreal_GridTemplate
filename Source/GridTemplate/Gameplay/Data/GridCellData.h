// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridCellData.generated.h"

USTRUCT(BlueprintType)
struct FGridCellData
{
	GENERATED_BODY();
	
	// X, Y, Z Coordinate of Cell
	UPROPERTY(BlueprintReadWrite)
	FIntVector CellGridCoord = FIntVector(0, 0, 0);
	
	// World Vector Location of Cell
	UPROPERTY(BlueprintReadWrite)
	FVector CellWorldLocation = FVector(0, 0, 0);
	
	UPROPERTY(BlueprintReadWrite)
	float HeightOffset = 0.f;
	
	// MovementCost Minimum = 10
	UPROPERTY(BlueprintReadWrite)
	int32 MovementCost = 10;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsWalkable = true;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsOccupied = false;
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FIntVector> ExtraMovableCells = TArray<FIntVector>();
};
