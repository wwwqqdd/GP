// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ALSPlayerCameraManager.h"

#ifdef ALS_SYSTEM_ALSPlayerCameraManager_generated_h
#error "ALSPlayerCameraManager.generated.h already included, missing '#pragma once' in ALSPlayerCameraManager.h"
#endif
#define ALS_SYSTEM_ALSPlayerCameraManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AALSBaseCharacter;

// ********** Begin Class AALSPlayerCameraManager **************************************************
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCustomCameraBehavior); \
	DECLARE_FUNCTION(execCalculateAxisIndependentLag); \
	DECLARE_FUNCTION(execGetCameraBehaviorParam); \
	DECLARE_FUNCTION(execOnPossess);


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_17_CALLBACK_WRAPPERS
ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSPlayerCameraManager_NoRegister();

#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAALSPlayerCameraManager(); \
	friend struct Z_Construct_UClass_AALSPlayerCameraManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSPlayerCameraManager_NoRegister(); \
public: \
	DECLARE_CLASS2(AALSPlayerCameraManager, APlayerCameraManager, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ALS_System"), Z_Construct_UClass_AALSPlayerCameraManager_NoRegister) \
	DECLARE_SERIALIZER(AALSPlayerCameraManager)


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AALSPlayerCameraManager(AALSPlayerCameraManager&&) = delete; \
	AALSPlayerCameraManager(const AALSPlayerCameraManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AALSPlayerCameraManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AALSPlayerCameraManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AALSPlayerCameraManager) \
	NO_API virtual ~AALSPlayerCameraManager();


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_14_PROLOG
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_17_CALLBACK_WRAPPERS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_17_INCLASS_NO_PURE_DECLS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AALSPlayerCameraManager;

// ********** End Class AALSPlayerCameraManager ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
