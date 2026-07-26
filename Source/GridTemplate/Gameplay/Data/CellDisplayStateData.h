// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CellDisplayStateData.generated.h"

/**
 * Define DisplayState and Priority of Cell
 */
UENUM(BlueprintType, meta=(ScriptName="CellDisplayStateEnum"))
enum class ECellDisplayState: uint8
{
	Blank = 0,
	MoveRange = 1,
	Path = 2,
	EffectRange = 3,
	EffectArea = 4,
	Hovered = 5,
	Selected = 6
};

USTRUCT(BlueprintType)
struct FCellDisplayStateColor : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ECellDisplayState CellDisplayState = ECellDisplayState::Blank;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FColor CellDisplayColor = FColor::Green;
};

// Container of Cell DisplayState TArray and ISM ID
USTRUCT(BlueprintType)
struct FCellDisplayStateData
{
	GENERATED_BODY()
    
	FCellDisplayStateData() {};
	FCellDisplayStateData(ECellDisplayState CellDisplayState, int32 ID)
	{
		CellDisplayStates.Add(CellDisplayState);
		InstanceID = ID;
	};
    
	UPROPERTY(BlueprintReadWrite, Category = "Cell|Visuals")
	TArray<ECellDisplayState> CellDisplayStates;
    
	UPROPERTY(BlueprintReadOnly)
	int32 InstanceID = -1;
};
