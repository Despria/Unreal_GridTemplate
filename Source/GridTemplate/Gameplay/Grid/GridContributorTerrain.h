// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridContributorBase.h"
#include "GameFramework/Actor.h"
#include "GridContributorTerrain.generated.h"

UCLASS()
class GRIDTEMPLATE_API AGridContributorTerrain : public AGridContributorBase
{
	GENERATED_BODY()
	
public:	
	AGridContributorTerrain();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Build")
	TObjectPtr<UMaterialInterface> TerrainMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Build")
	TObjectPtr<UStaticMeshComponent> TerrainMesh;
	
	virtual TArray<FIntVector> GetAffectedCellCoords() override;
	virtual bool Apply() override;

};
