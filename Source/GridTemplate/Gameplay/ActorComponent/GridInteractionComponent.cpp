// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/ActorComponent/GridInteractionComponent.h"

#include "InputActionValue.h"
#include "Gameplay/Grid/GridUnit.h"
#include "Gameplay/Subsystem/GridSubsystem.h"

// Sets default values for this component's properties
UGridInteractionComponent::UGridInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UGridInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UGridInteractionComponent::PerformClick_Implementation() {
	FHitResult Hit;
	if (!PerformLineTrace(Hit)) return;

	AActor* HitActor = Hit.GetActor();
	if (HitActor && HitActor->GetClass()->ImplementsInterface(UGridUnit::StaticClass()))
	{
		OnUnitClicked.Broadcast(HitActor);
		return;
	}

	UGridSubsystem* GridSub = GetWorld()->GetSubsystem<UGridSubsystem>();
	if (!GridSub) return;

	FIntVector CellCoord = GridSub->WorldLocationToCellCoord(Hit.Location);
	if (GridSub->IsValidCell(CellCoord))
	{
		OnCellClicked.Broadcast(CellCoord);
	}
}

void UGridInteractionComponent::PerformHovering_Implementation() {
	FHitResult Hit;
	if (!PerformLineTrace(Hit)) return;

	UGridSubsystem* GridSub = GetWorld()->GetSubsystem<UGridSubsystem>();
	if (!GridSub) return;

	FIntVector CellCoord = GridSub->WorldLocationToCellCoord(Hit.Location);
	if (GridSub->IsValidCell(CellCoord))
	{
		// 이전 호버 셀과 다를 때만 발행 (불필요한 갱신 방지)
		if (CellCoord != LastHoveredCell)
		{
			LastHoveredCell = CellCoord;
			OnCellHovered.Broadcast(CellCoord);
		}
	}
}

bool UGridInteractionComponent::PerformLineTrace(FHitResult& OutHitResult) const
{
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	if (!PC) return false;

	FVector WorldLocation, WorldDirection;
	PC->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());

	return GetWorld()->LineTraceSingleByChannel(
		OutHitResult,
		WorldLocation,
		WorldLocation + WorldDirection * TraceDistance,
		ECC_Visibility,
		Params
	);
}
