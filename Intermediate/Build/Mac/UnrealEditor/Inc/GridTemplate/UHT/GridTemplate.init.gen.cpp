// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridTemplate_init() {}
	GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature();
	GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature();
	GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature();
	GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnEnemyDied__DelegateSignature();
	GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature();
	GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature();
	GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature();
	GRIDTEMPLATE_API UFunction* Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GridTemplate;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GridTemplate()
	{
		if (!Z_Registration_Info_UPackage__Script_GridTemplate.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_GridTemplate_OnAttackRangeUpdated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GridTemplate_OnCellClicked__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GridTemplate_OnCellHovered__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GridTemplate_OnEnemyDied__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GridTemplate_OnMoveableRangeUpdated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GridTemplate_OnPathUpdated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GridTemplate_OnSelectionCleared__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GridTemplate_OnUnitClicked__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/GridTemplate",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x5EADE84C,
				0x5767C998,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GridTemplate.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_GridTemplate.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GridTemplate(Z_Construct_UPackage__Script_GridTemplate, TEXT("/Script/GridTemplate"), Z_Registration_Info_UPackage__Script_GridTemplate, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x5EADE84C, 0x5767C998));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
