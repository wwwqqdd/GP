// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Animation/ALSPlayerCameraBehavior.h"

#ifdef ALS_SYSTEM_ALSPlayerCameraBehavior_generated_h
#error "ALSPlayerCameraBehavior.generated.h already included, missing '#pragma once' in ALSPlayerCameraBehavior.h"
#endif
#define ALS_SYSTEM_ALSPlayerCameraBehavior_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UALSPlayerCameraBehavior *************************************************
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSPlayerCameraBehavior_NoRegister();

#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUALSPlayerCameraBehavior(); \
	friend struct Z_Construct_UClass_UALSPlayerCameraBehavior_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSPlayerCameraBehavior_NoRegister(); \
public: \
	DECLARE_CLASS2(UALSPlayerCameraBehavior, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ALS_System"), Z_Construct_UClass_UALSPlayerCameraBehavior_NoRegister) \
	DECLARE_SERIALIZER(UALSPlayerCameraBehavior)


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UALSPlayerCameraBehavior(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UALSPlayerCameraBehavior(UALSPlayerCameraBehavior&&) = delete; \
	UALSPlayerCameraBehavior(const UALSPlayerCameraBehavior&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UALSPlayerCameraBehavior); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UALSPlayerCameraBehavior); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UALSPlayerCameraBehavior) \
	NO_API virtual ~UALSPlayerCameraBehavior();


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h_16_PROLOG
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h_19_INCLASS_NO_PURE_DECLS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UALSPlayerCameraBehavior;

// ********** End Class UALSPlayerCameraBehavior ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
