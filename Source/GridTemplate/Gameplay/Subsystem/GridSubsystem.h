// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Gameplay/Data/GridCellData.h"
#include "GridSubsystem.generated.h"

class AGridUnitBase;
class UGridInteractionComponent;

USTRUCT(BlueprintType)
struct FGridCellPathfindData
{
	GENERATED_BODY();
	
	UPROPERTY(BlueprintReadWrite)
	FIntVector CellCoord = FIntVector(INT_MIN, INT_MIN, INT_MIN);
	
	UPROPERTY(BlueprintReadWrite)
	int32 GCost = 0;
	
	UPROPERTY(BlueprintReadWrite)
	int32 HCost = 0;
	
	UPROPERTY(BlueprintReadWrite)
	int32 FCost = 0;
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FIntVector> NeighborCells = TArray<FIntVector>();
	
	UPROPERTY(BlueprintReadWrite)
	FIntVector FromCell = FIntVector(INT_MIN, INT_MIN, INT_MIN);
};

USTRUCT(BlueprintType)
struct FGridTraversalParams
{
	GENERATED_BODY()
	
	// 대각선 이동 허용 여부 (Euclidean vs Manhattan)
	UPROPERTY(BlueprintReadWrite)
	bool bIsDiagonal = false;
	
	// 통과 가능한 지형의 비트마스크. (1 << ETerrainType 값)의 OR 조합.
	// 기본값 1 = (1 << ETerrainType::Ground) → 기본 보행 지형만 통과 가능.
	// 새 지형(ETerrainType 값 추가) 대응 시 이 마스크에 명시적으로 비트를 추가해야만 통과 가능 (fail-closed).
	UPROPERTY(BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = "/Script/GridTemplate.ETerrainType"))
	int32 TraversableTerrainMask = 1 << static_cast<int32>(ETerrainType::Ground);
	
	// true면 bIsOccupied 셀을 통과(경유)할 수 있음. 단, 정지는 IsCellStoppable에서 항상 불가 처리됨.
	UPROPERTY(BlueprintReadWrite)
	bool bCanPassOccupied = false;
};

UENUM(Blueprintable)
enum class EEffectRangeType : uint8
{
	Point = 0,
	Line = 1,
	Square = 2,
	Diamond = 3,
	Star = 4,
	Cross = 5,
	Random = 6
};

UENUM(Blueprintable)
enum class EEffectRangeDirection : uint8
{
	Vertical = 0,
	Horizontal = 1
};

USTRUCT(BlueprintType)
struct FEffectRangeData
{
	GENERATED_BODY();
	
	UPROPERTY(BlueprintReadWrite)
	EEffectRangeType EffectRangeType = EEffectRangeType::Point;
	
	UPROPERTY(BlueprintReadWrite)
	EEffectRangeDirection EffectRangeDirection = EEffectRangeDirection::Vertical;
	
	UPROPERTY(BlueprintReadWrite)
	FIntVector EffectOriginCellCoord = FIntVector(0, 0, 0);
	
	UPROPERTY(BlueprintReadWrite)
	int32 EffectXLength = 1;
	
	UPROPERTY(BlueprintReadWrite)
	int32 EffectYLength = 1;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsDiagonal = false;
	
	UPROPERTY(BlueprintReadWrite)
	int32 RandomCount = 1;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInitializedGrid);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveableRangeUpdated, const TArray<FIntVector>&, Cells);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEffectRangeUpdated, const TArray<FIntVector>&, Cells);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPathUpdated, const TArray<FIntVector>&, Cells);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveLayerChanged, int32, NewLayer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelectionCleared);

/**
 * Grid Subsystem which manages logical grid and calculations about grid which depends on runtime, e.g., A* Pathfinding.
 */
UCLASS(Blueprintable, Abstract)
class GRIDTEMPLATE_API UGridSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void InitializeGrid();
	
	bool bIsGridInitialized = false;

#pragma region Cell Properties

	#pragma region Cell Properties From GridSettings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	float CellSize = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridXLength = 20;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 GridYLength = 20;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	FVector GridOrigin = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	TMap<int32, float> LayerBaseHeights = TMap<int32, float>{};
	#pragma endregion 
	
	UPROPERTY(BlueprintReadWrite, Category = "Grid")
	int32 ActiveLayer = 0;
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE float GetCellSize() { return CellSize; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE int32 GetGridWidth() { return GridXLength; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE int32 GetGridHeight() { return GridYLength; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE FVector GetGridOrigin() { return GridOrigin; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE int32 GetActiveLayer() { return ActiveLayer; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE TMap<int32, float> GetLayerBaseHeights() { return LayerBaseHeights; };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE int32 GetGridCellCoords(TArray<FIntVector>& CellCoords) { return GridCells.GetKeys(CellCoords); };
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	bool IsValidCell(FIntVector GridCoord) const;
	
	UFUNCTION(BlueprintCallable, Category = "Grid")
	TArray<FIntVector> GetAllCellCoords() const;
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Layers")
	void SetActiveLayer(int32 NewLayer);
	
private:
	UPROPERTY(BlueprintReadWrite, Category = "Grid", meta = (AllowPrivateAccess=true))
	TMap<FIntVector, FGridCellData> GridCells;
	
	bool IsValidLayer(int32 Layer) const;
#pragma endregion 	
	
#pragma region A* Pathfinding
public:
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding")
	TArray<FIntVector> GetAlphaStarPathToTargetCoord(FIntVector StartCoord, FIntVector TargetCoord, const FGridTraversalParams& TraversalParams);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding|MoveRange")
	TArray<FIntVector> GetMovableRangeCellCoords(FIntVector StartCoord, int32 MovementPoint, const FGridTraversalParams& TraversalParams);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding|EffectRange")
	TArray<FIntVector> GetEffectRangeCellCoords(FEffectRangeData& EffectRangeData);
	
private:
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding", meta=(AllowPrivateAccess=true))
	TMap<FIntVector, int32> GetReachableCellCoords(FIntVector CellCoord, const FGridTraversalParams& TraversalParams);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding", meta=(AllowPrivateAccess=true))
	bool IsCellTraversable(FIntVector CellCoord, const FGridTraversalParams& TraversalParams) const;
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding", meta=(AllowPrivateAccess=true))
	bool IsCellStoppable(FIntVector CellCoord, const FGridTraversalParams& TraversalParams) const;
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding", meta=(AllowPrivateAccess=true))
	int32 CalculateHCost(FIntVector CellCoord, FIntVector TargetCoord, bool bIsDiagonal);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding", meta=(AllowPrivateAccess=true))
	FIntVector GetLowestFCostCellCoord(TSet<FIntVector>& OpenCellCoords, TMap<FIntVector, FGridCellPathfindData>& PathfindCells);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding", meta=(AllowPrivateAccess=true))
	bool IsTargetCoord(FIntVector CellCoord, FIntVector TargetCoord);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding|EffectRange", meta=(AllowPrivateAccess=true))
	TArray<FIntVector> GetLineEffectRange(FIntVector OriginCellCoord, int32 EffectDistance, EEffectRangeDirection EffectRangeDirection);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding|EffectRange", meta=(AllowPrivateAccess=true))
	TArray<FIntVector> GetSquareEffectRange(FIntVector OriginCellCoord, int32 EffectXDistance);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding|EffectRange", meta=(AllowPrivateAccess=true))
	TArray<FIntVector> GetDiamondEffectRange(FIntVector OriginCellCoord, int32 EffectDistance);

	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding|EffectRange", meta=(AllowPrivateAccess=true))
	TArray<FIntVector> GetStarEffectRange(FIntVector OriginCellCoord, int32 EffectDistance);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding|EffectRange", meta=(AllowPrivateAccess=true))
	TArray<FIntVector> GetCrossEffectRange(FIntVector OriginCellCoord, int32 EffectDistance, bool bIsDiagonalCross);
	
	UFUNCTION(BlueprintCallable, Category = "Grid|Pathfinding|EffectRange", meta=(AllowPrivateAccess=true))
	TArray<FIntVector> GetRandomEffectRange(FIntVector OriginCellCoord, int32 EffectDistance, int Count);
	
	TArray<FIntVector> GetBresenhamLine(FIntVector Start, FIntVector End);
#pragma endregion
	
#pragma region Unit Selection / Movement Input
	// GridInteractionComponent의 클릭 이벤트를 구독하여, "유닛 선택 → 이동 범위 표시 → 범위 내 셀 클릭 시 이동"
	// 흐름을 처리함. 입력 레이어(GridInteractionComponent)는 "무엇이 클릭됐는가"만 알리고,
	// 실제 게임 규칙 판단(선택 상태, 이동 가능 여부)은 여기(로직 레이어)에서 담당.
private:
	// OnWorldBeginPlay에서 호출. 이 시점엔 PlayerController/GridInteractionComponent의 BeginPlay가
	// 이미 끝난 상태이므로 안전하게 FindComponentByClass 가능.
	void BindInteractionEvents();
	void UnbindInteractionEvents();
 
	// 유닛 클릭 시: 선택 + 이동 가능 범위 계산 및 브로드캐스트
	UFUNCTION()
	void HandleUnitClicked(AActor* HitActor);
 
	// 셀 클릭 시: 선택된 유닛이 있고 클릭한 셀이 이동 범위 내라면 경로 계산 후 이동 명령.
	// 범위 밖 클릭 시 선택 해제.
	UFUNCTION()
	void HandleCellClicked(FIntVector CellCoord);
 
	void ClearSelection();
 
	UPROPERTY()
	TArray<TObjectPtr<AGridUnitBase>> CurrentUnits;
	
	UPROPERTY()
	TObjectPtr<AGridUnitBase> SelectedUnit;
 
	UPROPERTY()
	TObjectPtr<UGridInteractionComponent> GridInteractionComponent;
 
	TArray<FIntVector> CurrentMovableRangeCells;
#pragma endregion	
	
#pragma region Delegates (Event Dispatchers)
public:
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnMoveableRangeUpdated OnMoveableRangeUpdated;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnEffectRangeUpdated OnAttackRangeUpdated;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnPathUpdated OnPathUpdated;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnSelectionCleared OnSelectionCleared;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnActiveLayerChanged OnActiveLayerChanged;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Grid")
	FOnInitializedGrid OnInitializedGrid;
#pragma endregion 
};
