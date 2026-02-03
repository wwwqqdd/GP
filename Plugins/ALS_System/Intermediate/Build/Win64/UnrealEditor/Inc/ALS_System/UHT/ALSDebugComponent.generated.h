// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Component/ALSDebugComponent.h"

#ifdef ALS_SYSTEM_ALSDebugComponent_generated_h
#error "ALSDebugComponent.generated.h already included, missing '#pragma once' in ALSDebugComponent.h"
#endif
#define ALS_SYSTEM_ALSDebugComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class APlayerController;

// ********** Begin Class UALSDebugComponent *******************************************************
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OverlayMenuCycle_Implementation(bool bValue); \
	virtual void OpenOverlayMenu_Implementation(bool bValue); \
	DECLARE_FUNCTION(execFocusedDebugCharacterCycle); \
	DECLARE_FUNCTION(execGetShowLayerColors); \
	DECLARE_FUNCTION(execGetShowDebugShapes); \
	DECLARE_FUNCTION(execGetShowTraces); \
	DECLARE_FUNCTION(execGetDebugView); \
	DECLARE_FUNCTION(execToggleCharacterInfo); \
	DECLARE_FUNCTION(execToggleLayerColors); \
	DECLARE_FUNCTION(execToggleDebugShapes); \
	DECLARE_FUNCTION(execToggleTraces); \
	DECLARE_FUNCTION(execToggleDebugMesh); \
	DECLARE_FUNCTION(execOverlayMenuCycle); \
	DECLARE_FUNCTION(execOpenOverlayMenu); \
	DECLARE_FUNCTION(execToggleDebugView); \
	DECLARE_FUNCTION(execToggleHud); \
	DECLARE_FUNCTION(execToggleSlomo); \
	DECLARE_FUNCTION(execToggleGlobalTimeDilationLocal);


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_16_CALLBACK_WRAPPERS
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSDebugComponent_NoRegister();

#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUALSDebugComponent(); \
	friend struct Z_Construct_UClass_UALSDebugComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSDebugComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UALSDebugComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ALS_System"), Z_Construct_UClass_UALSDebugComponent_NoRegister) \
	DECLARE_SERIALIZER(UALSDebugComponent)


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UALSDebugComponent(UALSDebugComponent&&) = delete; \
	UALSDebugComponent(const UALSDebugComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UALSDebugComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UALSDebugComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UALSDebugComponent) \
	NO_API virtual ~UALSDebugComponent();


#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_13_PROLOG
#define FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_16_CALLBACK_WRAPPERS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_16_INCLASS_NO_PURE_DECLS \
	FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UALSDebugComponent;

// ********** End Class UALSDebugComponent *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Component_ALSDebugComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
