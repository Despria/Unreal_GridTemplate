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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> GridInputMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	int32 GridInputMappingPriority = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputAction> IA_MouseClick;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputAction> IA_MouseWheel;
	
	UFUNCTION(BlueprintCallable, Category = "Components")
	UGridInteractionComponent* GetGridInteractionComponent();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess=true))
	TObjectPtr<UGridInteractionComponent> GridInteractionComponent;
	
};
