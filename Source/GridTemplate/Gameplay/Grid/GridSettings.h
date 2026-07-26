// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/Data/GridCellData.h"
#include "GridSettings.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnBuildGridCellData);

/**
 * Store GridCellData which is referenced when initializing Level.
 * This Actor MUST be placed on Level.
 */
UCLASS(Blueprintable)
class GRIDTEMPLATE_API AGridSettings : public AActor
{
	GENERATED_BODY()
	
public:	
	AGridSettings();

protected:
	virtual void BeginPlay() override;

public:
	/**
	 * Size of Each Cell on Grid.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	float CellSize = 100.f;

	/**
	 * Number of Cells on X Axis. (Standard X Axis, not Unreal X Axis)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridXLength = 20;

	/**
	 * Number of Cells on Y Axis. (Standard Y Axis, not Unreal Y Axis)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridYLength = 20;

	/**
	 * Grid Origin on Level.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	FVector GridOrigin = FVector(0, 0, 0);

	/**
	 * Actual Data of Grid Cells.
	 */
	UPROPERTY(BlueprintReadWrite, Category = "Grid", meta = (AllowPrivateAccess=true))
	TMap<FIntVector, FGridCellData> GridCells;

	/**
	 * Layer Setting of Grid. Key is Layer ID, Value is Z Offset of Each Layer.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	TMap<int32, float> LayerBaseHeights;

	/**
	 * MUST be called after Level Design is Changed. Build Grid Cell Data(GridCells).
	 */
	UFUNCTION(CallInEditor, Category = "Grid|Build", meta = (DisplayName = "Build Grid Cell Data"))
	void BuildGridCellData();
	
	UFUNCTION(Category= "Grid|Modifier")
	FORCEINLINE float GetCellSize() const { return CellSize; }
	
	UFUNCTION(Category= "Grid|Modifier")
	FORCEINLINE int32 GetGridXLength() const { return GridXLength; }
	
	UFUNCTION(Category= "Grid|Modifier")
	FORCEINLINE int32 GetGridYLength() const { return GridYLength; }
	
	UFUNCTION(Category= "Grid|Modifier")
	FORCEINLINE FVector GetGridOrigin() const { return GridOrigin; }
	
	UFUNCTION(Category = "Grid|Modifier")
	FORCEINLINE TMap<FIntVector, FGridCellData> GetGridCellData() { return GridCells; }
	
	UFUNCTION(Category = "Grid|Modifier")
	FORCEINLINE TMap<int32, float> GetLayerBaseHeights() { return LayerBaseHeights; }
	
	FOnBuildGridCellData OnBuildGridCellData;
};
