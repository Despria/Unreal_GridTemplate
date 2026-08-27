// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/Grid/GridSettings.h"

#include "EditorAssetLibrary.h"
#include "GridTemplate.h"
#include "GridContributor.h"
#include "GridMath.h"
#include "Gameplay/Data/GridCellData.h"
#include "Kismet/GameplayStatics.h"

AGridSettings::AGridSettings()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGridSettings::BeginPlay()
{
	Super::BeginPlay();
	OnBuildGridCellData.Broadcast();
}

void AGridSettings::BuildGridCellData() const
{
	if (!GridCellBuildDataAsset)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("BuildGridCellData: GridCellBuildedDataAsset is NULL"));
		UE_LOG(LogTemp, Error, TEXT("BuildGridCellData: GridCellBuildedDataAsset is NULL"));
		return;
	}
	if (!GridCellBuildDataAsset->GridCells.IsEmpty())
	{
		GEngine->AddOnScreenDebugMessage(-2, 5.0f, FColor::Red, 
			TEXT("BuildGridCellData: GridCellBuildedDataAsset is NOT EMPTY. Please Run DisposeGridCellData first."));
		UE_LOG(LogTemp, Error, 
			TEXT("BuildGridCellData: GridCellBuildedDataAsset is NOT EMPTY. Please Run DisposeGridCellData first."));
		return;
	}
	
	TMap<FIntVector, FGridCellData> GridCells = TMap<FIntVector, FGridCellData>()
	;
	TArray<int32> Layers;
	LayerBaseHeights.GenerateKeyArray(Layers);
	for (int i = 0; i < Layers.Num(); i++)
	{
		for (int j = 0; j < GridYLength; j++)
		{
			for (int k = 0; k < GridXLength; k++)
			{
				FIntVector CellCoordOnGrid = FIntVector(k, j, Layers[i]);
				
				FGridCellData GridCellData = FGridCellData();
				GridCellData.CellGridCoord = CellCoordOnGrid;
				GridCellData.CellWorldLocation = UGridMath::CellCoordToWorldLocation(
					GridCellData.CellGridCoord, GridOrigin, CellSize, LayerBaseHeights);
				
				// 각 셀의 위치마다 일정 거리만큼의 LineTrace를 수행하고, 이동 가능한 셀인지 판별하여 정보를 업데이트 해 주어야 함.
				FCollisionQueryParams CollisionQueryParams;
				CollisionQueryParams.AddIgnoredActor(this);
				FVector GridCellCenterLocation = 
					UGridMath::CellCenterToWorldLocation(GridCellData.CellGridCoord, GridOrigin, CellSize, LayerBaseHeights);
				FVector StartLocation = GridCellCenterLocation + FVector(0, 0, WalkableTraceDistance);
				FVector EndLocation = GridCellCenterLocation - FVector(0, 0, WalkableTraceDistance);
				FHitResult HitResult;
				
				GetWorld()->LineTraceSingleByChannel(
					HitResult,
					StartLocation,
					EndLocation,
					COLLISION_GRID,
					CollisionQueryParams
				);
				if (!HitResult.bBlockingHit) GridCellData.TerrainType = ETerrainType::Air;
				UE_LOG(LogTemp, Warning, TEXT("Grid Traced!"));
				
				GridCells.Add(CellCoordOnGrid, GridCellData);
			}
		}
	}
	
	TArray<AActor*> Contributors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UGridContributor::StaticClass(), Contributors);
	
	for (AActor* Actor : Contributors)
	{
		if (IGridContributor* Contributor = Cast<IGridContributor>(Actor))
		{
			Contributor->Apply();
		}
	}

#if WITH_EDITOR
	GridCellBuildDataAsset->Modify();

	GridCellBuildDataAsset->GridCells = GridCells;
	GridCellBuildDataAsset->CellSize = CellSize;
	GridCellBuildDataAsset->GridXLength = GridXLength;
	GridCellBuildDataAsset->GridYLength = GridYLength;
	GridCellBuildDataAsset->GridOrigin = GridOrigin;
	GridCellBuildDataAsset->LayerBaseHeights = LayerBaseHeights;

	if (GridCellBuildDataAsset->MarkPackageDirty())
	{
		UEditorAssetLibrary::SaveLoadedAsset(GridCellBuildDataAsset, /*bOnlyIfIsDirty=*/false);
		UE_LOG(LogTemp, Log, TEXT("GridCellBuildDataAsset saved."));
	}
#endif
}

void AGridSettings::DisposeGridCellData() const
{
	if (!GridCellBuildDataAsset->GridCells.IsEmpty())
		GridCellBuildDataAsset->GridCells.Empty();
}
