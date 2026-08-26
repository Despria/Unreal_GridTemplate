// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "UObject/Interface.h"
#include "EquipmentItem.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEquipmentItem : public UItem
{
	GENERATED_BODY()
};

/**
 * 
 */
class GRIDTEMPLATE_API IEquipmentItem : public IItem
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
