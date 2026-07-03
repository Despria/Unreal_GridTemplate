// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridVisualizer.h"

// Sets default values
AGridVisualizer::AGridVisualizer()
{
 	
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

