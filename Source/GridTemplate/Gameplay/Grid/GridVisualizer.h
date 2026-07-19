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
    // ── 공통 설정 ─────────────────────────────────────────
    // GridSubsystem과 동일한 수치로 유지, 머티리얼/ISM/디버그 텍스트 모두 이 값을 기준으로 동작 (BeginPlay에서 별도 동기화 함)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Setup")
    float CellSize = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Setup")
    int32 GridWidth = 20;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Setup")
    int32 GridHeight = 20;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Setup")
    FVector GridOrigin = FVector::ZeroVector;
    
    // ── 게임용: 레벨 전체 그리드 평면 ───────────────────
    // 현재 Opaque 머티리얼 사용, 추후 Deferred Decal로 전환 예정
    // ActiveLayer 전환 시 Z 위치를 LayerBaseHeights[ActiveLayer]로 이동

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid|Mesh")
    TObjectPtr<UStaticMeshComponent> GridMeshComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Mesh")
    TObjectPtr<UMaterialInterface> GridMaterial;

    // 각 셀의 상태를 표시할 ISM
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid|ISM")
    TObjectPtr<UInstancedStaticMeshComponent> ISM_CellDisplayState;

    // ISM에 사용할 셀 크기 평면 메쉬
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|ISM")
    TObjectPtr<UStaticMesh> CellMesh;

    // ── 게임용: ISM 갱신 함수 ────────────────────────────
    // GridManager 델리게이트에 바인딩
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnShowMovableRangeHandler(const TArray<FIntVector>& Cells);
    virtual void OnShowMovableRangeHandler_Implementation(const TArray<FIntVector>& Cells);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void OnShowAttackRangeHandler(const TArray<FIntVector>& Cells);
    virtual void OnShowAttackRangeHandler_Implementation(const TArray<FIntVector>& Cells);

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
    
    // ── 층 전환 처리 ─────────────────────────────────────
    // OnActiveLayerChanged 델리게이트 수신 시 호출
    // 그리드 평면 Z 이동 + ISM 전체 초기화

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Layers")
    void HandleActiveLayerChanged(int32 NewLayer);
    virtual void HandleActiveLayerChanged_Implementation(int32 NewLayer);
    
    // ── 디버그용 설정 ────────────────────────────────────
    // bShowDebugCoords: 기본값 false, 개발 중에만 ON
    // ActiveLayer에 해당하는 셀만 필터링하여 표시

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug")
    bool bShowDebugCoords = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug")
    FLinearColor DebugTextColor = FLinearColor::Yellow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug")
    float DebugTextDuration = -1.f;   // -1 = 무한 유지

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug")
    float DebugTextZOffset = 10.f;    // 바닥에 묻히지 않도록 Z축 오프셋
    
    // ── 디버그 함수 ──────────────────────────────────────
    // ShowDebugCoords: ActiveLayer 셀만 필터링하여 DrawDebugString
    // 에디터 모드: 자체 변수(CellSize/Width/Height/GridOrigin)로 직접 계산
    // PIE 모드: GridManager 데이터 사용

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Debug")
    void InitializeDebugCoords();
    virtual void InitializeDebugCoords_Implementation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Debug")
    void ToggleDebugCoords();
    virtual void ToggleDebugCoords_Implementation();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Debug")
    void ClearDebugCoords();
    virtual void ClearDebugCoords_Implementation();

    // 에디터 디테일 패널 버튼으로 노출 (PIE 없이 에디터에서 직접 실행)
    UFUNCTION(CallInEditor, Category = "Grid|Debug")
    void InitializeDebugCoordsInEditor();
    
    UFUNCTION(CallInEditor, Category = "Grid|Debug")
    void ToggleDebugCoordsInEditor();

    UFUNCTION(CallInEditor, Category = "Grid|Debug")
    void ClearDebugCoordsInEditor();

private:
    // ── 내부 참조 ────────────────────────────────────────
    // BeginPlay 시 GetWorld()->GetSubsystem<UGridManager>()로 캐싱
    // 에디터 모드에서는 nullptr일 수 있으므로 항상 IsValid() 체크 필요
    
    UPROPERTY()
    TObjectPtr<UGridSubsystem> GridSubsystem;
    
    UPROPERTY()
    TObjectPtr<UGridInteractionComponent> GridInteractionComponent;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TObjectPtr<UDataTable> CellDisplayColorTable;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true), Category="Grid|ISM")
    float ISM_ZOffset = 1.0f;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true), Category="Grid|ISM")
    int32 NumCustomDataFloats = 4;

    // 상태표시가 전환된 Cell들을 관리하기 위한 Map
    // Click, Hover, MoveRange 등 특정 상태를 표시해야 하는 Cell이라면 여기 담아서 상태 갱신에 활용 (전체 그리드를 대상으로 순회하면 비효율적)
    // 어떠한 상태도 없어진 Cell이라면 Map에서 제거하면 됨.
    UPROPERTY(BLueprintReadWrite, Category="Grid|Visual", meta=(AllowPrivateAccess=true))
    TMap<FIntVector, FCellDisplayStateData> GridCellDisplayStates = TMap<FIntVector, FCellDisplayStateData>();
    
    UFUNCTION(BlueprintCallable, Category = "Grid|Visual", meta=(AllowPrivateAccess=true))
    void RefreshGridCellDisplayState(FIntVector CellCoord);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug", meta=(AllowPrivateAccess=true))
    TArray<TObjectPtr<class ATextRenderActor>> DebugCellCoords;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Debug", meta=(AllowPrivateAccess=true))
    bool bIsShowingDebugCoords = false;
    
    // GridManager 델리게이트 바인딩/해제
    void BindToGridManager();
    void UnbindFromGridManager();

};
