// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ALSPlayerController.h"

#ifdef ALS_SYSTEM_ALSPlayerController_generated_h
#error "ALSPlayerController.generated.h already included, missing '#pragma once' in ALSPlayerController.h"
#endif
#define ALS_SYSTEM_ALSPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FInputActionValue;

// ********** Begin Class AALSPlayerController *****************************************************
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerController_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDebugOverlayMenuCycleAction); \
	DECLARE_FUNCTION(execDebugOpenOverlayMenuAction); \
	DECLARE_FUNCTION(execDebugToggleMeshAction); \
	DECLARE_FUNCTION(execDebugFocusedCharacterCycleAction); \
	DECLARE_FUNCTION(execDebugToggleSlomoAction); \
	DECLARE_FUNCTION(execDebugToggleCharacterInfoAction); \
	DECLARE_FUNCTION(execDebugToggleLayerColorsAction); \
	DECLARE_FUNCTION(execDebugToggleShapesAction); \
	DECLARE_FUNCTION(execDebugToggleTracesAction); \
	DECLARE_FUNCTION(execDebugToggleDebugViewAction); \
	DECLARE_FUNCTION(execDebugToggleHudAction); \
	DECLARE_FUNCTION(execLookingDirectionAction); \
	DECLARE_FUNCTION(execVelocityDirectionAction); \
	DECLARE_FUNCTION(execRagdollAction); \
	DECLARE_FUNCTION(execWalkAction); \
	DECLARE_FUNCTION(execStanceAction); \
	DECLARE_FUNCTION(execCameraHeldAction); \
	DECLARE_FUNCTION(execCameraTapAction); \
	DECLARE_FUNCTION(execAimAction); \
	DECLARE_FUNCTION(execSprintAction); \
	DECLARE_FUNCTION(execJumpAction); \
	DECLARE_FUNCTION(execCameraRightAction); \
	DECLARE_FUNCTION(execCameraUpAction); \
	DECLARE_FUNCTION(execRightMovementAction); \
	DECLARE_FUNCTION(execForwardMovementAction);


ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSPlayerController_NoRegister();

#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerController_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAALSPlayerController(); \
	friend struct Z_Construct_UClass_AALSPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AALSPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ALS_System"), Z_Construct_UClass_AALSPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AALSPlayerController)


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerController_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AALSPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AALSPlayerController(AALSPlayerController&&) = delete; \
	AALSPlayerController(const AALSPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AALSPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AALSPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AALSPlayerController) \
	NO_API virtual ~AALSPlayerController();


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerController_h_15_PROLOG
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerController_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerController_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerController_h_18_INCLASS_NO_PURE_DECLS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerController_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AALSPlayerController;

// ********** End Class AALSPlayerController *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
