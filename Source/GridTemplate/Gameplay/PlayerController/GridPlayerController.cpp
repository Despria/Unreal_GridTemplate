// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/PlayerController/GridPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

AGridPlayerController::AGridPlayerController() {
    GridInteractionComponent = CreateDefaultSubobject<UGridInteractionComponent>(TEXT("GridInteractionComponent"));
}

void AGridPlayerController::BeginPlay() {
    Super::BeginPlay();
    
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (GridInputMappingContext)
            {
                Subsystem->AddMappingContext(GridInputMappingContext, GridInputMappingPriority);
            }
        }
    }
    bShowMouseCursor = true;
}

void AGridPlayerController::SetupInputComponent() {
    Super::SetupInputComponent();

    UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent);

    if (!EIC)
    {
        UE_LOG(LogTemp, Warning,
            TEXT("[GridPlayerController] EnhancedInputComponent 캐스팅 실패. "
                 "프로젝트 설정에서 DefaultInputComponentClass를 확인하세요."));
        return;
    }

    if (IA_MouseClick)
    {
        EIC->BindAction(
            IA_MouseClick,
            ETriggerEvent::Started,
            GridInteractionComponent.Get(),
            &UGridInteractionComponent::PerformClick
        );
    }
    if (IA_MouseWheel)
    {
        EIC->BindAction(
                IA_MouseWheel,
                ETriggerEvent::Triggered,
                GridInteractionComponent.Get(),
                &UGridInteractionComponent::PerformWheel
            );
    }
}

