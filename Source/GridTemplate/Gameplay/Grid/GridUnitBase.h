// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridUnit.h"
#include "GameFramework/Actor.h"
#include "Gameplay/Data/UnitBaseStatDataAsset.h"
#include "Gameplay/Item/EquipmentItem.h"
#include "GridUnitBase.generated.h"

class UGridSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitSpawned, AGridUnitBase*, Unit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitDestroyed, AGridUnitBase*, Unit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitMovementStarted, AGridUnitBase*, Unit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnUnitReachedCell, AGridUnitBase*, Unit, FIntVector, PreviousCellCoord, FIntVector, NewCellCoord);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitMovementFinished, AGridUnitBase*, Unit);

UCLASS(Abstract)
class GRIDTEMPLATE_API AGridUnitBase : public APawn, public IGridUnit
{
	GENERATED_BODY()
	
public:
	AGridUnitBase();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Unit|Status")
	TObjectPtr<UUnitBaseStatDataAsset> UnitBaseStatDataAsset = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category="Unit|Status")
	FUnitBaseStatData UnitBaseStatData = FUnitBaseStatData();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Unit|Interaction")
	bool bIsInteractable = true;
	
public:
	virtual FIntVector GetCellCoord() const override;
	virtual int32 GetMovementPoints() const override;
	virtual bool IsDiagonalMovable() const override;
	virtual bool IsInteractable() const override;

	#pragma region Initialization / Lifecycle
public:
	// Spawner(SpawnActorDeferred 사용)가 장비 등 외부 정보 설정을 마친 뒤 명시적으로 호출.
	// BeginPlay()에서도 자동 호출되지만, bIsStatInitialized 가드로 인해 이미 초기화된 경우 재실행되지 않음.
	// (레벨에 직접 배치된 유닛은 BeginPlay()가 유일한 호출 시점이 됨)
	UFUNCTION(BlueprintCallable, Category = "Unit|Initialization")
	void InitializeUnit();
 
	// 유닛의 초기화(스탯/아이템 반영 등)가 모두 끝난 뒤, BeginPlay() 시점에 1회 발행됨.
	// GridSubsystem 등이 이 델리게이트를 구독하여 유닛 리스트에 등록 + 다른 델리게이트에 바인딩.
	UPROPERTY(BlueprintAssignable, Category = "Unit|Lifecycle")
	FOnUnitSpawned OnUnitSpawned;
 
	// 유닛이 실제로 제거되는 시점(EndPlay, EEndPlayReason::Destroyed)에 발행됨.
	// GridSubsystem 등이 이 델리게이트를 구독하여 유닛 리스트에서 제거 + 마지막 점유 셀 해제.
	UPROPERTY(BlueprintAssignable, Category = "Unit|Lifecycle")
	FOnUnitDestroyed OnUnitDestroyed;
 
private:
	bool bIsInitialized = false;
#pragma endregion
 
#pragma region Grid Movement
public:
	// 이동 속도 (Units/sec)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit|Movement")
	float MovementSpeed = 300.f;
 
	// 이동 중 진행 방향으로 회전하는 속도 (Degrees/sec)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit|Movement")
	float RotationInterpSpeed = 540.f;
 
	// 목표 셀 중심에 도달했다고 판정할 허용 오차 (uu)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit|Movement")
	float ArrivalTolerance = 5.f;
 
	// 경로 이동이 시작되는 시점 (MoveAlongPath 호출 시 1회)
	UPROPERTY(BlueprintAssignable, Category = "Unit|Movement")
	FOnUnitMovementStarted OnUnitMovementStarted;
 
	// 경로 상의 각 셀에 도착할 때마다 발행. PreviousCellCoord/NewCellCoord를 함께 전달하여
	// 구독자(GridSubsystem 등)가 별도의 캐시 없이도 점유 셀을 갱신할 수 있도록 함.
	UPROPERTY(BlueprintAssignable, Category = "Unit|Movement")
	FOnUnitReachedCell OnUnitReachedCell;
 
	// 경로 전체 이동이 끝난 시점 (마지막 셀 도착 직후 1회)
	UPROPERTY(BlueprintAssignable, Category = "Unit|Movement")
	FOnUnitMovementFinished OnUnitMovementFinished;
 
	// Path에 시작 셀(현재 위치)이 포함되어 있어도, 빠져 있어도 무방함
	// (내부적으로 Path[0]이 현재 CurrentCellCoord와 같으면 자동으로 건너뜀)
	UFUNCTION(BlueprintCallable, Category = "Unit|Movement")
	void MoveAlongPath(const TArray<FIntVector>& Path);
 
	UFUNCTION(BlueprintCallable, Category = "Unit|Movement")
	void StopMovement();
 
	UFUNCTION(BlueprintCallable, Category = "Unit|Movement")
	FORCEINLINE bool IsMoving() const { return bIsMoving; }
 
protected:
	// 현재 목표 웨이포인트로 한 스텝 이동 처리. 도착 시 true 반환.
	bool TickMoveToCell(float DeltaTime);
 
	// MovePathIndex가 가리키는 다음 웨이포인트의 월드 좌표를 계산하고 이동 시작
	void MoveToNextCellCoord();
 
private:
	// 유닛이 현재 "점유"하고 있다고 판정되는 셀 좌표.
	// 이동 중 GetActorLocation() 기반 실시간 역산 시 셀 사이 애매한 값이 나오는 것을 방지하기 위해,
	// 매 웨이포인트 도착 시점에만 갱신되는 캐시 값으로 관리함.
	UPROPERTY(BlueprintReadOnly, Category = "Unit|Movement", meta = (AllowPrivateAccess = true))
	FIntVector CurrentCellCoord = FIntVector(INT_MIN, INT_MIN, INT_MIN);
 
	TArray<FIntVector> MovePath;
	int32 MovePathIndex = INDEX_NONE;
	bool bIsMoving = false;
	FVector CurrentTargetLocation = FVector::ZeroVector;
 
	UPROPERTY()
	TObjectPtr<UGridSubsystem> GridSubsystem;
#pragma endregion
 
#pragma region Equipment
private:
	// 장착 중인 아이템 리스트. IItem/IEquipmentItem 인터페이스 확정 후 아래 선언 및
	// InitializeUnit()의 반복 로직 주석을 해제하여 반영 예정.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit|Equipment", meta = (AllowPrivateAccess = true))
	TArray<TScriptInterface<IEquipmentItem>> EquippedItems;
#pragma endregion
};
