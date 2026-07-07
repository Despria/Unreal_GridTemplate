// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/ActorComponent/GridInteractionComponent.h"

#include "InputActionValue.h"
#include "Gameplay/Grid/GridUnit.h"
#include "Gameplay/Subsystem/GridSubsystem.h"

UGridInteractionComponent::UGridInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
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
	PerformHovering();
}

void UGridInteractionComponent::PerformClick(const FInputActionValue& Value) {
	bool isClicked = Value.Get<bool>();
	if (!isClicked) return;
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("Click"));
	
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

void UGridInteractionComponent::PerformHovering() {
	FHitResult Hit;
	if (!PerformLineTrace(Hit)) return;
	if (!GridSubsystem) return;

	FIntVector CellCoord = GridSubsystem->WorldLocationToCellCoord(Hit.Location); 
	if (GridSubsystem->IsValidCell(CellCoord))
	{
		if (CellCoord != LastHoveredCell)
		{
			LastHoveredCell = CellCoord;
			OnCellHovered.Broadcast(CellCoord);
		}
	}
	else
	{
		// 현재 어떤 Cell위에도 마우스가 없는 상태에서, 다시 OnCellHoverExited가 호출되는 것을 방지하는 조건문
		if (LastHoveredCell != FIntVector(INT_MIN, INT_MIN, INT_MIN))
		{
			LastHoveredCell = FIntVector(INT_MIN, INT_MIN, INT_MIN);
			OnCellHoverExited.Broadcast();
		}
	}
}

void UGridInteractionComponent::PerformWheel(const FInputActionValue& Value)
{
	float WheelAxis = Value.Get<float>();
	UE_LOG(LogTemp, Warning, TEXT("MouseWheel %f"), WheelAxis);
	// 마우스 휠에 따른 로직 필요
}

bool UGridInteractionComponent::PerformLineTrace(FHitResult& OutHitResult) const
{
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	if (!PC) return false;

	FVector WorldLocation, WorldDirection;
	PC->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());

	// ECC_Visibility는 추후 Grid 전용 콜리전 채널로 변경해야 함.
	return GetWorld()->LineTraceSingleByChannel(
		OutHitResult,
		WorldLocation,
		WorldLocation + WorldDirection * TraceDistance,
		ECC_Visibility,
		Params
	);
}
