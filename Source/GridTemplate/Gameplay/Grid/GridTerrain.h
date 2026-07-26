// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridContributor.h"
#include "GameFramework/Actor.h"
#include "GridTerrain.generated.h"

UCLASS()
class GRIDTEMPLATE_API AGridTerrain : public AActor, public IGridContributor
{
	GENERATED_BODY()
	
public:	
	AGridTerrain();

protected:
	virtual void BeginPlay() override;

public:	
	virtual TArray<FIntVector> GetAffectedCellCoords() override;
	virtual bool Apply() override;

};
