// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/PlayerController/GridPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

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
                // Priority: 값이 높을수록 우선순위 높음
                // 여러 IMC가 동시에 등록될 경우 우선순위로 충돌 해결
                Subsystem->AddMappingContext(GridInputMappingContext, GridInputMappingPriority);
            }
        }
    }
}

void AGridPlayerController::SetupInputComponent() {
    Super::SetupInputComponent();

    // ── BindAction: InputAction → 함수 연결 ──────────────
    // AddMappingContext는 IMC 등록 담당 (BeginPlay에서 처리)
    // BindAction은 "해당 InputAction 발생 시 어떤 함수를 호출하는가" 담당
    // 두 역할이 다르므로 함께 사용

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
            ETriggerEvent::Triggered,
            GridInteractionComponent.Get(),
            &UGridInteractionComponent::PerformClick
        );
    }

    if (IA_MouseMove)   
    {
        EIC->BindAction(
            IA_MouseMove,
            ETriggerEvent::Triggered,
            GridInteractionComponent.Get(),
            &UGridInteractionComponent::PerformHovering
        );
    }
}

