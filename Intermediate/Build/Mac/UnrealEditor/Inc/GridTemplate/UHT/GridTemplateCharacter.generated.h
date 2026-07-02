// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GridTemplateCharacter.h"

#ifdef GRIDTEMPLATE_GridTemplateCharacter_generated_h
#error "GridTemplateCharacter.generated.h already included, missing '#pragma once' in GridTemplateCharacter.h"
#endif
#define GRIDTEMPLATE_GridTemplateCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AGridTemplateCharacter ***************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoLook); \
	DECLARE_FUNCTION(execDoMove);


GRIDTEMPLATE_API UClass* Z_Construct_UClass_AGridTemplateCharacter_NoRegister();

#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGridTemplateCharacter(); \
	friend struct Z_Construct_UClass_AGridTemplateCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GRIDTEMPLATE_API UClass* Z_Construct_UClass_AGridTemplateCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AGridTemplateCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/GridTemplate"), Z_Construct_UClass_AGridTemplateCharacter_NoRegister) \
	DECLARE_SERIALIZER(AGridTemplateCharacter)


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGridTemplateCharacter(AGridTemplateCharacter&&) = delete; \
	AGridTemplateCharacter(const AGridTemplateCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGridTemplateCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGridTemplateCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AGridTemplateCharacter) \
	NO_API virtual ~AGridTemplateCharacter();


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateCharacter_h_21_PROLOG
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGridTemplateCharacter;

// ********** End Class AGridTemplateCharacter *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_GridTemplateCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
