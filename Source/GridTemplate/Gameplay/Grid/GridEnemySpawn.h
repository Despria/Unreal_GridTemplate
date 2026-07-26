// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridContributor.h"
#include "GameFramework/Actor.h"
#include "GridEnemySpawn.generated.h"

UCLASS()
class GRIDTEMPLATE_API AGridEnemySpawn : public AActor, public IGridContributor
{
	GENERATED_BODY()
	
public:	
	AGridEnemySpawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual TArray<FIntVector> GetAffectedCellCoords() override;
	virtual bool Apply() override;

};
