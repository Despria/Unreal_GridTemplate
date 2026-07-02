// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Gameplay/ActorComponent/GridInteractionComponent.h"
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
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
