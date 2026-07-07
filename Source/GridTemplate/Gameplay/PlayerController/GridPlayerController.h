// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Gameplay/ActorComponent/GridInteractionComponent.h"
#include "InputMappingContext.h"
#include "GridPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GRIDTEMPLATE_API AGridPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGridPlayerController();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UGridInteractionComponent> GridInteractionComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> GridInputMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	int32 GridInputMappingPriority = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UInputAction> IA_MouseClick;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UInputAction> IA_MouseWheel;
	
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
