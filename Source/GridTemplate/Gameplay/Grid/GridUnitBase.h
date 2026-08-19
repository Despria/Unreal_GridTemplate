// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridUnit.h"
#include "GameFramework/Actor.h"
#include "Gameplay/Data/UnitBaseStatDataAsset.h"
#include "GridUnitBase.generated.h"

UCLASS(Abstract)
class GRIDTEMPLATE_API AGridUnitBase : public AActor, public IGridUnit
{
	GENERATED_BODY()
	
public:
	AGridUnitBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Unit|Status")
	TObjectPtr<UUnitBaseStatDataAsset> UnitBaseStatDataAsset = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category="Unit|Status")
	FUnitBaseStatData UnitBaseStatData = FUnitBaseStatData();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Unit|Interaction")
	bool bIsInteractable = true;
	
public:
	virtual FIntVector GetCellCoord() const override;
	virtual int32 GetMovementPoints() const override;
	virtual bool IsDiagonalMovable() const override;
	virtual bool IsInteractable() const override;
	
protected:
	virtual void InitializeUnit();
};
