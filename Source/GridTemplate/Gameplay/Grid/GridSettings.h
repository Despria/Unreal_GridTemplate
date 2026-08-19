// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/Data/GridCellBuildDataAsset.h"
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
	 * MUST be called after Level Design is Changed. Build Grid Cell Data(GridCells).
	 */
	UFUNCTION(CallInEditor, Category = "Grid|Build", 
		meta = (DisplayName = "Build Grid Cell Data", ToolTip="Must Call after Change Level Design"))
	void BuildGridCellData() const;
	
	UFUNCTION(CallInEditor, Category = "Grid|Build", meta = (DisplayName = "Dispose Grid Cell Data"))
	void DisposeGridCellData() const;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Build")
	float WalkableTraceDistance = 50.f;

	UFUNCTION(Category= "Grid|Modifier")
	FORCEINLINE float GetCellSize() const { return GridCellBuildDataAsset ? GridCellBuildDataAsset->CellSize : CellSize; }
	
	UFUNCTION(Category= "Grid|Modifier")
	FORCEINLINE int32 GetGridXLength() const { return GridCellBuildDataAsset ? GridCellBuildDataAsset->GridXLength : GridXLength; }
	
	UFUNCTION(Category= "Grid|Modifier")
	FORCEINLINE int32 GetGridYLength() const { return GridCellBuildDataAsset ? GridCellBuildDataAsset->GridYLength : GridYLength; }
	
	UFUNCTION(Category= "Grid|Modifier")
	FORCEINLINE FVector GetGridOrigin() const { return GridCellBuildDataAsset ? GridCellBuildDataAsset->GridOrigin : GridOrigin; }
	
	UFUNCTION(Category= "Grid|Modifier")
	FORCEINLINE TMap<FIntVector, FGridCellData> GetGridCellData() const
	{ return GridCellBuildDataAsset ? GridCellBuildDataAsset->GridCells : TMap<FIntVector, FGridCellData>(); }
	
	UFUNCTION(Category = "Grid|Modifier")
	FORCEINLINE TMap<int32, float> GetLayerBaseHeights() const 
	{ return GridCellBuildDataAsset ? GridCellBuildDataAsset->LayerBaseHeights : LayerBaseHeights; }
	
	FOnBuildGridCellData OnBuildGridCellData;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	TObjectPtr<UGridCellBuildDataAsset> GridCellBuildDataAsset;
	
	/**
	 * Size of Each Cell on Grid.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	float CellSize = 100.f;

	/**
	 * Number of Cells on X Axis. (Standard X Axis, not Unreal X Axis)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	int32 GridXLength = 20;

	/**
	 * Number of Cells on Y Axis. (Standard Y Axis, not Unreal Y Axis)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	int32 GridYLength = 20;

	/**
	 * Grid Origin on Level.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	FVector GridOrigin = FVector(0, 0, 0);

	/**
	 * Layer Setting of Grid. Key is Layer ID, Value is Z Offset of Each Layer.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	TMap<int32, float> LayerBaseHeights;
};
