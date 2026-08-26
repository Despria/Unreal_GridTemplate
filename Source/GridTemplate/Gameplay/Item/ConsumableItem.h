// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "UObject/Interface.h"
#include "ConsumableItem.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConsumableItem : public UItem
{
	GENERATED_BODY()
};

/**
 * 
 */
class GRIDTEMPLATE_API IConsumableItem : public IItem
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
