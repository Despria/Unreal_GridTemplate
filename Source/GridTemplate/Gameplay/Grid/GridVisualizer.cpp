// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridVisualizer.h"
#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
AGridVisualizer::AGridVisualizer()
{
	PrimaryActorTick.bCanEverTick = false;
 	SetRootComponent(CreateDefaultSubobject<USceneComponent>("GridRoot"));
	
	GridMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grid_ActiveLayer"));
	GridMeshComponent->SetupAttachment(GetRootComponent());
	GridMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GridMeshComponent->SetGenerateOverlapEvents(false);
	
	ISM_Attack = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM_AttackCell"));
	ISM_Attack->SetupAttachment(GetRootComponent());
	ISM_Attack->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ISM_Attack->SetGenerateOverlapEvents(false);
	
	ISM_Movement = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM_MovementCell"));
	ISM_Movement->SetupAttachment(GetRootComponent());
	ISM_Movement->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ISM_Movement->SetGenerateOverlapEvents(false);
	
	ISM_Path = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM_PathCell"));
	ISM_Path->SetupAttachment(GetRootComponent());
	ISM_Path->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ISM_Path->SetGenerateOverlapEvents(false);
}

// Called when the game starts or when spawned
void AGridVisualizer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGridVisualizer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AGridVisualizer::ShowMovableRange_Implementation(const TArray<FIntVector>& Cells)
{
}

void AGridVisualizer::ShowAttackRange_Implementation(const TArray<FIntVector>& Cells)
{
}

void AGridVisualizer::ShowPath_Implementation(const TArray<FIntVector>& Cells)
{
}

void AGridVisualizer::ClearAll_Implementation()
{
}

void AGridVisualizer::InitGridMesh_Implementation()
{
}

void AGridVisualizer::UpdateGridMaterial_Implementation()
{
}

void AGridVisualizer::HandleActiveLayerChanged_Implementation(int32 NewLayer)
{
}

void AGridVisualizer::ShowDebugCoords_Implementation()
{
}

void AGridVisualizer::ClearDebugCoords_Implementation()
{
}

void AGridVisualizer::ShowDebugCoordsInEditor()
{
	ShowDebugCoords();
}

void AGridVisualizer::ClearDebugCoordsInEditor()
{
	ClearDebugCoords();
}

void AGridVisualizer::BindToGridManager()
{
}

void AGridVisualizer::UnbindFromGridManager()
{
}

void AGridVisualizer::RefreshISM(UInstancedStaticMeshComponent* ISM, const TArray<FIntVector>& Cells)
{
}

