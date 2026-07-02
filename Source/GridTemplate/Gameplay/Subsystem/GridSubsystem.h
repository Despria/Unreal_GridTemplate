// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GridSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FGridCellData
{
	GENERATED_BODY();
	
	UPROPERTY(BlueprintReadWrite)
	FVector2D GridCoord = FVector2D(0, 0);
	
	UPROPERTY(BlueprintReadWrite)
	FVector WorldCenter = FVector(0, 0, 0);
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsWalkable;
	
	UPROPERTY(BlueprintReadWrite)
	float Height = 0.f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveableRangeUpdated, const TArray<FVector2D>&, Cells);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttackRangeUpdated, const TArray<FVector2D>&, Cells);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPathUpdated, const TArray<FVector2D>&, Cells);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelectionCleared);

/**
 * Grid Subsystem which manages Logical Grid and calculations about grid, ex) A* Pathfinding.
 */
UCLASS()
class GRIDTEMPLATE_API UGridSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	float CellSize = 100.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridWidth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridHeight;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	FVector GridOrigin = FVector(0, 0, 0);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid")
	void InitializeGrid();
	virtual void InitializeGrid_Implementation();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid")
	FVector GridToWorldCenter(FVector2D GridCoord) const;
	virtual FVector GridToWorldCenter_Implementation(FVector2D GridCoord) const;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid")
	FVector2D WorldToGrid(FVector WorldLocation) const;
	virtual FVector2D WorldToGrid_Implementation(FVector WorldLocation) const;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid")
	bool IsValidCell(FVector2D GridCoord) const;
	virtual bool IsValidCell_Implementation(FVector2D GridCoord) const;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid")
	TArray<FVector2D> GetAllCellCoords() const;
	virtual TArray<FVector2D> GetAllCellCoords_Implementation() const;
	
	UPROPERTY(BlueprintAssignable, Category = "Grid")
	FOnMoveableRangeUpdated OnMoveableRangeUpdated;
	
	UPROPERTY(BlueprintAssignable, Category = "Grid")
	FOnAttackRangeUpdated OnAttackRangeUpdated;
	
	UPROPERTY(BlueprintAssignable, Category = "Grid")
	FOnPathUpdated OnPathUpdated;
	
	UPROPERTY(BlueprintAssignable, Category = "Grid")
	FOnSelectionCleared OnSelectionCleared;
	
private:
	TMap<FVector2D, FGridCellData> GridData;
};
