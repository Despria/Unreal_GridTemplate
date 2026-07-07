// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/Subsystem/GridSubsystem.h"
#include "GridInteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCellClicked, FIntVector, GridCoord);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCellHovered, FIntVector, GridCoord);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCellHoverExited);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitClicked, AActor*, HitActor);

UCLASS(BlueprintType, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRIDTEMPLATE_API UGridInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGridInteractionComponent();

public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APlayerController> PlayerController;
	
	UPROPERTY(BlueprintAssignable, Category="Interaction|Events")
	FOnCellClicked OnCellClicked;
	
	UPROPERTY(BlueprintAssignable, Category="Interaction|Events")
	FOnCellHovered OnCellHovered;
	
	UPROPERTY(BlueprintAssignable, Category="Interaction|Events")
	FOnCellHoverExited OnCellHoverExited;
	
	UPROPERTY(BlueprintAssignable, Category="Interaction|Events")
	FOnUnitClicked OnUnitClicked;
	
	UPROPERTY(EditAnywhere, Category="Interaction|Events")
	float TraceDistance = 100000.f;
	
	UFUNCTION(BlueprintCallable, Category="Interaction|Events")
	void PerformClick(const FInputActionValue& Value);
	
	UFUNCTION(BlueprintCallable, Category="Interaction|Events")
	void PerformHovering();
	
	UFUNCTION(BlueprintCallable, Category="Interaction|Events")
	void PerformWheel(const FInputActionValue& Value);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	TObjectPtr<UGridSubsystem> GridSubsystem;
	
	bool PerformLineTrace(FHitResult& OutHitResult) const;
	FIntVector LastHoveredCell = FIntVector(INT_MIN, INT_MIN, INT_MIN);
	FVector2D LastMousePosition = FVector2D::ZeroVector;
};
