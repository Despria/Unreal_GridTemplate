// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GridInteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCellClicked, FIntVector, GridCoord);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCellHovered, FIntVector, GridCoord);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitClicked, AActor*, HitActor);

UCLASS(BlueprintType, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRIDTEMPLATE_API UGridInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGridInteractionComponent();

public:
	UPROPERTY(BlueprintAssignable, Category="Interaction|Events")
	FOnCellClicked OnCellClicked;
	
	UPROPERTY(BlueprintAssignable, Category="Interaction|Events")
	FOnCellHovered OnCellHovered;
	
	UPROPERTY(BlueprintAssignable, Category="Interaction|Events")
	FOnUnitClicked OnUnitClicked;
	
	UPROPERTY(EditAnywhere, Category="Interaction|Events")
	float TraceDistance;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interaction|Events")
	void PerformClick();
	virtual void PerformClick_Implementation();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interaction|Events")
	void PerformHovering();
	virtual void PerformHovering_Implementation();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
private:
	bool PerformLineTrace(FHitResult& OutHitResult) const;
	FIntVector LastHoveredCell = FIntVector(INT_MIN, INT_MIN, INT_MIN);

};
