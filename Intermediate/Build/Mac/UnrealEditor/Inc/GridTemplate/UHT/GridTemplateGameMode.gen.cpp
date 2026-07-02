// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GridTemplateGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeGridTemplateGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
GRIDTEMPLATE_API UClass* Z_Construct_UClass_AGridTemplateGameMode();
GRIDTEMPLATE_API UClass* Z_Construct_UClass_AGridTemplateGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_GridTemplate();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AGridTemplateGameMode ****************************************************
void AGridTemplateGameMode::StaticRegisterNativesAGridTemplateGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AGridTemplateGameMode;
UClass* AGridTemplateGameMode::GetPrivateStaticClass()
{
	using TClass = AGridTemplateGameMode;
	if (!Z_Registration_Info_UClass_AGridTemplateGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("GridTemplateGameMode"),
			Z_Registration_Info_UClass_AGridTemplateGameMode.InnerSingleton,
			StaticRegisterNativesAGridTemplateGameMode,
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
	return Z_Registration_Info_UClass_AGridTemplateGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AGridTemplateGameMode_NoRegister()
{
	return AGridTemplateGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AGridTemplateGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a third person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GridTemplateGameMode.h" },
		{ "ModuleRelativePath", "GridTemplateGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a third person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridTemplateGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGridTemplateGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_GridTemplate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridTemplateGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGridTemplateGameMode_Statics::ClassParams = {
	&AGridTemplateGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridTemplateGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AGridTemplateGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGridTemplateGameMode()
{
	if (!Z_Registration_Info_UClass_AGridTemplateGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGridTemplateGameMode.OuterSingleton, Z_Construct_UClass_AGridTemplateGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGridTemplateGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGridTemplateGameMode);
AGridTemplateGameMode::~AGridTemplateGameMode() {}
// ********** End Class AGridTemplateGameMode ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateGameMode_h__Script_GridTemplate_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGridTemplateGameMode, AGridTemplateGameMode::StaticClass, TEXT("AGridTemplateGameMode"), &Z_Registration_Info_UClass_AGridTemplateGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridTemplateGameMode), 137826387U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateGameMode_h__Script_GridTemplate_3114476123(TEXT("/Script/GridTemplate"),
	Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateGameMode_h__Script_GridTemplate_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateGameMode_h__Script_GridTemplate_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
