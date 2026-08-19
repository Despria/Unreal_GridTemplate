// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridCellData.h"
#include "Engine/DataAsset.h"
#include "GridCellBuildDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GRIDTEMPLATE_API UGridCellBuildDataAsset : public UDataAsset
{
	GENERATED_BODY()

	/**
	 * Access Available Only through AGridSettings
	 */
	friend class AGridSettings;
	
private:
	/**
	 * Size of Each Cell on Grid.
	 */
	UPROPERTY(VisibleAnywhere)
	float CellSize = 100.f;

	/**
	 * Number of Cells on X Axis. (Standard X Axis, not Unreal X Axis)
	 */
	UPROPERTY(VisibleAnywhere)
	int32 GridXLength = 20;

	/**
	 * Number of Cells on Y Axis. (Standard Y Axis, not Unreal Y Axis)
	 */
	UPROPERTY(VisibleAnywhere)
	int32 GridYLength = 20;

	/**
	 * Grid Origin on Level.
	 */
	UPROPERTY(VisibleAnywhere)
	FVector GridOrigin = FVector(0, 0, 0);

	/**
	 * Actual Data of Grid Cells.
	 */
	UPROPERTY(VisibleAnywhere)
	TMap<FIntVector, FGridCellData> GridCells;

	/**
	 * Layer Setting of Grid. Key is Layer ID, Value is Z Offset of Each Layer.
	 */
	UPROPERTY(VisibleAnywhere)
	TMap<int32, float> LayerBaseHeights;
};
