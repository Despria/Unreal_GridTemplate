// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Gameplay/Subsystem/GridSubsystem.h"

#ifdef GRIDTEMPLATE_GridSubsystem_generated_h
#error "GridSubsystem.generated.h already included, missing '#pragma once' in GridSubsystem.h"
#endif
#define GRIDTEMPLATE_GridSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FGridCellData *****************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGridCellData_Statics; \
	GRIDTEMPLATE_API static class UScriptStruct* StaticStruct();


struct FGridCellData;
// ********** End ScriptStruct FGridCellData *******************************************************

// ********** Begin Delegate FOnMoveableRangeUpdated ***********************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_27_DELEGATE \
GRIDTEMPLATE_API void FOnMoveableRangeUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnMoveableRangeUpdated, TArray<FVector2D> const& Cells);


// ********** End Delegate FOnMoveableRangeUpdated *************************************************

// ********** Begin Delegate FOnAttackRangeUpdated *************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_28_DELEGATE \
GRIDTEMPLATE_API void FOnAttackRangeUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnAttackRangeUpdated, TArray<FVector2D> const& Cells);


// ********** End Delegate FOnAttackRangeUpdated ***************************************************

// ********** Begin Delegate FOnPathUpdated ********************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_29_DELEGATE \
GRIDTEMPLATE_API void FOnPathUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnPathUpdated, TArray<FVector2D> const& Cells);


// ********** End Delegate FOnPathUpdated **********************************************************

// ********** Begin Delegate FOnSelectionCleared ***************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_30_DELEGATE \
GRIDTEMPLATE_API void FOnSelectionCleared_DelegateWrapper(const FMulticastScriptDelegate& OnSelectionCleared);


// ********** End Delegate FOnSelectionCleared *****************************************************

// ********** Begin Class UGridSubsystem ***********************************************************
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetAllCellCoords); \
	DECLARE_FUNCTION(execIsValidCell); \
	DECLARE_FUNCTION(execWorldToGrid); \
	DECLARE_FUNCTION(execGridToWorldCenter); \
	DECLARE_FUNCTION(execInitializeGrid);


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_38_CALLBACK_WRAPPERS
GRIDTEMPLATE_API UClass* Z_Construct_UClass_UGridSubsystem_NoRegister();

#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGridSubsystem(); \
	friend struct Z_Construct_UClass_UGridSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GRIDTEMPLATE_API UClass* Z_Construct_UClass_UGridSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGridSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GridTemplate"), Z_Construct_UClass_UGridSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGridSubsystem)


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGridSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGridSubsystem(UGridSubsystem&&) = delete; \
	UGridSubsystem(const UGridSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGridSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGridSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGridSubsystem) \
	NO_API virtual ~UGridSubsystem();


#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_35_PROLOG
#define FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_38_CALLBACK_WRAPPERS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_38_INCLASS_NO_PURE_DECLS \
	FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGridSubsystem;

// ********** End Class UGridSubsystem *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_despia_Documents_Unreal_Projects_GridTemplate_Source_GridTemplate_Gameplay_Subsystem_GridSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
