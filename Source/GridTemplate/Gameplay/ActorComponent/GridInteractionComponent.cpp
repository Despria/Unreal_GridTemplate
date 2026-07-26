// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/ActorComponent/GridInteractionComponent.h"

#include "GridTemplate.h"
#include "InputActionValue.h"
#include "Gameplay/Grid/GridMath.h"
#include "Gameplay/Grid/GridUnit.h"
#include "Gameplay/Subsystem/GridSubsystem.h"

UGridInteractionComponent::UGridInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.05f;
}

void UGridInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	
	GridSubsystem = GetWorld()->GetSubsystem<UGridSubsystem>();
	
	PlayerController = Cast<APlayerController>(GetOwner());
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("UGridInteractionComponent: PlayerController is NULL!!!"));
	}
}

void UGridInteractionComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	if (!PlayerController) return;
	
	FVector2D CurrentMousePos;
	PlayerController->GetMousePosition(CurrentMousePos.X, CurrentMousePos.Y);

	if (CurrentMousePos == LastMousePosition) return;
	LastMousePosition = CurrentMousePos;
	PerformGridHovering();
}

void UGridInteractionComponent::PerformMouseClick(const FInputActionValue& Value) {
	if (!GridSubsystem) return;
	
	bool bIsClicked = Value.Get<bool>();
	if (!bIsClicked) return;
	
	FHitResult Hit;
	if (!PerformGridLineTrace(Hit)) return;
	
	// If already clicked other Cell, cancel that click
	if (LastClickedCell != FIntVector(INT_MIN, INT_MIN, INT_MIN))
	{
		OnCellClickExited.Broadcast(LastClickedCell);
	}
	
	// If Clicked Actor
	AActor* HitActor = Hit.GetActor();
	if (HitActor && HitActor->GetClass()->ImplementsInterface(UGridUnit::StaticClass()))
	{
		FIntVector ActorCellCoord = UGridMath::WorldLocationToCellCoord(HitActor->GetActorLocation(), 
			GridSubsystem->GetGridOrigin(), GridSubsystem->GetCellSize(), GridSubsystem->GetActiveLayer());
		LastClickedCell = ActorCellCoord;
		OnUnitClicked.Broadcast(HitActor);
		return;
	}
	
	// If Clicked Cell
	FIntVector CellCoord = UGridMath::WorldLocationToCellCoord(Hit.Location, 
			GridSubsystem->GetGridOrigin(), GridSubsystem->GetCellSize(), GridSubsystem->GetActiveLayer());
	if (GridSubsystem->IsValidCell(CellCoord))
	{
		LastClickedCell = CellCoord;
		OnCellClicked.Broadcast(CellCoord);
	}
}

void UGridInteractionComponent::PerformGridHovering() {
	if (!GridSubsystem) return;
	
	FHitResult Hit;
	if (!PerformGridLineTrace(Hit))
	{
		UE_LOG(LogTemp, Warning, TEXT("Not on Grid!"));
		// 현재 어떤 Cell위에도 마우스가 없는 상태에서, 다시 OnCellHoverExited가 호출되는 것을 방지하는 조건문
		if (LastHoveredCell != FIntVector(INT_MIN, INT_MIN, INT_MIN))
		{
			OnCellHoverExited.Broadcast(LastHoveredCell);
			LastHoveredCell = FIntVector(INT_MIN, INT_MIN, INT_MIN);
		}
		return;
	}
	
	FIntVector CellCoord = UGridMath::WorldLocationToCellCoord(Hit.Location, 
			GridSubsystem->GetGridOrigin(), GridSubsystem->GetCellSize(), GridSubsystem->GetActiveLayer());
	if (CellCoord != LastHoveredCell)
	{
		if (GridSubsystem->IsValidCell(CellCoord))
		{
			OnCellHoverExited.Broadcast(LastHoveredCell);
			LastHoveredCell = CellCoord;
			OnCellHovered.Broadcast(CellCoord);
		}
		else
		{
			if (LastHoveredCell != FIntVector(INT_MIN, INT_MIN, INT_MIN))
			{
				OnCellHoverExited.Broadcast(LastHoveredCell);
				LastHoveredCell = FIntVector(INT_MIN, INT_MIN, INT_MIN);
			}
		}
	}
}

void UGridInteractionComponent::PerformMouseWheel(const FInputActionValue& Value)
{
	float WheelAxis = Value.Get<float>();
	
	// 마우스 휠에 따른 로직 필요
	// 플레이어 카메라를 가져와서 해당 카메라의 SpringArm을 조절하여 줌 인/아웃 조절
	// GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
}

// Perform LineTrace to Grid
bool UGridInteractionComponent::PerformGridLineTrace(FHitResult& OutHitResult) const
{
	if (!PlayerController) return false;

	FVector WorldLocation, WorldDirection;
	bool bMouseToWorld = PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
	if (!bMouseToWorld) return false;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());
	
	return GetWorld()->LineTraceSingleByChannel(
		OutHitResult,
		WorldLocation,
		WorldLocation + WorldDirection * TraceDistance,
		COLLISION_GRID,
		Params
	);
	
}
