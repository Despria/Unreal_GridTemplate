// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitBaseStatDataAsset.h"
#include "UnitBaseStatData.generated.h"

USTRUCT(BlueprintType)
struct FUnitManaTypeData : public FUnitBaseStatData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Unit|Status|Combat")
	int32 BaseManaPoint = 0;
};

USTRUCT(BlueprintType)
struct FUnitStaminaTypeData : public FUnitBaseStatData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Unit|Status|Combat")
	int32 BaseStaminaPoint = 0;
};
