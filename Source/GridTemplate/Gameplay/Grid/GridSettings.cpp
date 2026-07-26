// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridSettings.h"
#include "GridContributor.h"
#include "Kismet/GameplayStatics.h"

AGridSettings::AGridSettings()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGridSettings::BeginPlay()
{
	Super::BeginPlay();
}

void AGridSettings::BuildGridCellData()
{
	TArray<int32> Layers;
	LayerBaseHeights.GenerateKeyArray(Layers);
	for (int i = 0; i < Layers.Num(); i++)
	{
		for (int j = 0; j < GridYLength; j++)
		{
			for (int k = 0; k < GridXLength; k++)
			{
				FGridCellData GridCellData = FGridCellData();
				GridCellData.CellGridCoord = FIntVector(k, j, Layers[i]);
				
				GridCellData.CellWorldLocation = GridOrigin + FVector(k * CellSize, j * CellSize, LayerBaseHeights[Layers[i]]);
				// 각 셀의 위치마다 일정 거리만큼의 LineTrace를 수행하고, 이동 가능한 셀인지 판별하여 정보를 업데이트 해 주어야 함.
				// LineTrace 길이는 LayerBaseHeight를 참조하여 수행하면 될 듯.
				GridCells.Add(FIntVector(k, j, Layers[i]), GridCellData);
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
}
