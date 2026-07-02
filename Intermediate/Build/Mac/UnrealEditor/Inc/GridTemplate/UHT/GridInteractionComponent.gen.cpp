// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Gameplay/ActorComponent/GridInteractionComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeGridInteractionComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
GRIDTEMPLATE_API UClass* Z_Construct_UClass_UGridInteractionComponent();
GRIDTEMPLATE_API UClass* Z_Construct_UClass_UGridInteractionComponent_NoRegister();
GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature();
GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature();
GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_GridTemplate();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnCellClicked ********************************************************
struct Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics
{
	struct _Script_GridTemplate_eventOnCellClicked_Parms
	{
		FVector2D GridCoord;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Gameplay/ActorComponent/GridInteractionComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridCoord;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::NewProp_GridCoord = { "GridCoord", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GridTemplate_eventOnCellClicked_Parms, GridCoord), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::NewProp_GridCoord,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GridTemplate, nullptr, "OnCellClicked__DelegateSignature", Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::_Script_GridTemplate_eventOnCellClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::_Script_GridTemplate_eventOnCellClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCellClicked_DelegateWrapper(const FMulticastScriptDelegate& OnCellClicked, FVector2D GridCoord)
{
	struct _Script_GridTemplate_eventOnCellClicked_Parms
	{
		FVector2D GridCoord;
	};
	_Script_GridTemplate_eventOnCellClicked_Parms Parms;
	Parms.GridCoord=GridCoord;
	OnCellClicked.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCellClicked **********************************************************

// ********** Begin Delegate FOnCellHovered ********************************************************
struct Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics
{
	struct _Script_GridTemplate_eventOnCellHovered_Parms
	{
		FVector2D GridCoord;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Gameplay/ActorComponent/GridInteractionComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridCoord;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::NewProp_GridCoord = { "GridCoord", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GridTemplate_eventOnCellHovered_Parms, GridCoord), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::NewProp_GridCoord,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GridTemplate, nullptr, "OnCellHovered__DelegateSignature", Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::_Script_GridTemplate_eventOnCellHovered_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::_Script_GridTemplate_eventOnCellHovered_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCellHovered_DelegateWrapper(const FMulticastScriptDelegate& OnCellHovered, FVector2D GridCoord)
{
	struct _Script_GridTemplate_eventOnCellHovered_Parms
	{
		FVector2D GridCoord;
	};
	_Script_GridTemplate_eventOnCellHovered_Parms Parms;
	Parms.GridCoord=GridCoord;
	OnCellHovered.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCellHovered **********************************************************

// ********** Begin Delegate FOnUnitClicked ********************************************************
struct Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics
{
	struct _Script_GridTemplate_eventOnUnitClicked_Parms
	{
		AActor* HitActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Gameplay/ActorComponent/GridInteractionComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::NewProp_HitActor = { "HitActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GridTemplate_eventOnUnitClicked_Parms, HitActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::NewProp_HitActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GridTemplate, nullptr, "OnUnitClicked__DelegateSignature", Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::_Script_GridTemplate_eventOnUnitClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::_Script_GridTemplate_eventOnUnitClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnUnitClicked_DelegateWrapper(const FMulticastScriptDelegate& OnUnitClicked, AActor* HitActor)
{
	struct _Script_GridTemplate_eventOnUnitClicked_Parms
	{
		AActor* HitActor;
	};
	_Script_GridTemplate_eventOnUnitClicked_Parms Parms;
	Parms.HitActor=HitActor;
	OnUnitClicked.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnUnitClicked **********************************************************

// ********** Begin Class UGridInteractionComponent Function PerformTrace **************************
static FName NAME_UGridInteractionComponent_PerformTrace = FName(TEXT("PerformTrace"));
void UGridInteractionComponent::PerformTrace()
{
	UFunction* Func = FindFunctionChecked(NAME_UGridInteractionComponent_PerformTrace);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		PerformTrace_Implementation();
	}
}
struct Z_Construct_UFunction_UGridInteractionComponent_PerformTrace_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Interaction|Events" },
		{ "ModuleRelativePath", "Gameplay/ActorComponent/GridInteractionComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridInteractionComponent_PerformTrace_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGridInteractionComponent, nullptr, "PerformTrace", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGridInteractionComponent_PerformTrace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGridInteractionComponent_PerformTrace_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGridInteractionComponent_PerformTrace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGridInteractionComponent_PerformTrace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGridInteractionComponent::execPerformTrace)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PerformTrace_Implementation();
	P_NATIVE_END;
}
// ********** End Class UGridInteractionComponent Function PerformTrace ****************************

// ********** Begin Class UGridInteractionComponent ************************************************
void UGridInteractionComponent::StaticRegisterNativesUGridInteractionComponent()
{
	UClass* Class = UGridInteractionComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "PerformTrace", &UGridInteractionComponent::execPerformTrace },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UGridInteractionComponent;
UClass* UGridInteractionComponent::GetPrivateStaticClass()
{
	using TClass = UGridInteractionComponent;
	if (!Z_Registration_Info_UClass_UGridInteractionComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("GridInteractionComponent"),
			Z_Registration_Info_UClass_UGridInteractionComponent.InnerSingleton,
			StaticRegisterNativesUGridInteractionComponent,
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
	return Z_Registration_Info_UClass_UGridInteractionComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UGridInteractionComponent_NoRegister()
{
	return UGridInteractionComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGridInteractionComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Gameplay/ActorComponent/GridInteractionComponent.h" },
		{ "ModuleRelativePath", "Gameplay/ActorComponent/GridInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCellClicked_MetaData[] = {
		{ "Category", "Interaction|Events" },
		{ "ModuleRelativePath", "Gameplay/ActorComponent/GridInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCellHovered_MetaData[] = {
		{ "Category", "Interaction|Events" },
		{ "ModuleRelativePath", "Gameplay/ActorComponent/GridInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnUnitClicked_MetaData[] = {
		{ "Category", "Interaction|Events" },
		{ "ModuleRelativePath", "Gameplay/ActorComponent/GridInteractionComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCellClicked;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCellHovered;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnUnitClicked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGridInteractionComponent_PerformTrace, "PerformTrace" }, // 3519930701
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGridInteractionComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGridInteractionComponent_Statics::NewProp_OnCellClicked = { "OnCellClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridInteractionComponent, OnCellClicked), Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCellClicked_MetaData), NewProp_OnCellClicked_MetaData) }; // 475464938
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGridInteractionComponent_Statics::NewProp_OnCellHovered = { "OnCellHovered", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridInteractionComponent, OnCellHovered), Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCellHovered_MetaData), NewProp_OnCellHovered_MetaData) }; // 2392239083
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGridInteractionComponent_Statics::NewProp_OnUnitClicked = { "OnUnitClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridInteractionComponent, OnUnitClicked), Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnUnitClicked_MetaData), NewProp_OnUnitClicked_MetaData) }; // 1696674389
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGridInteractionComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridInteractionComponent_Statics::NewProp_OnCellClicked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridInteractionComponent_Statics::NewProp_OnCellHovered,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridInteractionComponent_Statics::NewProp_OnUnitClicked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGridInteractionComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UGridInteractionComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_GridTemplate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGridInteractionComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGridInteractionComponent_Statics::ClassParams = {
	&UGridInteractionComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGridInteractionComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGridInteractionComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGridInteractionComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UGridInteractionComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGridInteractionComponent()
{
	if (!Z_Registration_Info_UClass_UGridInteractionComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGridInteractionComponent.OuterSingleton, Z_Construct_UClass_UGridInteractionComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGridInteractionComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGridInteractionComponent);
UGridInteractionComponent::~UGridInteractionComponent() {}
// ********** End Class UGridInteractionComponent **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h__Script_GridTemplate_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGridInteractionComponent, UGridInteractionComponent::StaticClass, TEXT("UGridInteractionComponent"), &Z_Registration_Info_UClass_UGridInteractionComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGridInteractionComponent), 1666674602U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h__Script_GridTemplate_3993096564(TEXT("/Script/GridTemplate"),
	Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h__Script_GridTemplate_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h__Script_GridTemplate_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
