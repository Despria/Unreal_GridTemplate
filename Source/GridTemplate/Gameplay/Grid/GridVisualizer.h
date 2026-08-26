// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/Subsystem/GridSubsystem.h"
#include "Gameplay/ActorComponent/GridInteractionComponent.h"
#include "Gameplay/Data/CellDisplayStateData.h"
#include "GridVisualizer.generated.h"

UCLASS()
class GRIDTEMPLATE_API AGridVisualizer : public AActor
{
	GENERATED_BODY()
    
public:
    AGridVisualizer();

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Setup")
    float CellSize = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Setup")
    int32 GridWidth = 20;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Setup")
    int32 GridHeight = 20;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Setup")
    FVector GridOrigin = FVector::ZeroVector;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid|Mesh")
    TObjectPtr<UStaticMeshComponent> GridMeshComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Mesh")
    TObjectPtr<UMaterialInterface> GridMaterial;

    // 각 셀의 상태를 표시할 ISM
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid|ISM")
    TObjectPtr<UInstancedStaticMeshComponent> ISM_CellDisplayState;

    // ISM에 사용할 셀 크기 평면 메쉬
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|ISM")
    TObjectPtr<UStaticMesh> CellMesh;

    // GridManager 델리게이트에 바인딩
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnInitializedGrid();
    virtual void OnInitializedGrid_Implementation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnShowMovableRangeHandler(const TArray<FIntVector>& Cells);
    virtual void OnShowMovableRangeHandler_Implementation(const TArray<FIntVector>& Cells);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnShowEffectRangeHandler(const TArray<FIntVector>& Cells);
    virtual void OnShowEffectRangeHandler_Implementation(const TArray<FIntVector>& Cells);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnShowPathHandler(const TArray<FIntVector>& Cells);
    virtual void OnShowPathHandler_Implementation(const TArray<FIntVector>& Cells);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnCellClickedHandler(FIntVector CellCoord);
    virtual void OnCellClickedHandler_Implementation(FIntVector CellCoord);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnCellClickExitedHandler(FIntVector CellCoord);
    virtual void OnCellClickExitedHandler_Implementation(FIntVector CellCoord);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnCellHoveredHandler(FIntVector CellCoord);
    virtual void OnCellHoveredHandler_Implementation(FIntVector CellCoord);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnCellHoverExitedHandler(FIntVector CellCoord);
    virtual void OnCellHoverExitedHandler_Implementation(FIntVector CellCoord);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnUnitClickedHandler(AActor* Unit);
    virtual void OnUnitClickedHandler_Implementation(AActor* Unit);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void HandleSelectionCleared();
    virtual void HandleSelectionCleared_Implementation();

    UFUNCTION(BlueprintCallable, Category = "Grid|Visual")
    void SetCellDisplayState(FIntVector CellCoord, ECellDisplayState NewState);
    
    UFUNCTION(BlueprintCallable, Category = "Grid|Visual")
    void RemoveCellDisplayState(FIntVector CellCoord, ECellDisplayState StateToRemove);

    // 레벨 전체에 표시할 그리드 초기화
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Mesh")
    void InitGridMesh();
    virtual void InitGridMesh_Implementation();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Mesh")
    void UpdateGridMaterial();
    virtual void UpdateGridMaterial_Implementation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Layers")
    void HandleActiveLayerChanged(int32 NewLayer);
    virtual void HandleActiveLayerChanged_Implementation(int32 NewLayer);

private:
    UPROPERTY()
    TObjectPtr<UGridSubsystem> GridSubsystem;
    
    UPROPERTY()
    TObjectPtr<UGridInteractionComponent> GridInteractionComponent;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TObjectPtr<UDataTable> CellDisplayColorTable;
    
    TArray<FIntVector> DisplayedMovableRangeCells;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true), Category="Grid|ISM")
    float ISM_ZOffset = 1.0f;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true), Category="Grid|ISM")
    int32 NumCustomDataFloats = 4;

    UPROPERTY(BLueprintReadWrite, Category="Grid|Visual", meta=(AllowPrivateAccess=true))
    TMap<FIntVector, FCellDisplayStateData> GridCellDisplayStates = TMap<FIntVector, FCellDisplayStateData>();
    
    UFUNCTION(BlueprintCallable, Category = "Grid|Visual", meta=(AllowPrivateAccess=true))
    void RefreshGridCellDisplayState(FIntVector CellCoord);

    
#pragma region Debug
public:
    // ── 디버그용 설정 ────────────────────────────────────
    // bShowDebugCoords: 기본값 false, 개발 중에만 ON
    // ActiveLayer에 해당하는 셀만 필터링하여 표시
    
    // 각 셀의 상태를 표시할 ISM
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid|ISM")
    TObjectPtr<UInstancedStaticMeshComponent> ISM_CellDebug;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug")
    FLinearColor DebugTextColor = FLinearColor::Yellow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug")
    float DebugTextDuration = -1.f;   // -1 = 무한 유지

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug")
    float DebugTextZOffset = 10.f;    // 바닥에 묻히지 않도록 Z축 오프셋
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Debug")
    void InitializeDebugCellInstances();
    virtual void InitializeDebugCellInstances_Implementation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Debug")
    void ClearDebugCellInstances();
    virtual void ClearDebugCellInstances_Implementation();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Debug")
    void InitializeDebugCoords();
    virtual void InitializeDebugCoords_Implementation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Debug")
    void ClearDebugCoords();
    virtual void ClearDebugCoords_Implementation();

    UFUNCTION(CallInEditor, Category = "Grid|Debug")
    void InitializeDebugCellInstancesInEditor();
    
    UFUNCTION(CallInEditor, Category = "Grid|Debug")
    void ClearDebugCellInstancesInEditor();
    
    UFUNCTION(CallInEditor, Category = "Grid|Debug")
    void InitializeDebugCoordsInEditor();
    
    UFUNCTION(CallInEditor, Category = "Grid|Debug")
    void ClearDebugCoordsInEditor();

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug", meta=(AllowPrivateAccess=true))
    TArray<TObjectPtr<class ATextRenderActor>> DebugCellCoords;
#pragma endregion 
};
