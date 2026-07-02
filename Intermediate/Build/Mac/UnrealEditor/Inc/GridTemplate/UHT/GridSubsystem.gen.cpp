// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Gameplay/Subsystem/GridSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeGridSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
GRIDTEMPLATE_API UClass* Z_Construct_UClass_UGridSubsystem();
GRIDTEMPLATE_API UClass* Z_Construct_UClass_UGridSubsystem_NoRegister();
GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature();
GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature();
GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature();
GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature();
GRIDTEMPLATE_API UScriptStruct* Z_Construct_UScriptStruct_FGridCellData();
UPackage* Z_Construct_UPackage__Script_GridTemplate();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FGridCellData *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGridCellData;
class UScriptStruct* FGridCellData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGridCellData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGridCellData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGridCellData, (UObject*)Z_Construct_UPackage__Script_GridTemplate(), TEXT("GridCellData"));
	}
	return Z_Registration_Info_UScriptStruct_FGridCellData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FGridCellData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridCoord_MetaData[] = {
		{ "Category", "GridCellData" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldCenter_MetaData[] = {
		{ "Category", "GridCellData" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsWalkable_MetaData[] = {
		{ "Category", "GridCellData" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
		{ "Category", "GridCellData" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridCoord;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldCenter;
	static void NewProp_bIsWalkable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsWalkable;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGridCellData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_GridCoord = { "GridCoord", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGridCellData, GridCoord), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridCoord_MetaData), NewProp_GridCoord_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_WorldCenter = { "WorldCenter", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGridCellData, WorldCenter), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldCenter_MetaData), NewProp_WorldCenter_MetaData) };
void Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_bIsWalkable_SetBit(void* Obj)
{
	((FGridCellData*)Obj)->bIsWalkable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_bIsWalkable = { "bIsWalkable", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FGridCellData), &Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_bIsWalkable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsWalkable_MetaData), NewProp_bIsWalkable_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGridCellData, Height), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Height_MetaData), NewProp_Height_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGridCellData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_GridCoord,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_WorldCenter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_bIsWalkable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCellData_Statics::NewProp_Height,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGridCellData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGridCellData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GridTemplate,
	nullptr,
	&NewStructOps,
	"GridCellData",
	Z_Construct_UScriptStruct_FGridCellData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGridCellData_Statics::PropPointers),
	sizeof(FGridCellData),
	alignof(FGridCellData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGridCellData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGridCellData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGridCellData()
{
	if (!Z_Registration_Info_UScriptStruct_FGridCellData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGridCellData.InnerSingleton, Z_Construct_UScriptStruct_FGridCellData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FGridCellData.InnerSingleton;
}
// ********** End ScriptStruct FGridCellData *******************************************************

// ********** Begin Delegate FOnMoveableRangeUpdated ***********************************************
struct Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics
{
	struct _Script_GridTemplate_eventOnMoveableRangeUpdated_Parms
	{
		TArray<FVector2D> Cells;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Cells_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Cells_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Cells;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::NewProp_Cells_Inner = { "Cells", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::NewProp_Cells = { "Cells", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GridTemplate_eventOnMoveableRangeUpdated_Parms, Cells), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Cells_MetaData), NewProp_Cells_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::NewProp_Cells_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::NewProp_Cells,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GridTemplate, nullptr, "OnMoveableRangeUpdated__DelegateSignature", Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::_Script_GridTemplate_eventOnMoveableRangeUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::_Script_GridTemplate_eventOnMoveableRangeUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnMoveableRangeUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnMoveableRangeUpdated, TArray<FVector2D> const& Cells)
{
	struct _Script_GridTemplate_eventOnMoveableRangeUpdated_Parms
	{
		TArray<FVector2D> Cells;
	};
	_Script_GridTemplate_eventOnMoveableRangeUpdated_Parms Parms;
	Parms.Cells=Cells;
	OnMoveableRangeUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnMoveableRangeUpdated *************************************************

// ********** Begin Delegate FOnAttackRangeUpdated *************************************************
struct Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics
{
	struct _Script_GridTemplate_eventOnAttackRangeUpdated_Parms
	{
		TArray<FVector2D> Cells;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Cells_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Cells_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Cells;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::NewProp_Cells_Inner = { "Cells", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::NewProp_Cells = { "Cells", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GridTemplate_eventOnAttackRangeUpdated_Parms, Cells), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Cells_MetaData), NewProp_Cells_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::NewProp_Cells_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::NewProp_Cells,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GridTemplate, nullptr, "OnAttackRangeUpdated__DelegateSignature", Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::_Script_GridTemplate_eventOnAttackRangeUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::_Script_GridTemplate_eventOnAttackRangeUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAttackRangeUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnAttackRangeUpdated, TArray<FVector2D> const& Cells)
{
	struct _Script_GridTemplate_eventOnAttackRangeUpdated_Parms
	{
		TArray<FVector2D> Cells;
	};
	_Script_GridTemplate_eventOnAttackRangeUpdated_Parms Parms;
	Parms.Cells=Cells;
	OnAttackRangeUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnAttackRangeUpdated ***************************************************

// ********** Begin Delegate FOnPathUpdated ********************************************************
struct Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics
{
	struct _Script_GridTemplate_eventOnPathUpdated_Parms
	{
		TArray<FVector2D> Cells;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Cells_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Cells_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Cells;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::NewProp_Cells_Inner = { "Cells", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::NewProp_Cells = { "Cells", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GridTemplate_eventOnPathUpdated_Parms, Cells), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Cells_MetaData), NewProp_Cells_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::NewProp_Cells_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::NewProp_Cells,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GridTemplate, nullptr, "OnPathUpdated__DelegateSignature", Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::_Script_GridTemplate_eventOnPathUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::_Script_GridTemplate_eventOnPathUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPathUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnPathUpdated, TArray<FVector2D> const& Cells)
{
	struct _Script_GridTemplate_eventOnPathUpdated_Parms
	{
		TArray<FVector2D> Cells;
	};
	_Script_GridTemplate_eventOnPathUpdated_Parms Parms;
	Parms.Cells=Cells;
	OnPathUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnPathUpdated **********************************************************

// ********** Begin Delegate FOnSelectionCleared ***************************************************
struct Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GridTemplate, nullptr, "OnSelectionCleared__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSelectionCleared_DelegateWrapper(const FMulticastScriptDelegate& OnSelectionCleared)
{
	OnSelectionCleared.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnSelectionCleared *****************************************************

// ********** Begin Class UGridSubsystem Function GetAllCellCoords *********************************
struct GridSubsystem_eventGetAllCellCoords_Parms
{
	TArray<FVector2D> ReturnValue;
};
static FName NAME_UGridSubsystem_GetAllCellCoords = FName(TEXT("GetAllCellCoords"));
TArray<FVector2D> UGridSubsystem::GetAllCellCoords() const
{
	UFunction* Func = FindFunctionChecked(NAME_UGridSubsystem_GetAllCellCoords);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GridSubsystem_eventGetAllCellCoords_Parms Parms;
		const_cast<UGridSubsystem*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UGridSubsystem*>(this)->GetAllCellCoords_Implementation();
	}
}
struct Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridSubsystem_eventGetAllCellCoords_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGridSubsystem, nullptr, "GetAllCellCoords", Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::PropPointers), sizeof(GridSubsystem_eventGetAllCellCoords_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GridSubsystem_eventGetAllCellCoords_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGridSubsystem::execGetAllCellCoords)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FVector2D>*)Z_Param__Result=P_THIS->GetAllCellCoords_Implementation();
	P_NATIVE_END;
}
// ********** End Class UGridSubsystem Function GetAllCellCoords ***********************************

// ********** Begin Class UGridSubsystem Function GridToWorldCenter ********************************
struct GridSubsystem_eventGridToWorldCenter_Parms
{
	FVector2D GridCoord;
	FVector ReturnValue;

	/** Constructor, initializes return property only **/
	GridSubsystem_eventGridToWorldCenter_Parms()
		: ReturnValue(ForceInit)
	{
	}
};
static FName NAME_UGridSubsystem_GridToWorldCenter = FName(TEXT("GridToWorldCenter"));
FVector UGridSubsystem::GridToWorldCenter(FVector2D GridCoord) const
{
	UFunction* Func = FindFunctionChecked(NAME_UGridSubsystem_GridToWorldCenter);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GridSubsystem_eventGridToWorldCenter_Parms Parms;
		Parms.GridCoord=GridCoord;
		const_cast<UGridSubsystem*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UGridSubsystem*>(this)->GridToWorldCenter_Implementation(GridCoord);
	}
}
struct Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridCoord;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::NewProp_GridCoord = { "GridCoord", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridSubsystem_eventGridToWorldCenter_Parms, GridCoord), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridSubsystem_eventGridToWorldCenter_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::NewProp_GridCoord,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGridSubsystem, nullptr, "GridToWorldCenter", Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::PropPointers), sizeof(GridSubsystem_eventGridToWorldCenter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C820C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GridSubsystem_eventGridToWorldCenter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGridSubsystem::execGridToWorldCenter)
{
	P_GET_STRUCT(FVector2D,Z_Param_GridCoord);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GridToWorldCenter_Implementation(Z_Param_GridCoord);
	P_NATIVE_END;
}
// ********** End Class UGridSubsystem Function GridToWorldCenter **********************************

// ********** Begin Class UGridSubsystem Function InitializeGrid ***********************************
static FName NAME_UGridSubsystem_InitializeGrid = FName(TEXT("InitializeGrid"));
void UGridSubsystem::InitializeGrid()
{
	UFunction* Func = FindFunctionChecked(NAME_UGridSubsystem_InitializeGrid);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		InitializeGrid_Implementation();
	}
}
struct Z_Construct_UFunction_UGridSubsystem_InitializeGrid_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridSubsystem_InitializeGrid_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGridSubsystem, nullptr, "InitializeGrid", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_InitializeGrid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGridSubsystem_InitializeGrid_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGridSubsystem_InitializeGrid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGridSubsystem_InitializeGrid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGridSubsystem::execInitializeGrid)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeGrid_Implementation();
	P_NATIVE_END;
}
// ********** End Class UGridSubsystem Function InitializeGrid *************************************

// ********** Begin Class UGridSubsystem Function IsValidCell **************************************
struct GridSubsystem_eventIsValidCell_Parms
{
	FVector2D GridCoord;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	GridSubsystem_eventIsValidCell_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UGridSubsystem_IsValidCell = FName(TEXT("IsValidCell"));
bool UGridSubsystem::IsValidCell(FVector2D GridCoord) const
{
	UFunction* Func = FindFunctionChecked(NAME_UGridSubsystem_IsValidCell);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GridSubsystem_eventIsValidCell_Parms Parms;
		Parms.GridCoord=GridCoord;
		const_cast<UGridSubsystem*>(this)->ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UGridSubsystem*>(this)->IsValidCell_Implementation(GridCoord);
	}
}
struct Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridCoord;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::NewProp_GridCoord = { "GridCoord", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridSubsystem_eventIsValidCell_Parms, GridCoord), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GridSubsystem_eventIsValidCell_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GridSubsystem_eventIsValidCell_Parms), &Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::NewProp_GridCoord,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGridSubsystem, nullptr, "IsValidCell", Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::PropPointers), sizeof(GridSubsystem_eventIsValidCell_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C820C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GridSubsystem_eventIsValidCell_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGridSubsystem_IsValidCell()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGridSubsystem_IsValidCell_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGridSubsystem::execIsValidCell)
{
	P_GET_STRUCT(FVector2D,Z_Param_GridCoord);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsValidCell_Implementation(Z_Param_GridCoord);
	P_NATIVE_END;
}
// ********** End Class UGridSubsystem Function IsValidCell ****************************************

// ********** Begin Class UGridSubsystem Function WorldToGrid **************************************
struct GridSubsystem_eventWorldToGrid_Parms
{
	FVector WorldLocation;
	FVector2D ReturnValue;

	/** Constructor, initializes return property only **/
	GridSubsystem_eventWorldToGrid_Parms()
		: ReturnValue(ForceInit)
	{
	}
};
static FName NAME_UGridSubsystem_WorldToGrid = FName(TEXT("WorldToGrid"));
FVector2D UGridSubsystem::WorldToGrid(FVector WorldLocation) const
{
	UFunction* Func = FindFunctionChecked(NAME_UGridSubsystem_WorldToGrid);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GridSubsystem_eventWorldToGrid_Parms Parms;
		Parms.WorldLocation=WorldLocation;
		const_cast<UGridSubsystem*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UGridSubsystem*>(this)->WorldToGrid_Implementation(WorldLocation);
	}
}
struct Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridSubsystem_eventWorldToGrid_Parms, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridSubsystem_eventWorldToGrid_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::NewProp_WorldLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGridSubsystem, nullptr, "WorldToGrid", Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::PropPointers), sizeof(GridSubsystem_eventWorldToGrid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C820C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GridSubsystem_eventWorldToGrid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGridSubsystem_WorldToGrid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGridSubsystem_WorldToGrid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGridSubsystem::execWorldToGrid)
{
	P_GET_STRUCT(FVector,Z_Param_WorldLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=P_THIS->WorldToGrid_Implementation(Z_Param_WorldLocation);
	P_NATIVE_END;
}
// ********** End Class UGridSubsystem Function WorldToGrid ****************************************

// ********** Begin Class UGridSubsystem ***********************************************************
void UGridSubsystem::StaticRegisterNativesUGridSubsystem()
{
	UClass* Class = UGridSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAllCellCoords", &UGridSubsystem::execGetAllCellCoords },
		{ "GridToWorldCenter", &UGridSubsystem::execGridToWorldCenter },
		{ "InitializeGrid", &UGridSubsystem::execInitializeGrid },
		{ "IsValidCell", &UGridSubsystem::execIsValidCell },
		{ "WorldToGrid", &UGridSubsystem::execWorldToGrid },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UGridSubsystem;
UClass* UGridSubsystem::GetPrivateStaticClass()
{
	using TClass = UGridSubsystem;
	if (!Z_Registration_Info_UClass_UGridSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("GridSubsystem"),
			Z_Registration_Info_UClass_UGridSubsystem.InnerSingleton,
			StaticRegisterNativesUGridSubsystem,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UGridSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UGridSubsystem_NoRegister()
{
	return UGridSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGridSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Grid Subsystem which manages Logical Grid and calculations about grid, ex) A* Pathfinding.\n */" },
#endif
		{ "IncludePath", "Gameplay/Subsystem/GridSubsystem.h" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid Subsystem which manages Logical Grid and calculations about grid, ex) A* Pathfinding." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridWidth_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridHeight_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridOrigin_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMoveableRangeUpdated_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAttackRangeUpdated_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPathUpdated_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSelectionCleared_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Gameplay/Subsystem/GridSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridHeight;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridOrigin;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMoveableRangeUpdated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAttackRangeUpdated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPathUpdated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSelectionCleared;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGridSubsystem_GetAllCellCoords, "GetAllCellCoords" }, // 1614443543
		{ &Z_Construct_UFunction_UGridSubsystem_GridToWorldCenter, "GridToWorldCenter" }, // 2847967306
		{ &Z_Construct_UFunction_UGridSubsystem_InitializeGrid, "InitializeGrid" }, // 1404516451
		{ &Z_Construct_UFunction_UGridSubsystem_IsValidCell, "IsValidCell" }, // 2721791155
		{ &Z_Construct_UFunction_UGridSubsystem_WorldToGrid, "WorldToGrid" }, // 370599597
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGridSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGridSubsystem_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridSubsystem, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGridSubsystem_Statics::NewProp_GridWidth = { "GridWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridSubsystem, GridWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridWidth_MetaData), NewProp_GridWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGridSubsystem_Statics::NewProp_GridHeight = { "GridHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridSubsystem, GridHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridHeight_MetaData), NewProp_GridHeight_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGridSubsystem_Statics::NewProp_GridOrigin = { "GridOrigin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridSubsystem, GridOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridOrigin_MetaData), NewProp_GridOrigin_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGridSubsystem_Statics::NewProp_OnMoveableRangeUpdated = { "OnMoveableRangeUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridSubsystem, OnMoveableRangeUpdated), Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMoveableRangeUpdated_MetaData), NewProp_OnMoveableRangeUpdated_MetaData) }; // 417107141
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGridSubsystem_Statics::NewProp_OnAttackRangeUpdated = { "OnAttackRangeUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridSubsystem, OnAttackRangeUpdated), Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAttackRangeUpdated_MetaData), NewProp_OnAttackRangeUpdated_MetaData) }; // 3907518694
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGridSubsystem_Statics::NewProp_OnPathUpdated = { "OnPathUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridSubsystem, OnPathUpdated), Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPathUpdated_MetaData), NewProp_OnPathUpdated_MetaData) }; // 2082672429
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGridSubsystem_Statics::NewProp_OnSelectionCleared = { "OnSelectionCleared", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridSubsystem, OnSelectionCleared), Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSelectionCleared_MetaData), NewProp_OnSelectionCleared_MetaData) }; // 736734861
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGridSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridSubsystem_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridSubsystem_Statics::NewProp_GridWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridSubsystem_Statics::NewProp_GridHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridSubsystem_Statics::NewProp_GridOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridSubsystem_Statics::NewProp_OnMoveableRangeUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridSubsystem_Statics::NewProp_OnAttackRangeUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridSubsystem_Statics::NewProp_OnPathUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridSubsystem_Statics::NewProp_OnSelectionCleared,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGridSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UGridSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GridTemplate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGridSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGridSubsystem_Statics::ClassParams = {
	&UGridSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGridSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGridSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGridSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGridSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGridSubsystem()
{
	if (!Z_Registration_Info_UClass_UGridSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGridSubsystem.OuterSingleton, Z_Construct_UClass_UGridSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGridSubsystem.OuterSingleton;
}
UGridSubsystem::UGridSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGridSubsystem);
UGridSubsystem::~UGridSubsystem() {}
// ********** End Class UGridSubsystem *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h__Script_GridTemplate_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGridCellData::StaticStruct, Z_Construct_UScriptStruct_FGridCellData_Statics::NewStructOps, TEXT("GridCellData"), &Z_Registration_Info_UScriptStruct_FGridCellData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGridCellData), 3873657498U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGridSubsystem, UGridSubsystem::StaticClass, TEXT("UGridSubsystem"), &Z_Registration_Info_UClass_UGridSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGridSubsystem), 2577021811U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h__Script_GridTemplate_4143098701(TEXT("/Script/GridTemplate"),
	Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h__Script_GridTemplate_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h__Script_GridTemplate_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h__Script_GridTemplate_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h__Script_GridTemplate_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
