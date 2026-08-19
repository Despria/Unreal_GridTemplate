// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridContributorBase.h"
#include "GridUnit.h"
#include "GameFramework/Actor.h"
#include "GridContributorUnitSpawn.generated.h"

UCLASS()
class GRIDTEMPLATE_API AGridContributorUnitSpawn : public AGridContributorBase
{
	GENERATED_BODY()
	
public:	
	AGridContributorUnitSpawn();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Build")
	TScriptInterface<IGridUnit> UnitToSpawn;
	
	virtual TArray<FIntVector> GetAffectedCellCoords() override;
	virtual bool Apply() override;

};
