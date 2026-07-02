// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GridTemplatePlayerController.h"

#ifdef GRIDTEMPLATE_GridTemplatePlayerController_generated_h
#error "GridTemplatePlayerController.generated.h already included, missing '#pragma once' in GridTemplatePlayerController.h"
#endif
#define GRIDTEMPLATE_GridTemplatePlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AGridTemplatePlayerController ********************************************
GRIDTEMPLATE_API UClass* Z_Construct_UClass_AGridTemplatePlayerController_NoRegister();

#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplatePlayerController_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGridTemplatePlayerController(); \
	friend struct Z_Construct_UClass_AGridTemplatePlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GRIDTEMPLATE_API UClass* Z_Construct_UClass_AGridTemplatePlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AGridTemplatePlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/GridTemplate"), Z_Construct_UClass_AGridTemplatePlayerController_NoRegister) \
	DECLARE_SERIALIZER(AGridTemplatePlayerController)


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplatePlayerController_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGridTemplatePlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGridTemplatePlayerController(AGridTemplatePlayerController&&) = delete; \
	AGridTemplatePlayerController(const AGridTemplatePlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGridTemplatePlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGridTemplatePlayerController); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGridTemplatePlayerController) \
	NO_API virtual ~AGridTemplatePlayerController();


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplatePlayerController_h_16_PROLOG
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplatePlayerController_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplatePlayerController_h_19_INCLASS_NO_PURE_DECLS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplatePlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGridTemplatePlayerController;

// ********** End Class AGridTemplatePlayerController **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplatePlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
