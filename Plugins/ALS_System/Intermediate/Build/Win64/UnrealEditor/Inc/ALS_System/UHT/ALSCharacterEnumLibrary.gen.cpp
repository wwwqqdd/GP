// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Library/ALSCharacterEnumLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeALSCharacterEnumLibrary() {}

// ********** Begin Cross Module References ********************************************************
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSFootstepType();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSGait();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSGroundedEntryState();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSHipsDirection();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSMantleType();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSMovementAction();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSMovementDirection();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSMovementState();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSOverlayState();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSRotationMode();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSSpawnType();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSStance();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSViewMode();
UPackage* Z_Construct_UPackage__Script_ALS_System();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EALSGait ******************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSGait;
static UEnum* EALSGait_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSGait.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSGait.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSGait, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSGait"));
	}
	return Z_Registration_Info_UEnum_EALSGait.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSGait>()
{
	return EALSGait_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSGait_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character gait state. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums\n */" },
#endif
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "Running.Name", "EALSGait::Running" },
		{ "ScriptName", "ALS_Gait" },
		{ "Sprinting.Name", "EALSGait::Sprinting" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character gait state. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums" },
#endif
		{ "Walking.Name", "EALSGait::Walking" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSGait::Walking", (int64)EALSGait::Walking },
		{ "EALSGait::Running", (int64)EALSGait::Running },
		{ "EALSGait::Sprinting", (int64)EALSGait::Sprinting },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSGait_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSGait",
	"EALSGait",
	Z_Construct_UEnum_ALS_System_EALSGait_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSGait_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSGait_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSGait_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSGait()
{
	if (!Z_Registration_Info_UEnum_EALSGait.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSGait.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSGait_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSGait.InnerSingleton;
}
// ********** End Enum EALSGait ********************************************************************

// ********** Begin Enum EALSMovementAction ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSMovementAction;
static UEnum* EALSMovementAction_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSMovementAction.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSMovementAction.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSMovementAction, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSMovementAction"));
	}
	return Z_Registration_Info_UEnum_EALSMovementAction.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSMovementAction>()
{
	return EALSMovementAction_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSMovementAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character movement action state. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums\n */" },
#endif
		{ "GettingUp.Name", "EALSMovementAction::GettingUp" },
		{ "HighMantle.Name", "EALSMovementAction::HighMantle" },
		{ "LowMantle.Name", "EALSMovementAction::LowMantle" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "None.Name", "EALSMovementAction::None" },
		{ "Rolling.Name", "EALSMovementAction::Rolling" },
		{ "ScriptName", "ALS_MovementAction" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character movement action state. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSMovementAction::None", (int64)EALSMovementAction::None },
		{ "EALSMovementAction::LowMantle", (int64)EALSMovementAction::LowMantle },
		{ "EALSMovementAction::HighMantle", (int64)EALSMovementAction::HighMantle },
		{ "EALSMovementAction::Rolling", (int64)EALSMovementAction::Rolling },
		{ "EALSMovementAction::GettingUp", (int64)EALSMovementAction::GettingUp },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSMovementAction_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSMovementAction",
	"EALSMovementAction",
	Z_Construct_UEnum_ALS_System_EALSMovementAction_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSMovementAction_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSMovementAction_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSMovementAction_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSMovementAction()
{
	if (!Z_Registration_Info_UEnum_EALSMovementAction.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSMovementAction.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSMovementAction_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSMovementAction.InnerSingleton;
}
// ********** End Enum EALSMovementAction **********************************************************

// ********** Begin Enum EALSMovementState *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSMovementState;
static UEnum* EALSMovementState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSMovementState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSMovementState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSMovementState, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSMovementState"));
	}
	return Z_Registration_Info_UEnum_EALSMovementState.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSMovementState>()
{
	return EALSMovementState_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSMovementState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character movement state. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums\n */" },
#endif
		{ "Grounded.Name", "EALSMovementState::Grounded" },
		{ "InAir.Name", "EALSMovementState::InAir" },
		{ "Mantling.Name", "EALSMovementState::Mantling" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "None.Name", "EALSMovementState::None" },
		{ "Ragdoll.Name", "EALSMovementState::Ragdoll" },
		{ "ScriptName", "ALS_MovementState" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character movement state. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSMovementState::None", (int64)EALSMovementState::None },
		{ "EALSMovementState::Grounded", (int64)EALSMovementState::Grounded },
		{ "EALSMovementState::InAir", (int64)EALSMovementState::InAir },
		{ "EALSMovementState::Mantling", (int64)EALSMovementState::Mantling },
		{ "EALSMovementState::Ragdoll", (int64)EALSMovementState::Ragdoll },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSMovementState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSMovementState",
	"EALSMovementState",
	Z_Construct_UEnum_ALS_System_EALSMovementState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSMovementState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSMovementState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSMovementState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSMovementState()
{
	if (!Z_Registration_Info_UEnum_EALSMovementState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSMovementState.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSMovementState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSMovementState.InnerSingleton;
}
// ********** End Enum EALSMovementState ***********************************************************

// ********** Begin Enum EALSOverlayState **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSOverlayState;
static UEnum* EALSOverlayState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSOverlayState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSOverlayState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSOverlayState, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSOverlayState"));
	}
	return Z_Registration_Info_UEnum_EALSOverlayState.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSOverlayState>()
{
	return EALSOverlayState_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSOverlayState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Barrel.Name", "EALSOverlayState::Barrel" },
		{ "Binoculars.Name", "EALSOverlayState::Binoculars" },
		{ "BlueprintType", "true" },
		{ "Bow.Name", "EALSOverlayState::Bow" },
		{ "Box.Name", "EALSOverlayState::Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character overlay state. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums\n */" },
#endif
		{ "Default.Name", "EALSOverlayState::Default" },
		{ "Feminine.Name", "EALSOverlayState::Feminine" },
		{ "HandsTied.Name", "EALSOverlayState::HandsTied" },
		{ "Injured.Name", "EALSOverlayState::Injured" },
		{ "Masculine.Name", "EALSOverlayState::Masculine" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "PistolOneHanded.Name", "EALSOverlayState::PistolOneHanded" },
		{ "PistolTwoHanded.Name", "EALSOverlayState::PistolTwoHanded" },
		{ "Rifle.Name", "EALSOverlayState::Rifle" },
		{ "ScriptName", "ALS_OverlayState" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character overlay state. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums" },
#endif
		{ "Torch.Name", "EALSOverlayState::Torch" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSOverlayState::Default", (int64)EALSOverlayState::Default },
		{ "EALSOverlayState::Masculine", (int64)EALSOverlayState::Masculine },
		{ "EALSOverlayState::Feminine", (int64)EALSOverlayState::Feminine },
		{ "EALSOverlayState::Injured", (int64)EALSOverlayState::Injured },
		{ "EALSOverlayState::HandsTied", (int64)EALSOverlayState::HandsTied },
		{ "EALSOverlayState::Rifle", (int64)EALSOverlayState::Rifle },
		{ "EALSOverlayState::PistolOneHanded", (int64)EALSOverlayState::PistolOneHanded },
		{ "EALSOverlayState::PistolTwoHanded", (int64)EALSOverlayState::PistolTwoHanded },
		{ "EALSOverlayState::Bow", (int64)EALSOverlayState::Bow },
		{ "EALSOverlayState::Torch", (int64)EALSOverlayState::Torch },
		{ "EALSOverlayState::Binoculars", (int64)EALSOverlayState::Binoculars },
		{ "EALSOverlayState::Box", (int64)EALSOverlayState::Box },
		{ "EALSOverlayState::Barrel", (int64)EALSOverlayState::Barrel },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSOverlayState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSOverlayState",
	"EALSOverlayState",
	Z_Construct_UEnum_ALS_System_EALSOverlayState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSOverlayState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSOverlayState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSOverlayState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSOverlayState()
{
	if (!Z_Registration_Info_UEnum_EALSOverlayState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSOverlayState.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSOverlayState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSOverlayState.InnerSingleton;
}
// ********** End Enum EALSOverlayState ************************************************************

// ********** Begin Enum EALSRotationMode **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSRotationMode;
static UEnum* EALSRotationMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSRotationMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSRotationMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSRotationMode, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSRotationMode"));
	}
	return Z_Registration_Info_UEnum_EALSRotationMode.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSRotationMode>()
{
	return EALSRotationMode_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSRotationMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Aiming.Name", "EALSRotationMode::Aiming" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character rotation mode. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums\n */" },
#endif
		{ "LookingDirection.Name", "EALSRotationMode::LookingDirection" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "ScriptName", "ALS_RotationMode" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character rotation mode. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums" },
#endif
		{ "VelocityDirection.Name", "EALSRotationMode::VelocityDirection" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSRotationMode::VelocityDirection", (int64)EALSRotationMode::VelocityDirection },
		{ "EALSRotationMode::LookingDirection", (int64)EALSRotationMode::LookingDirection },
		{ "EALSRotationMode::Aiming", (int64)EALSRotationMode::Aiming },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSRotationMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSRotationMode",
	"EALSRotationMode",
	Z_Construct_UEnum_ALS_System_EALSRotationMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSRotationMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSRotationMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSRotationMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSRotationMode()
{
	if (!Z_Registration_Info_UEnum_EALSRotationMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSRotationMode.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSRotationMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSRotationMode.InnerSingleton;
}
// ********** End Enum EALSRotationMode ************************************************************

// ********** Begin Enum EALSStance ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSStance;
static UEnum* EALSStance_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSStance.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSStance.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSStance, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSStance"));
	}
	return Z_Registration_Info_UEnum_EALSStance.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSStance>()
{
	return EALSStance_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSStance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character stance. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums\n */" },
#endif
		{ "Crouching.Name", "EALSStance::Crouching" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "ScriptName", "ALS_Stance" },
		{ "Standing.Name", "EALSStance::Standing" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character stance. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSStance::Standing", (int64)EALSStance::Standing },
		{ "EALSStance::Crouching", (int64)EALSStance::Crouching },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSStance_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSStance",
	"EALSStance",
	Z_Construct_UEnum_ALS_System_EALSStance_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSStance_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSStance_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSStance_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSStance()
{
	if (!Z_Registration_Info_UEnum_EALSStance.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSStance.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSStance_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSStance.InnerSingleton;
}
// ********** End Enum EALSStance ******************************************************************

// ********** Begin Enum EALSViewMode **************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSViewMode;
static UEnum* EALSViewMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSViewMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSViewMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSViewMode, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSViewMode"));
	}
	return Z_Registration_Info_UEnum_EALSViewMode.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSViewMode>()
{
	return EALSViewMode_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSViewMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character view mode. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums\n */" },
#endif
		{ "FirstPerson.Name", "EALSViewMode::FirstPerson" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "ScriptName", "ALS_ViewMode" },
		{ "ThirdPerson.Name", "EALSViewMode::ThirdPerson" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character view mode. Note: Also edit related struct in ALSStructEnumLibrary if you add new enums" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSViewMode::ThirdPerson", (int64)EALSViewMode::ThirdPerson },
		{ "EALSViewMode::FirstPerson", (int64)EALSViewMode::FirstPerson },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSViewMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSViewMode",
	"EALSViewMode",
	Z_Construct_UEnum_ALS_System_EALSViewMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSViewMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSViewMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSViewMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSViewMode()
{
	if (!Z_Registration_Info_UEnum_EALSViewMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSViewMode.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSViewMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSViewMode.InnerSingleton;
}
// ********** End Enum EALSViewMode ****************************************************************

// ********** Begin Enum EALSAnimFeatureExample ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSAnimFeatureExample;
static UEnum* EALSAnimFeatureExample_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSAnimFeatureExample.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSAnimFeatureExample.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSAnimFeatureExample"));
	}
	return Z_Registration_Info_UEnum_EALSAnimFeatureExample.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSAnimFeatureExample>()
{
	return EALSAnimFeatureExample_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AdditiveBlending.Name", "EALSAnimFeatureExample::AdditiveBlending" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "ScriptName", "ALS_AnimFeatureExample" },
		{ "SprintImpulse.Name", "EALSAnimFeatureExample::SprintImpulse" },
		{ "StrideBlending.Name", "EALSAnimFeatureExample::StrideBlending" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSAnimFeatureExample::StrideBlending", (int64)EALSAnimFeatureExample::StrideBlending },
		{ "EALSAnimFeatureExample::AdditiveBlending", (int64)EALSAnimFeatureExample::AdditiveBlending },
		{ "EALSAnimFeatureExample::SprintImpulse", (int64)EALSAnimFeatureExample::SprintImpulse },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSAnimFeatureExample",
	"EALSAnimFeatureExample",
	Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample()
{
	if (!Z_Registration_Info_UEnum_EALSAnimFeatureExample.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSAnimFeatureExample.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSAnimFeatureExample_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSAnimFeatureExample.InnerSingleton;
}
// ********** End Enum EALSAnimFeatureExample ******************************************************

// ********** Begin Enum EALSFootstepType **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSFootstepType;
static UEnum* EALSFootstepType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSFootstepType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSFootstepType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSFootstepType, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSFootstepType"));
	}
	return Z_Registration_Info_UEnum_EALSFootstepType.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSFootstepType>()
{
	return EALSFootstepType_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSFootstepType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Jump.Name", "EALSFootstepType::Jump" },
		{ "Land.Name", "EALSFootstepType::Land" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "ScriptName", "ALS_FootstepType" },
		{ "Step.Name", "EALSFootstepType::Step" },
		{ "WalkRun.Name", "EALSFootstepType::WalkRun" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSFootstepType::Step", (int64)EALSFootstepType::Step },
		{ "EALSFootstepType::WalkRun", (int64)EALSFootstepType::WalkRun },
		{ "EALSFootstepType::Jump", (int64)EALSFootstepType::Jump },
		{ "EALSFootstepType::Land", (int64)EALSFootstepType::Land },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSFootstepType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSFootstepType",
	"EALSFootstepType",
	Z_Construct_UEnum_ALS_System_EALSFootstepType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSFootstepType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSFootstepType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSFootstepType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSFootstepType()
{
	if (!Z_Registration_Info_UEnum_EALSFootstepType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSFootstepType.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSFootstepType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSFootstepType.InnerSingleton;
}
// ********** End Enum EALSFootstepType ************************************************************

// ********** Begin Enum EALSGroundedEntryState ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSGroundedEntryState;
static UEnum* EALSGroundedEntryState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSGroundedEntryState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSGroundedEntryState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSGroundedEntryState, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSGroundedEntryState"));
	}
	return Z_Registration_Info_UEnum_EALSGroundedEntryState.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSGroundedEntryState>()
{
	return EALSGroundedEntryState_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSGroundedEntryState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "None.Name", "EALSGroundedEntryState::None" },
		{ "Roll.Name", "EALSGroundedEntryState::Roll" },
		{ "ScriptName", "ALS_GroundedEntryState" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSGroundedEntryState::None", (int64)EALSGroundedEntryState::None },
		{ "EALSGroundedEntryState::Roll", (int64)EALSGroundedEntryState::Roll },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSGroundedEntryState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSGroundedEntryState",
	"EALSGroundedEntryState",
	Z_Construct_UEnum_ALS_System_EALSGroundedEntryState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSGroundedEntryState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSGroundedEntryState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSGroundedEntryState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSGroundedEntryState()
{
	if (!Z_Registration_Info_UEnum_EALSGroundedEntryState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSGroundedEntryState.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSGroundedEntryState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSGroundedEntryState.InnerSingleton;
}
// ********** End Enum EALSGroundedEntryState ******************************************************

// ********** Begin Enum EALSHipsDirection *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSHipsDirection;
static UEnum* EALSHipsDirection_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSHipsDirection.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSHipsDirection.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSHipsDirection, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSHipsDirection"));
	}
	return Z_Registration_Info_UEnum_EALSHipsDirection.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSHipsDirection>()
{
	return EALSHipsDirection_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSHipsDirection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "B.Name", "EALSHipsDirection::B" },
		{ "BlueprintType", "true" },
		{ "F.Name", "EALSHipsDirection::F" },
		{ "LB.Name", "EALSHipsDirection::LB" },
		{ "LF.Name", "EALSHipsDirection::LF" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "RB.Name", "EALSHipsDirection::RB" },
		{ "RF.Name", "EALSHipsDirection::RF" },
		{ "ScriptName", "ALS_HipsDirection" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSHipsDirection::F", (int64)EALSHipsDirection::F },
		{ "EALSHipsDirection::B", (int64)EALSHipsDirection::B },
		{ "EALSHipsDirection::RF", (int64)EALSHipsDirection::RF },
		{ "EALSHipsDirection::RB", (int64)EALSHipsDirection::RB },
		{ "EALSHipsDirection::LF", (int64)EALSHipsDirection::LF },
		{ "EALSHipsDirection::LB", (int64)EALSHipsDirection::LB },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSHipsDirection_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSHipsDirection",
	"EALSHipsDirection",
	Z_Construct_UEnum_ALS_System_EALSHipsDirection_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSHipsDirection_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSHipsDirection_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSHipsDirection_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSHipsDirection()
{
	if (!Z_Registration_Info_UEnum_EALSHipsDirection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSHipsDirection.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSHipsDirection_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSHipsDirection.InnerSingleton;
}
// ********** End Enum EALSHipsDirection ***********************************************************

// ********** Begin Enum EALSMantleType ************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSMantleType;
static UEnum* EALSMantleType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSMantleType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSMantleType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSMantleType, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSMantleType"));
	}
	return Z_Registration_Info_UEnum_EALSMantleType.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSMantleType>()
{
	return EALSMantleType_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSMantleType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "FallingCatch.Name", "EALSMantleType::FallingCatch" },
		{ "HighMantle.Name", "EALSMantleType::HighMantle" },
		{ "LowMantle.Name", "EALSMantleType::LowMantle" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "ScriptName", "ALS_MantleType" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSMantleType::HighMantle", (int64)EALSMantleType::HighMantle },
		{ "EALSMantleType::LowMantle", (int64)EALSMantleType::LowMantle },
		{ "EALSMantleType::FallingCatch", (int64)EALSMantleType::FallingCatch },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSMantleType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSMantleType",
	"EALSMantleType",
	Z_Construct_UEnum_ALS_System_EALSMantleType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSMantleType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSMantleType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSMantleType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSMantleType()
{
	if (!Z_Registration_Info_UEnum_EALSMantleType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSMantleType.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSMantleType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSMantleType.InnerSingleton;
}
// ********** End Enum EALSMantleType **************************************************************

// ********** Begin Enum EALSMovementDirection *****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSMovementDirection;
static UEnum* EALSMovementDirection_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSMovementDirection.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSMovementDirection.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSMovementDirection, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSMovementDirection"));
	}
	return Z_Registration_Info_UEnum_EALSMovementDirection.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSMovementDirection>()
{
	return EALSMovementDirection_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSMovementDirection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Backward.Name", "EALSMovementDirection::Backward" },
		{ "BlueprintType", "true" },
		{ "Forward.Name", "EALSMovementDirection::Forward" },
		{ "Left.Name", "EALSMovementDirection::Left" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "Right.Name", "EALSMovementDirection::Right" },
		{ "ScriptName", "ALS_MovementDirection" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSMovementDirection::Forward", (int64)EALSMovementDirection::Forward },
		{ "EALSMovementDirection::Right", (int64)EALSMovementDirection::Right },
		{ "EALSMovementDirection::Left", (int64)EALSMovementDirection::Left },
		{ "EALSMovementDirection::Backward", (int64)EALSMovementDirection::Backward },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSMovementDirection_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSMovementDirection",
	"EALSMovementDirection",
	Z_Construct_UEnum_ALS_System_EALSMovementDirection_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSMovementDirection_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSMovementDirection_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSMovementDirection_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSMovementDirection()
{
	if (!Z_Registration_Info_UEnum_EALSMovementDirection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSMovementDirection.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSMovementDirection_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSMovementDirection.InnerSingleton;
}
// ********** End Enum EALSMovementDirection *******************************************************

// ********** Begin Enum EALSSpawnType *************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EALSSpawnType;
static UEnum* EALSSpawnType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EALSSpawnType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EALSSpawnType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ALS_System_EALSSpawnType, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("EALSSpawnType"));
	}
	return Z_Registration_Info_UEnum_EALSSpawnType.OuterSingleton;
}
template<> ALS_SYSTEM_API UEnum* StaticEnum<EALSSpawnType>()
{
	return EALSSpawnType_StaticEnum();
}
struct Z_Construct_UEnum_ALS_System_EALSSpawnType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Attached.Name", "EALSSpawnType::Attached" },
		{ "BlueprintType", "true" },
		{ "Location.Name", "EALSSpawnType::Location" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterEnumLibrary.h" },
		{ "ScriptName", "ALS_SpawnType" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EALSSpawnType::Location", (int64)EALSSpawnType::Location },
		{ "EALSSpawnType::Attached", (int64)EALSSpawnType::Attached },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ALS_System_EALSSpawnType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	"EALSSpawnType",
	"EALSSpawnType",
	Z_Construct_UEnum_ALS_System_EALSSpawnType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSSpawnType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ALS_System_EALSSpawnType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ALS_System_EALSSpawnType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ALS_System_EALSSpawnType()
{
	if (!Z_Registration_Info_UEnum_EALSSpawnType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EALSSpawnType.InnerSingleton, Z_Construct_UEnum_ALS_System_EALSSpawnType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EALSSpawnType.InnerSingleton;
}
// ********** End Enum EALSSpawnType ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Library_ALSCharacterEnumLibrary_h__Script_ALS_System_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EALSGait_StaticEnum, TEXT("EALSGait"), &Z_Registration_Info_UEnum_EALSGait, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 302578120U) },
		{ EALSMovementAction_StaticEnum, TEXT("EALSMovementAction"), &Z_Registration_Info_UEnum_EALSMovementAction, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3592139098U) },
		{ EALSMovementState_StaticEnum, TEXT("EALSMovementState"), &Z_Registration_Info_UEnum_EALSMovementState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3499683400U) },
		{ EALSOverlayState_StaticEnum, TEXT("EALSOverlayState"), &Z_Registration_Info_UEnum_EALSOverlayState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 633900848U) },
		{ EALSRotationMode_StaticEnum, TEXT("EALSRotationMode"), &Z_Registration_Info_UEnum_EALSRotationMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2421730686U) },
		{ EALSStance_StaticEnum, TEXT("EALSStance"), &Z_Registration_Info_UEnum_EALSStance, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3364754934U) },
		{ EALSViewMode_StaticEnum, TEXT("EALSViewMode"), &Z_Registration_Info_UEnum_EALSViewMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2043679271U) },
		{ EALSAnimFeatureExample_StaticEnum, TEXT("EALSAnimFeatureExample"), &Z_Registration_Info_UEnum_EALSAnimFeatureExample, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3598371368U) },
		{ EALSFootstepType_StaticEnum, TEXT("EALSFootstepType"), &Z_Registration_Info_UEnum_EALSFootstepType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1065686014U) },
		{ EALSGroundedEntryState_StaticEnum, TEXT("EALSGroundedEntryState"), &Z_Registration_Info_UEnum_EALSGroundedEntryState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 136894182U) },
		{ EALSHipsDirection_StaticEnum, TEXT("EALSHipsDirection"), &Z_Registration_Info_UEnum_EALSHipsDirection, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2010966037U) },
		{ EALSMantleType_StaticEnum, TEXT("EALSMantleType"), &Z_Registration_Info_UEnum_EALSMantleType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4146670901U) },
		{ EALSMovementDirection_StaticEnum, TEXT("EALSMovementDirection"), &Z_Registration_Info_UEnum_EALSMovementDirection, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3787895579U) },
		{ EALSSpawnType_StaticEnum, TEXT("EALSSpawnType"), &Z_Registration_Info_UEnum_EALSSpawnType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1788513559U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Library_ALSCharacterEnumLibrary_h__Script_ALS_System_3604933036(TEXT("/Script/ALS_System"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Library_ALSCharacterEnumLibrary_h__Script_ALS_System_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Library_ALSCharacterEnumLibrary_h__Script_ALS_System_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
