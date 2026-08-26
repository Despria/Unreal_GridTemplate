// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridUnitBase.h"

#include "GridMath.h"
#include "Gameplay/Subsystem/GridSubsystem.h"

AGridUnitBase::AGridUnitBase()
{
	PrimaryActorTick.bCanEverTick = true;
 
	// 그리드 유닛은 플레이어/AI 컨트롤러가 직접 빙의하지 않고, 별도 로직(턴 시스템 등)으로 제어됨
	AutoPossessPlayer = EAutoReceiveInput::Disabled;
	AutoPossessAI = EAutoPossessAI::Disabled;
}

void AGridUnitBase::BeginPlay()
{
	Super::BeginPlay();
	// Spawner(SpawnActorDeferred)가 이미 호출했다면 bIsStatInitialized 가드로 인해 아무 일도 하지 않고 반환됨.
	// 레벨에 직접 배치된 유닛의 경우 여기서 최초로 초기화됨.
	InitializeUnit();
 
	// BeginPlay는 액터 생명주기 동안 정확히 1회만 호출되므로, 초기화 경로(스포너/레벨 배치)와 무관하게 여기서 1회 발행
	OnUnitSpawned.Broadcast(this);
}

void AGridUnitBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (EndPlayReason == EEndPlayReason::Destroyed)
	{
		OnUnitDestroyed.Broadcast(this);
	}
 
	OnUnitSpawned.Clear();
	OnUnitDestroyed.Clear();
	OnUnitMovementStarted.Clear();
	OnUnitReachedCell.Clear();
	OnUnitMovementFinished.Clear();
 
	Super::EndPlay(EndPlayReason);
}
 
void AGridUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
 
	if (bIsMoving)
	{
		TickMoveToCell(DeltaTime);
	}
}

void AGridUnitBase::InitializeUnit()
{
	if (bIsStatInitialized)
	{
		return;
	}
 
	if (!UnitBaseStatDataAsset)
	{
		UE_LOG(LogTemp, Error, TEXT("GridUnitBase::UnitBaseStatDataAsset IS NULL!!"))
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("GridUnitBaseStatDataAsset IS NULL!!"));
		Destroy();
		return;
	}
 
	// 1. 베이스 스탯 반영
	UnitBaseStatData.InitializeFromBaseStat(UnitBaseStatDataAsset);
 
	// 2. 장착 아이템 효과 반영
	for (const TScriptInterface<IEquipmentItem>& Item : EquippedItems)
	{
		if (Item)
		{
			Item->Apply(this);
		}
	}
 
	GridSubsystem = GetWorld()->GetSubsystem<UGridSubsystem>();
	if (GridSubsystem)
	{
		CurrentCellCoord = UGridMath::WorldLocationToCellCoord(
			GetActorLocation(),
			GridSubsystem->GetGridOrigin(),
			GridSubsystem->GetCellSize(),
			GridSubsystem->GetActiveLayer());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GridUnitBase::InitializeUnit - GridSubsystem is NULL!!"));
	}
 
	bIsStatInitialized = true;
	// 필요하다면 CurrentCellCoord 1회 초기화
}

FIntVector AGridUnitBase::GetCellCoord() const
{
	return CurrentCellCoord;
}

int32 AGridUnitBase::GetMovementPoints() const
{
	return UnitBaseStatData.MovementPoint;
}

bool AGridUnitBase::IsDiagonalMovable() const
{
	return UnitBaseStatData.bIsDiagonal;
}

bool AGridUnitBase::IsInteractable() const
{
	return bIsInteractable;
}

#pragma region Grid Movement
void AGridUnitBase::MoveAlongPath(const TArray<FIntVector>& Path)
{
	if (Path.IsEmpty() || !GridSubsystem)
	{
		return;
	}
 
	MovePath = Path;
	MovePathIndex = 0;
 
	// A*가 반환하는 Path는 시작 셀(현재 위치)을 포함하므로, 그 경우 첫 좌표는 건너뜀
	if (MovePath[0] == CurrentCellCoord)
	{
		MovePathIndex = 1;
	}
 
	if (!MovePath.IsValidIndex(MovePathIndex))
	{
		// 이동할 셀이 없음 (제자리 경로)
		MovePath.Empty();
		MovePathIndex = INDEX_NONE;
		return;
	}
 
	OnUnitMovementStarted.Broadcast(this);
	AdvanceToNextWaypoint();
}
 
void AGridUnitBase::StopMovement()
{
	bIsMoving = false;
	MovePath.Empty();
	MovePathIndex = INDEX_NONE;
}
 
void AGridUnitBase::AdvanceToNextWaypoint()
{
	if (!GridSubsystem || !MovePath.IsValidIndex(MovePathIndex))
	{
		bIsMoving = false;
		MovePath.Empty();
		MovePathIndex = INDEX_NONE;
		OnUnitMovementFinished.Broadcast(this);
		return;
	}
 
	CurrentTargetLocation = UGridMath::CellCenterToWorldLocation(
		MovePath[MovePathIndex],
		GridSubsystem->GetGridOrigin(),
		GridSubsystem->GetCellSize(),
		GridSubsystem->GetLayerBaseHeights());
 
	// Z값은 현재 액터 위치를 유지 (레이어 간 높이 차 반영은 추후 별도 처리 필요)
	CurrentTargetLocation.Z = GetActorLocation().Z;
 
	bIsMoving = true;
}
 
bool AGridUnitBase::TickMoveToCell(float DeltaTime)
{
	const FVector CurrentLocation = GetActorLocation();
	const FVector NewLocation = FMath::VInterpConstantTo(
		CurrentLocation, CurrentTargetLocation, DeltaTime, MovementSpeed);
	SetActorLocation(NewLocation);
 
	// 진행 방향으로 회전 (Pitch/Roll은 고정, Yaw만 반영)
	const FVector Direction = CurrentTargetLocation - CurrentLocation;
	if (!Direction.IsNearlyZero())
	{
		FRotator TargetRotation = Direction.Rotation();
		TargetRotation.Pitch = 0.f;
		TargetRotation.Roll = 0.f;
 
		const FRotator NewRotation = FMath::RInterpConstantTo(
			GetActorRotation(), TargetRotation, DeltaTime, RotationInterpSpeed);
		SetActorRotation(NewRotation);
	}
 
	if (FVector::DistSquared(NewLocation, CurrentTargetLocation) <= FMath::Square(ArrivalTolerance))
	{
		SetActorLocation(CurrentTargetLocation);
 
		const FIntVector PreviousCellCoord = CurrentCellCoord;
		CurrentCellCoord = MovePath[MovePathIndex];
		OnUnitReachedCell.Broadcast(this, PreviousCellCoord, CurrentCellCoord);
 
		MovePathIndex++;
 
		if (MovePath.IsValidIndex(MovePathIndex))
		{
			AdvanceToNextWaypoint();
		}
		else
		{
			bIsMoving = false;
			MovePath.Empty();
			MovePathIndex = INDEX_NONE;
			OnUnitMovementFinished.Broadcast(this);
		}
		return true;
	}
	return false;
}
#pragma endregion


