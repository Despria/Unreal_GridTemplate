// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GridUnit.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UGridUnit : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface for Units exist on Grid
 */
class GRIDTEMPLATE_API IGridUnit
{
	GENERATED_BODY()

public:
	// 현재 점유 중인 셀 좌표
	UFUNCTION(Category = "Grid|Unit")
	virtual FIntVector GetCellCoord() const;

	// 이동력 (이동 불가 오브젝트는 0 반환)
	UFUNCTION(Category = "Grid|Unit|Movement")
	virtual int32 GetMovementPoints() const;
	
	UFUNCTION(Category = "Grid|Unit|Movement")
	virtual bool IsDiagonalMovable() const;

	// 상호작용 가능 여부
	UFUNCTION(Category = "Grid|Unit")
	virtual bool IsInteractable() const;
};
