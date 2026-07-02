// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/ActorComponent/GridInteractionComponent.h"

// Sets default values for this component's properties
UGridInteractionComponent::UGridInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGridInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UGridInteractionComponent::PerformTrace_Implementation() {
    
}

