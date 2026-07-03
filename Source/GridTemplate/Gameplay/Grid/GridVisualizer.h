// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Subsystem/GridSubsystem.h"
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
    // GridManager와 동기화 필요
    // 머티리얼/ISM/디버그 텍스트 모두 이 값을 기준으로 동작

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

    // ── 게임용: ISM 하이라이트 ───────────────────────────
    // GridManager 델리게이트 수신 → ClearInstances() 후 재생성
    // Per-Instance Custom Data로 셀별 색상 개별 제어

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid|ISM")
    TObjectPtr<UInstancedStaticMeshComponent> ISM_Movement;  // 이동 가능 범위 (파란색)

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid|ISM")
    TObjectPtr<UInstancedStaticMeshComponent> ISM_Attack;    // 공격 가능 범위 (빨간색)

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid|ISM")
    TObjectPtr<UInstancedStaticMeshComponent> ISM_Path;      // 경로 표시 (노란색)

    // ISM에 사용할 셀 크기 평면 메쉬
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|ISM")
    TObjectPtr<UStaticMesh> CellMesh;

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

    // ── 게임용: ISM 갱신 함수 ────────────────────────────
    // GridManager 델리게이트에 바인딩
    // 수신 시 ClearInstances() 후 셀 목록 기준으로 인스턴스 재생성

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void ShowMovableRange(const TArray<FIntVector>& Cells);
    virtual void ShowMovableRange_Implementation(const TArray<FIntVector>& Cells);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void ShowAttackRange(const TArray<FIntVector>& Cells);
    virtual void ShowAttackRange_Implementation(const TArray<FIntVector>& Cells);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void ShowPath(const TArray<FIntVector>& Cells);
    virtual void ShowPath_Implementation(const TArray<FIntVector>& Cells);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|ISM")
    void ClearAll();
    virtual void ClearAll_Implementation();

    // ── 게임용: 그리드 평면 제어 함수 ───────────────────

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

    // ── 디버그 함수 ──────────────────────────────────────
    // ShowDebugCoords: ActiveLayer 셀만 필터링하여 DrawDebugString
    // 에디터 모드: 자체 변수(CellSize/Width/Height/GridOrigin)로 직접 계산
    // PIE 모드: GridManager 데이터 사용

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Debug")
    void ShowDebugCoords();
    virtual void ShowDebugCoords_Implementation();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Grid|Debug")
    void ClearDebugCoords();
    virtual void ClearDebugCoords_Implementation();

    // 에디터 디테일 패널 버튼으로 노출 (PIE 없이 에디터에서 직접 실행)
    UFUNCTION(CallInEditor, Category = "Grid|Debug")
    void ShowDebugCoordsInEditor();

    UFUNCTION(CallInEditor, Category = "Grid|Debug")
    void ClearDebugCoordsInEditor();

private:
    // ── 내부 참조 ────────────────────────────────────────
    // BeginPlay 시 GetWorld()->GetSubsystem<UGridManager>()로 캐싱
    // 에디터 모드에서는 nullptr일 수 있으므로 항상 IsValid() 체크 필요

    UPROPERTY()
    TObjectPtr<UGridSubsystem> CachedGridManager;

    // 델리게이트 바인딩 핸들 (EndPlay 시 해제용)
    FDelegateHandle MovableRangeHandle;
    FDelegateHandle AttackRangeHandle;
    FDelegateHandle PathHandle;
    FDelegateHandle SelectionClearedHandle;
    FDelegateHandle ActiveLayerHandle;
    FDelegateHandle InitializeGridHandle;

    // GridManager 델리게이트 바인딩/해제
    void BindToGridManager();
    void UnbindFromGridManager();

    // ISM 공통 갱신 로직
    void RefreshISM(UInstancedStaticMeshComponent* ISM, const TArray<FIntVector>& Cells);
};
