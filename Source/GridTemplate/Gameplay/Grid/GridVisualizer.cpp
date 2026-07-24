// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridVisualizer.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"
#include "Gameplay/Data/CellDisplayStateColorAsset.h"
#include "Gameplay/PlayerController/GridPlayerController.h"
#include "Gameplay/Grid/GridUnit.h"

AGridVisualizer::AGridVisualizer()
{
	PrimaryActorTick.bCanEverTick = false;
 	SetRootComponent(CreateDefaultSubobject<USceneComponent>("GridRoot"));
	
	GridMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grid_ActiveLayer"));
	GridMeshComponent->SetupAttachment(GetRootComponent());
	GridMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GridMeshComponent->SetGenerateOverlapEvents(false);
	
	ISM_CellDisplayState = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM_MovementCell"));
	ISM_CellDisplayState->SetupAttachment(GetRootComponent());
	ISM_CellDisplayState->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ISM_CellDisplayState->SetGenerateOverlapEvents(false);
}

void AGridVisualizer::BeginPlay()
{
	// UGridSubsystem으로부터 관련된 정보 받아서 초기화
	GridSubsystem = GetWorld()->GetSubsystem<UGridSubsystem>();
	if (GridSubsystem)
	{
		GridSubsystem->OnActiveLayerChanged.AddDynamic(this, &AGridVisualizer::HandleActiveLayerChanged);
		
		CellSize = GridSubsystem->GetCellSize();
		GridHeight = GridSubsystem->GetGridHeight();
		GridWidth = GridSubsystem->GetGridWidth();
		GridOrigin = GridSubsystem->GetGridOrigin();
	}
	
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		if (UGridInteractionComponent* InteractionComp =
			PC->FindComponentByClass<UGridInteractionComponent>())
		{
			InteractionComp->OnCellClicked.AddDynamic(
				this, &AGridVisualizer::OnCellClickedHandler);
			InteractionComp->OnCellClickExited.AddDynamic(
				this, &AGridVisualizer::OnCellClickExitedHandler);
			InteractionComp->OnCellHovered.AddDynamic(
				this, &AGridVisualizer::OnCellHoveredHandler);
			InteractionComp->OnCellHoverExited.AddDynamic(
				this, &AGridVisualizer::OnCellHoverExitedHandler);
			InteractionComp->OnUnitClicked.AddDynamic(
				this, &AGridVisualizer::OnUnitClickedHandler);
		}
	}
	
	ISM_CellDisplayState->SetNumCustomDataFloats(NumCustomDataFloats);
	TArray<FIntVector> CellCoords;
	for (int i = 0; i < GridSubsystem->GetGridCellCoords(CellCoords); i++)
	{
		int32 InstanceID = ISM_CellDisplayState->AddInstance
			(FTransform(GridSubsystem->CellCoordToWorldLocation(CellCoords[i]) + FVector(0, 0, ISM_ZOffset)));
		GridCellDisplayStates.Add(CellCoords[i], FCellDisplayStateData(ECellDisplayState::Blank, InstanceID));
	}
}

void AGridVisualizer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		if (UGridInteractionComponent* InteractionComp =
			PC->FindComponentByClass<UGridInteractionComponent>())
		{
			InteractionComp->OnCellClicked.RemoveDynamic(
				this, &AGridVisualizer::OnCellClickedHandler);
			InteractionComp->OnCellClickExited.RemoveDynamic(
				this, &AGridVisualizer::OnCellClickExitedHandler);
			InteractionComp->OnCellHovered.RemoveDynamic(
				this, &AGridVisualizer::OnCellHoveredHandler);
			InteractionComp->OnCellHoverExited.RemoveDynamic(
				this, &AGridVisualizer::OnCellHoverExitedHandler);
			InteractionComp->OnUnitClicked.RemoveDynamic(
				this, &AGridVisualizer::OnUnitClickedHandler);
		}
	}
	Super::EndPlay(EndPlayReason);
}

void AGridVisualizer::InitGridMesh_Implementation()
{
	
}

// Set DisplayState(ECellDisplayState) to Cell
void AGridVisualizer::SetCellDisplayState(FIntVector CellCoord, ECellDisplayState NewState)
{
	if (FCellDisplayStateData* CellVisualStates = GridCellDisplayStates.Find(CellCoord))
	{
		if (!CellVisualStates->CellDisplayStates.Contains(NewState))
		{
			CellVisualStates->CellDisplayStates.Add(NewState);
			RefreshGridCellDisplayState(CellCoord);
		}
	}
}

// Remove DisplayState(ECellDisplayState) from Cell
void AGridVisualizer::RemoveCellDisplayState(FIntVector CellCoord, ECellDisplayState StateToRemove)
{
	if (GridCellDisplayStates.Contains(CellCoord))
	{
		FCellDisplayStateData& CellVisualStates = GridCellDisplayStates[CellCoord];
		CellVisualStates.CellDisplayStates.RemoveAll( 
			[StateToRemove](ECellDisplayState CellDisplayState)
			{
				return CellDisplayState == StateToRemove;
			});
		RefreshGridCellDisplayState(CellCoord);
	}
}

// Refresh Cell Display State to Display State with highest priority
// (Priority is defined at ECellDisplayState)
void AGridVisualizer::RefreshGridCellDisplayState(FIntVector CellCoord)
{
	FCellDisplayStateData* StateData = GridCellDisplayStates.Find(CellCoord);
	if (!StateData) return;
	
	// 가장 우선순위가 높은 상태의 색
	int32 InstanceId = StateData->InstanceID;
	if (InstanceId == INDEX_NONE || InstanceId >= ISM_CellDisplayState->GetInstanceCount()) return;
	
	TArray<ECellDisplayState>& CellVisuals = StateData->CellDisplayStates;
	ECellDisplayState CurrentDisplayState = ECellDisplayState::Blank;
	for (int i = 0; i < CellVisuals.Num(); i++)
	{
		if (CurrentDisplayState < CellVisuals[i])
		{
			CurrentDisplayState = CellVisuals[i];	
		}
	}
	
	// ECellDisplayState -> Get Name
	UEnum* CellDisplayStateEnum = StaticEnum<ECellDisplayState>();
	if (!CellDisplayStateEnum) return;
	
	FName CellDisplayStateName;
	int32 CellDisplayStateIndex = CellDisplayStateEnum->GetIndexByValue(static_cast<int32>(CurrentDisplayState));
	if (CellDisplayStateIndex != INDEX_NONE)
	{
		CellDisplayStateName = FName(CellDisplayStateEnum->GetAuthoredNameStringByIndex(CellDisplayStateIndex));
	}
	
	// DataTable Row -> Get FColor
	if (FCellDisplayStateColor* CellDisplayStateColor = 
		CellDisplayColorTable->FindRow<FCellDisplayStateColor>(CellDisplayStateName, TEXT("CellDisplayStateColorTable")))
	{
		FColor Color = CellDisplayStateColor->CellDisplayColor;
		ISM_CellDisplayState->SetCustomDataValue(InstanceId, 0, Color.R, true);
		ISM_CellDisplayState->SetCustomDataValue(InstanceId, 1, Color.G, true);
		ISM_CellDisplayState->SetCustomDataValue(InstanceId, 2, Color.B, true);
		ISM_CellDisplayState->SetCustomDataValue(InstanceId, 3, Color.A, true);
	}
}

void AGridVisualizer::OnShowMovableRangeHandler_Implementation(const TArray<FIntVector>& Cells)
{
	// 유닛 클릭 시 해당 유닛의 이동 가능 반경을 표시
	// GridSubsystem의 함수를 호출하여 해당 위치에 ISM_CellDisplayState로 이동 가능 범위를 표시
}

void AGridVisualizer::OnShowAttackRangeHandler_Implementation(const TArray<FIntVector>& Cells)
{
	// 유닛 공격 스킬 선택 시 공격 가능 반경을 표시
	// GridSubsystem의 함수를 호출하여 해당 위치에 ISM_CellDisplayState로 공격 가능 범위를 표시
}

void AGridVisualizer::OnShowPathHandler_Implementation(const TArray<FIntVector>& Cells)
{
	// 유닛 이동 시 이동하는 경로를 표시
	// GridSubsystem의 함수를 호출하여 해당 위치에 ISM_CellDisplayState로 이동 경로인 Cell을 표시
}

// Called when mouse pointer clicked Cell
void AGridVisualizer::OnCellClickedHandler_Implementation(FIntVector CellCoord)
{
	SetCellDisplayState(CellCoord, ECellDisplayState::Selected);
}

// Called When mouse pointer clicked another cell while already selecting one Cell
void AGridVisualizer::OnCellClickExitedHandler_Implementation(FIntVector CellCoord)
{
	RemoveCellDisplayState(CellCoord, ECellDisplayState::Selected);
}

// Called when mouse pointer hovering on Cell
void AGridVisualizer::OnCellHoveredHandler_Implementation(FIntVector CellCoord)
{
	SetCellDisplayState(CellCoord, ECellDisplayState::Hovered);
}

// Called when mouse pointer exits from Cell
void AGridVisualizer::OnCellHoverExitedHandler_Implementation(FIntVector CellCoord)
{
	RemoveCellDisplayState(CellCoord, ECellDisplayState::Hovered);
}

void AGridVisualizer::OnUnitClickedHandler_Implementation(AActor* Unit)
{
	// 유닛 클릭 시
	FIntVector UnitCoord = Cast<IGridUnit>(Unit)->GetCellCoord();
	SetCellDisplayState(UnitCoord, ECellDisplayState::Selected);
}

void AGridVisualizer::UpdateGridMaterial_Implementation()
{
	
}

void AGridVisualizer::HandleActiveLayerChanged_Implementation(int32 NewLayer)
{
	
}

void AGridVisualizer::BindToGridManager()
{
	
}

void AGridVisualizer::UnbindFromGridManager()
{
	
}

void AGridVisualizer::InitializeDebugCoords_Implementation()
{
	if (!GridSubsystem)
	{
		GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("Grid Subsystem is NULL"));
		UE_LOG(LogTemp, Warning, TEXT("Grid Subsystem is NULL"));
		return;
	}
	if (DebugCellCoords.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, 
			TEXT("Debug Cell Coords TextRenderActors Array is Empty. Initialize Debug TextRenderActors..."))
		
		TArray<FIntVector> GridCellCoords;
		GridSubsystem->GetGridCellCoords(GridCellCoords);
	
		for (int i = 0; i < GridCellCoords.Num(); i++)
		{
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			ActorSpawnParams.Owner = this;
		
			ATextRenderActor* DebugCellCoord = GetWorld()->SpawnActor<ATextRenderActor>(
				GridSubsystem->CellCoordToWorldLocation(GridCellCoords[i]) 
					+ FVector(GridSubsystem->GetCellSize() * 0.5f, GridSubsystem->GetCellSize() * 0.5f, 10.f), 
				FRotator(90.f, 180.f, 0.f),
				ActorSpawnParams);
			DebugCellCoord->GetTextRender()->SetWorldSize(16.f);
			DebugCellCoord->SetActorEnableCollision(false);
			DebugCellCoord->GetTextRender()->Text = 
				FText::FromString(FString::Format(TEXT("X = {0}\nY = {1}\nZ = {2}"),
					{GridCellCoords[i].X, GridCellCoords[i].Y, GridCellCoords[i].Z }));
			DebugCellCoords.Add(DebugCellCoord);
		};
		
		bIsShowingDebugCoords = true;
	}
	
}

void AGridVisualizer::ToggleDebugCoords_Implementation()
{
	bIsShowingDebugCoords = !bIsShowingDebugCoords;
	for (int i = 0; i < DebugCellCoords.Num(); i++)
	{
		DebugCellCoords[i]->SetActorHiddenInGame(bIsShowingDebugCoords);
	}
}

void AGridVisualizer::ClearDebugCoords_Implementation()
{
	for (int i = DebugCellCoords.Num() - 1; i >= 0; i--)
	{
		DebugCellCoords.RemoveAt(i);
	}
	DebugCellCoords.Empty();
	bIsShowingDebugCoords = false;
}

void AGridVisualizer::InitializeDebugCoordsInEditor()
{
	if (!GridSubsystem)
	{
		GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("Grid Subsystem is NULL"));
		UE_LOG(LogTemp, Warning, TEXT("Grid Subsystem is NULL"));
		return;
	}
	InitializeDebugCoords();
}

void AGridVisualizer::ToggleDebugCoordsInEditor()
{
	ToggleDebugCoords();
}

void AGridVisualizer::ClearDebugCoordsInEditor()
{
	ClearDebugCoords();
}
