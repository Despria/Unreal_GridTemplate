// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Gameplay/Data/CellDisplayStateData.h"
#include "CellDisplayStateColorAsset.generated.h"

/**
 * 
 */
UCLASS()
class GRIDTEMPLATE_API UCellDisplayStateColorAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell|Visuals")
	TMap<ECellDisplayState, FColor> CellDisplayColorMap;
};
