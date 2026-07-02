// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Gameplay/PlayerController/GridPlayerController.h"

#ifdef GRIDTEMPLATE_GridPlayerController_generated_h
#error "GridPlayerController.generated.h already included, missing '#pragma once' in GridPlayerController.h"
#endif
#define GRIDTEMPLATE_GridPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AGridPlayerController ****************************************************
GRIDTEMPLATE_API UClass* Z_Construct_UClass_AGridPlayerController_NoRegister();

#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_PlayerController_GridPlayerController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGridPlayerController(); \
	friend struct Z_Construct_UClass_AGridPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GRIDTEMPLATE_API UClass* Z_Construct_UClass_AGridPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AGridPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GridTemplate"), Z_Construct_UClass_AGridPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AGridPlayerController)


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_PlayerController_GridPlayerController_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGridPlayerController(AGridPlayerController&&) = delete; \
	AGridPlayerController(const AGridPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGridPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGridPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGridPlayerController) \
	NO_API virtual ~AGridPlayerController();


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_PlayerController_GridPlayerController_h_13_PROLOG
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_PlayerController_GridPlayerController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_PlayerController_GridPlayerController_h_16_INCLASS_NO_PURE_DECLS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_PlayerController_GridPlayerController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGridPlayerController;

// ********** End Class AGridPlayerController ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_PlayerController_GridPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
