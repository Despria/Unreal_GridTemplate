// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GridSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FGridCellData
{
	GENERATED_BODY();
	
	// 셀의 그리드 상에서의 좌표 (X, Y, Z)
	UPROPERTY(BlueprintReadWrite)
	FIntVector CellGridCoord = FIntVector(0, 0, 0);
	
	// 셀 좌표 위치의 월드 상에서의 좌표
	UPROPERTY(BlueprintReadWrite)
	FVector CellWorldLocation = FVector(0, 0, 0);
	
	UPROPERTY(BlueprintReadWrite)
	float HeightOffset = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	int32 MovementCost = 1;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsWalkable = true;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsOccupied = false;
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FIntVector> ExtraMovableCells = TArray<FIntVector>();
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveableRangeUpdated, const TArray<FVector2D>&, Cells);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttackRangeUpdated, const TArray<FVector2D>&, Cells);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPathUpdated, const TArray<FVector2D>&, Cells);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveLayerChanged, int32, NewLayer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelectionCleared);

// 새로 추가한 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInitializedGrid);

/// GridSubsystem은 레벨, 데이터 에셋 등으로 존재할 그리드 관련 데이터를 통해, 
/// 플레이 중인 레벨에 대한 논리적 그리드 데이터를 생성/저장/관리하며,
/// A* 알고리즘을 통한 경로 계산 등을 담당하기 위한 클래스임.
/// InitializeGrid()를 통해 논리적 그리드 데이터를 초기화하고, 초기화 완료 시 FOnInitializeGrid를 발행하여 그리드 데이터 생성을 알림.
/// 이 데이터는 GridVisualizer와 같은 액터에서 사용하게 됨.

/**
 * Grid Subsystem which manages Logical Grid and calculations about grid, e.c, A* Pathfinding.
 */
UCLASS(Blueprintable, Abstract)
class GRIDTEMPLATE_API UGridSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void Deinitialize() override;
	
	// 셀 한 칸의 크기 (정사각형)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	float CellSize = 100.f;
	
	// 그리드 내에서의 셀의 개수 (가로)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridWidth = 20;
	// 그리드 내에서의 셀의 개수 (세로)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridHeight = 20;
	
	// 그리드의 셀 생성 시작점
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	FVector GridOrigin = FVector(0, 0, 0);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	TMap<int32, float> LayerBaseHeights;
	
	UPROPERTY(BlueprintReadWrite, Category = "Grid")
	int32 ActiveLayer = 0;
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void InitializeGrid();
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE float GetCellSize() { return CellSize; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE int32 GetGridWidth() { return GridWidth; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE int32 GetGridHeight() { return GridHeight; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE FVector GetGridOrigin() { return GridOrigin; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE int32 GetActiveLayer() { return ActiveLayer; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE int32 GetGridCellCoords(TArray<FIntVector>& CellCoords) { return GridCells.GetKeys(CellCoords); };
	
	// 셀의 그리드 상에서의 좌표를 월드 좌표로 변환
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FVector CellCoordToWorldLocation(FIntVector GridCoord) const;
	
	// 월드 좌표를 셀의 그리드 상에서의 좌표로 변환
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FIntVector WorldLocationToCellCoord(FVector WorldLocation) const;
	
	// 특정 셀의 중심 좌표를 반환
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FVector CellCenterAsWorldLocation(FIntVector GridCoord) const;
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	bool IsValidCell(FIntVector GridCoord) const;
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	TArray<FIntVector> GetAllCellCoords() const;
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Layers")
	void SetActiveLayer(int32 NewLayer);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Layers")
	void SetCellHeightOffset(FIntVector GridCoord, float NewHeightOffset);
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnMoveableRangeUpdated OnMoveableRangeUpdated;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnAttackRangeUpdated OnAttackRangeUpdated;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnPathUpdated OnPathUpdated;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnSelectionCleared OnSelectionCleared;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnActiveLayerChanged OnActiveLayerChanged;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnInitializedGrid OnInitializedGrid;
	
private:
	UPROPERTY(BlueprintReadWrite, Category = "Grid", meta = (AllowPrivateAccess=true))
	TMap<FIntVector, FGridCellData> GridCells;
	
	bool IsValidLayer(int32 Layer) const;
};
