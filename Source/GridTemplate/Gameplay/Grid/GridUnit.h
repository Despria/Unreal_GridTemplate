// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GridUnit.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UGridUnit : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GRIDTEMPLATE_API IGridUnit
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// 현재 점유 중인 셀 좌표
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GridUnit")
	FIntVector GetCellCoord() const;

	// 이동력 (이동 불가 오브젝트는 0 반환)
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GridUnit")
	int32 GetMovementPoints() const;

	// 상호작용 가능 여부
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GridUnit")
	bool IsInteractable() const;
};
