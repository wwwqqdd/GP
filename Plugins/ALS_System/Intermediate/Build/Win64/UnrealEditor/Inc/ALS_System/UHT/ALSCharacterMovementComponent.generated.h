// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ALSCharacterMovementComponent.h"

#ifdef ALS_SYSTEM_ALSCharacterMovementComponent_generated_h
#error "ALSCharacterMovementComponent.generated.h already included, missing '#pragma once' in ALSCharacterMovementComponent.h"
#endif
#define ALS_SYSTEM_ALSCharacterMovementComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class EALSGait : uint8;
struct FALSMovementSettings;

// ********** Begin Class UALSCharacterMovementComponent *******************************************
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_16_RPC_WRAPPERS \
	virtual void Server_SetAllowedGait_Implementation(EALSGait NewAllowedGait); \
	DECLARE_FUNCTION(execServer_SetAllowedGait); \
	DECLARE_FUNCTION(execSetAllowedGait); \
	DECLARE_FUNCTION(execSetMovementSettings);


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_16_CALLBACK_WRAPPERS
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSCharacterMovementComponent_NoRegister();

#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUALSCharacterMovementComponent(); \
	friend struct Z_Construct_UClass_UALSCharacterMovementComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSCharacterMovementComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UALSCharacterMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ALS_System"), Z_Construct_UClass_UALSCharacterMovementComponent_NoRegister) \
	DECLARE_SERIALIZER(UALSCharacterMovementComponent)


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UALSCharacterMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UALSCharacterMovementComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UALSCharacterMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UALSCharacterMovementComponent); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UALSCharacterMovementComponent(UALSCharacterMovementComponent&&) = delete; \
	UALSCharacterMovementComponent(const UALSCharacterMovementComponent&) = delete; \
	NO_API virtual ~UALSCharacterMovementComponent();


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_13_PROLOG
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_16_RPC_WRAPPERS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_16_CALLBACK_WRAPPERS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_16_INCLASS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UALSCharacterMovementComponent;

// ********** End Class UALSCharacterMovementComponent *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
