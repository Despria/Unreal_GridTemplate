// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GridMath.generated.h"

/**
 * Simple Calculations about grid
 */
UCLASS()
class GRIDTEMPLATE_API UGridMath : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Grid|Cell")
	static FVector CellCoordToWorldLocation(FIntVector CellCoord, FVector GridOrigin, float CellSize, TMap<int32, float> LayerBaseHeights);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Cell")
	static FVector CellCenterToWorldLocation(FIntVector CellCoord, FVector GridOrigin, float CellSize, TMap<int32, float> LayerBaseHeights);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Cell")
	static FIntVector WorldLocationToCellCoord(FVector WorldLocation, FVector GridOrigin, float CellSize, int32 ActiveLayer);
};
