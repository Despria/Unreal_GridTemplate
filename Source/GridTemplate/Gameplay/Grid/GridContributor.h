// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GridContributor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UGridContributor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GRIDTEMPLATE_API IGridContributor
{
	GENERATED_BODY()

public:
	// 자신 아래에 있는 Cell들을 감지, 해당되는 범위의 Cell들을 반환
	UFUNCTION(Category = "Grid|Modifier")
	virtual TArray<FIntVector> GetAffectedCellCoords() = 0;
	
	// 자신의 변경 내용을 GridSettings에 적용
	UFUNCTION(Category = "Grid|Modifier")
	virtual bool Apply() = 0;
};
