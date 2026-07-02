// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Gameplay/ActorComponent/GridInteractionComponent.h"

#ifdef GRIDTEMPLATE_GridInteractionComponent_generated_h
#error "GridInteractionComponent.generated.h already included, missing '#pragma once' in GridInteractionComponent.h"
#endif
#define GRIDTEMPLATE_GridInteractionComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;

// ********** Begin Delegate FOnCellClicked ********************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_9_DELEGATE \
GRIDTEMPLATE_API void FOnCellClicked_DelegateWrapper(const FMulticastScriptDelegate& OnCellClicked, FVector2D GridCoord);


// ********** End Delegate FOnCellClicked **********************************************************

// ********** Begin Delegate FOnCellHovered ********************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_10_DELEGATE \
GRIDTEMPLATE_API void FOnCellHovered_DelegateWrapper(const FMulticastScriptDelegate& OnCellHovered, FVector2D GridCoord);


// ********** End Delegate FOnCellHovered **********************************************************

// ********** Begin Delegate FOnUnitClicked ********************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_11_DELEGATE \
GRIDTEMPLATE_API void FOnUnitClicked_DelegateWrapper(const FMulticastScriptDelegate& OnUnitClicked, AActor* HitActor);


// ********** End Delegate FOnUnitClicked **********************************************************

// ********** Begin Class UGridInteractionComponent ************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execPerformTrace);


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_16_CALLBACK_WRAPPERS
GRIDTEMPLATE_API UClass* Z_Construct_UClass_UGridInteractionComponent_NoRegister();

#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGridInteractionComponent(); \
	friend struct Z_Construct_UClass_UGridInteractionComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GRIDTEMPLATE_API UClass* Z_Construct_UClass_UGridInteractionComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UGridInteractionComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GridTemplate"), Z_Construct_UClass_UGridInteractionComponent_NoRegister) \
	DECLARE_SERIALIZER(UGridInteractionComponent)


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGridInteractionComponent(UGridInteractionComponent&&) = delete; \
	UGridInteractionComponent(const UGridInteractionComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGridInteractionComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGridInteractionComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGridInteractionComponent) \
	NO_API virtual ~UGridInteractionComponent();


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_13_PROLOG
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_16_CALLBACK_WRAPPERS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_16_INCLASS_NO_PURE_DECLS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGridInteractionComponent;

// ********** End Class UGridInteractionComponent **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_ActorComponent_GridInteractionComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
