// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Library/ALSCharacterStructLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeALSCharacterStructLibrary() {}

// ********** Begin Cross Module References ********************************************************
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSSpawnType();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSCameraGaitSettings();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSCameraSettings();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSCameraStateSettings();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSComponentAndTransform();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSHitFX();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSMantleAsset();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSMantleParams();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSMantleTraceSettings();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSMovementSettings();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSMovementStanceSettings();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSMovementStateSettings();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSRotateInPlaceAsset();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimSequenceBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCurveVector_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_EAttachLocation();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PHYSICSCORE_API UEnum* Z_Construct_UEnum_PhysicsCore_EPhysicalSurface();
UPackage* Z_Construct_UPackage__Script_ALS_System();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FALSComponentAndTransform *****************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSComponentAndTransform;
class UScriptStruct* FALSComponentAndTransform::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSComponentAndTransform.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSComponentAndTransform.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSComponentAndTransform, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSComponentAndTransform"));
	}
	return Z_Registration_Info_UScriptStruct_FALSComponentAndTransform.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[] = {
		{ "Category", "Character Struct Library" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Component_MetaData[] = {
		{ "Category", "Character Struct Library" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Component;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSComponentAndTransform>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSComponentAndTransform, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Transform_MetaData), NewProp_Transform_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::NewProp_Component = { "Component", nullptr, (EPropertyFlags)0x0114000000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSComponentAndTransform, Component), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Component_MetaData), NewProp_Component_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::NewProp_Transform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::NewProp_Component,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSComponentAndTransform",
	Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::PropPointers),
	sizeof(FALSComponentAndTransform),
	alignof(FALSComponentAndTransform),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSComponentAndTransform()
{
	if (!Z_Registration_Info_UScriptStruct_FALSComponentAndTransform.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSComponentAndTransform.InnerSingleton, Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSComponentAndTransform.InnerSingleton;
}
// ********** End ScriptStruct FALSComponentAndTransform *******************************************

// ********** Begin ScriptStruct FALSCameraSettings ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSCameraSettings;
class UScriptStruct* FALSCameraSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSCameraSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSCameraSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSCameraSettings, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSCameraSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FALSCameraSettings.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSCameraSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetArmLength_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocketOffset_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LagSpeed_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationLagSpeed_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDoCollisionTest_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetArmLength;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SocketOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LagSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationLagSpeed;
	static void NewProp_bDoCollisionTest_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDoCollisionTest;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSCameraSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_TargetArmLength = { "TargetArmLength", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraSettings, TargetArmLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetArmLength_MetaData), NewProp_TargetArmLength_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_SocketOffset = { "SocketOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraSettings, SocketOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocketOffset_MetaData), NewProp_SocketOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_LagSpeed = { "LagSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraSettings, LagSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LagSpeed_MetaData), NewProp_LagSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_RotationLagSpeed = { "RotationLagSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraSettings, RotationLagSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationLagSpeed_MetaData), NewProp_RotationLagSpeed_MetaData) };
void Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_bDoCollisionTest_SetBit(void* Obj)
{
	((FALSCameraSettings*)Obj)->bDoCollisionTest = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_bDoCollisionTest = { "bDoCollisionTest", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FALSCameraSettings), &Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_bDoCollisionTest_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDoCollisionTest_MetaData), NewProp_bDoCollisionTest_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSCameraSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_TargetArmLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_SocketOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_LagSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_RotationLagSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewProp_bDoCollisionTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSCameraSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSCameraSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSCameraSettings",
	Z_Construct_UScriptStruct_FALSCameraSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSCameraSettings_Statics::PropPointers),
	sizeof(FALSCameraSettings),
	alignof(FALSCameraSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSCameraSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSCameraSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSCameraSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FALSCameraSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSCameraSettings.InnerSingleton, Z_Construct_UScriptStruct_FALSCameraSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSCameraSettings.InnerSingleton;
}
// ********** End ScriptStruct FALSCameraSettings **************************************************

// ********** Begin ScriptStruct FALSCameraGaitSettings ********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSCameraGaitSettings;
class UScriptStruct* FALSCameraGaitSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSCameraGaitSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSCameraGaitSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSCameraGaitSettings, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSCameraGaitSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FALSCameraGaitSettings.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Walking_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Running_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sprinting_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Crouching_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Walking;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Running;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Sprinting;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Crouching;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSCameraGaitSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::NewProp_Walking = { "Walking", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraGaitSettings, Walking), Z_Construct_UScriptStruct_FALSCameraSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Walking_MetaData), NewProp_Walking_MetaData) }; // 4129584515
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::NewProp_Running = { "Running", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraGaitSettings, Running), Z_Construct_UScriptStruct_FALSCameraSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Running_MetaData), NewProp_Running_MetaData) }; // 4129584515
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::NewProp_Sprinting = { "Sprinting", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraGaitSettings, Sprinting), Z_Construct_UScriptStruct_FALSCameraSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sprinting_MetaData), NewProp_Sprinting_MetaData) }; // 4129584515
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::NewProp_Crouching = { "Crouching", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraGaitSettings, Crouching), Z_Construct_UScriptStruct_FALSCameraSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Crouching_MetaData), NewProp_Crouching_MetaData) }; // 4129584515
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::NewProp_Walking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::NewProp_Running,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::NewProp_Sprinting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::NewProp_Crouching,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSCameraGaitSettings",
	Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::PropPointers),
	sizeof(FALSCameraGaitSettings),
	alignof(FALSCameraGaitSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSCameraGaitSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FALSCameraGaitSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSCameraGaitSettings.InnerSingleton, Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSCameraGaitSettings.InnerSingleton;
}
// ********** End ScriptStruct FALSCameraGaitSettings **********************************************

// ********** Begin ScriptStruct FALSCameraStateSettings *******************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSCameraStateSettings;
class UScriptStruct* FALSCameraStateSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSCameraStateSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSCameraStateSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSCameraStateSettings, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSCameraStateSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FALSCameraStateSettings.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VelocityDirection_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookingDirection_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Aiming_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_VelocityDirection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LookingDirection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Aiming;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSCameraStateSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::NewProp_VelocityDirection = { "VelocityDirection", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraStateSettings, VelocityDirection), Z_Construct_UScriptStruct_FALSCameraGaitSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VelocityDirection_MetaData), NewProp_VelocityDirection_MetaData) }; // 3426981484
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::NewProp_LookingDirection = { "LookingDirection", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraStateSettings, LookingDirection), Z_Construct_UScriptStruct_FALSCameraGaitSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookingDirection_MetaData), NewProp_LookingDirection_MetaData) }; // 3426981484
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::NewProp_Aiming = { "Aiming", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSCameraStateSettings, Aiming), Z_Construct_UScriptStruct_FALSCameraGaitSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Aiming_MetaData), NewProp_Aiming_MetaData) }; // 3426981484
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::NewProp_VelocityDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::NewProp_LookingDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::NewProp_Aiming,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSCameraStateSettings",
	Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::PropPointers),
	sizeof(FALSCameraStateSettings),
	alignof(FALSCameraStateSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSCameraStateSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FALSCameraStateSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSCameraStateSettings.InnerSingleton, Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSCameraStateSettings.InnerSingleton;
}
// ********** End ScriptStruct FALSCameraStateSettings *********************************************

// ********** Begin ScriptStruct FALSMantleAsset ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSMantleAsset;
class UScriptStruct* FALSMantleAsset::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMantleAsset.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSMantleAsset.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSMantleAsset, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSMantleAsset"));
	}
	return Z_Registration_Info_UScriptStruct_FALSMantleAsset.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSMantleAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimMontage_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionCorrectionCurve_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingOffset_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowHeight_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowPlayRate_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowStartPosition_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighHeight_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighPlayRate_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighStartPosition_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PositionCorrectionCurve;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartingOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LowHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LowPlayRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LowStartPosition;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HighHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HighPlayRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HighStartPosition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSMantleAsset>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_AnimMontage = { "AnimMontage", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleAsset, AnimMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimMontage_MetaData), NewProp_AnimMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_PositionCorrectionCurve = { "PositionCorrectionCurve", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleAsset, PositionCorrectionCurve), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionCorrectionCurve_MetaData), NewProp_PositionCorrectionCurve_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_StartingOffset = { "StartingOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleAsset, StartingOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingOffset_MetaData), NewProp_StartingOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_LowHeight = { "LowHeight", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleAsset, LowHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowHeight_MetaData), NewProp_LowHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_LowPlayRate = { "LowPlayRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleAsset, LowPlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowPlayRate_MetaData), NewProp_LowPlayRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_LowStartPosition = { "LowStartPosition", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleAsset, LowStartPosition), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowStartPosition_MetaData), NewProp_LowStartPosition_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_HighHeight = { "HighHeight", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleAsset, HighHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighHeight_MetaData), NewProp_HighHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_HighPlayRate = { "HighPlayRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleAsset, HighPlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighPlayRate_MetaData), NewProp_HighPlayRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_HighStartPosition = { "HighStartPosition", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleAsset, HighStartPosition), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighStartPosition_MetaData), NewProp_HighStartPosition_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSMantleAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_AnimMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_PositionCorrectionCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_StartingOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_LowHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_LowPlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_LowStartPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_HighHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_HighPlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewProp_HighStartPosition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMantleAsset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSMantleAsset_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSMantleAsset",
	Z_Construct_UScriptStruct_FALSMantleAsset_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMantleAsset_Statics::PropPointers),
	sizeof(FALSMantleAsset),
	alignof(FALSMantleAsset),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMantleAsset_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSMantleAsset_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSMantleAsset()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMantleAsset.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSMantleAsset.InnerSingleton, Z_Construct_UScriptStruct_FALSMantleAsset_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSMantleAsset.InnerSingleton;
}
// ********** End ScriptStruct FALSMantleAsset *****************************************************

// ********** Begin ScriptStruct FALSMantleParams **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSMantleParams;
class UScriptStruct* FALSMantleParams::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMantleParams.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSMantleParams.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSMantleParams, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSMantleParams"));
	}
	return Z_Registration_Info_UScriptStruct_FALSMantleParams.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSMantleParams_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimMontage_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionCorrectionCurve_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingPosition_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingOffset_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PositionCorrectionCurve;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartingPosition;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartingOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSMantleParams>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_AnimMontage = { "AnimMontage", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleParams, AnimMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimMontage_MetaData), NewProp_AnimMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_PositionCorrectionCurve = { "PositionCorrectionCurve", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleParams, PositionCorrectionCurve), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionCorrectionCurve_MetaData), NewProp_PositionCorrectionCurve_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_StartingPosition = { "StartingPosition", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleParams, StartingPosition), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingPosition_MetaData), NewProp_StartingPosition_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleParams, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_StartingOffset = { "StartingOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleParams, StartingOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingOffset_MetaData), NewProp_StartingOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSMantleParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_AnimMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_PositionCorrectionCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_StartingPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewProp_StartingOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMantleParams_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSMantleParams_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSMantleParams",
	Z_Construct_UScriptStruct_FALSMantleParams_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMantleParams_Statics::PropPointers),
	sizeof(FALSMantleParams),
	alignof(FALSMantleParams),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMantleParams_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSMantleParams_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSMantleParams()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMantleParams.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSMantleParams.InnerSingleton, Z_Construct_UScriptStruct_FALSMantleParams_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSMantleParams.InnerSingleton;
}
// ********** End ScriptStruct FALSMantleParams ****************************************************

// ********** Begin ScriptStruct FALSMantleTraceSettings *******************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSMantleTraceSettings;
class UScriptStruct* FALSMantleTraceSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMantleTraceSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSMantleTraceSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSMantleTraceSettings, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSMantleTraceSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FALSMantleTraceSettings.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxLedgeHeight_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinLedgeHeight_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReachDistance_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ForwardTraceRadius_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DownwardTraceRadius_MetaData[] = {
		{ "Category", "Mantle System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxLedgeHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinLedgeHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReachDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ForwardTraceRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DownwardTraceRadius;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSMantleTraceSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_MaxLedgeHeight = { "MaxLedgeHeight", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleTraceSettings, MaxLedgeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxLedgeHeight_MetaData), NewProp_MaxLedgeHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_MinLedgeHeight = { "MinLedgeHeight", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleTraceSettings, MinLedgeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinLedgeHeight_MetaData), NewProp_MinLedgeHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_ReachDistance = { "ReachDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleTraceSettings, ReachDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReachDistance_MetaData), NewProp_ReachDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_ForwardTraceRadius = { "ForwardTraceRadius", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleTraceSettings, ForwardTraceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ForwardTraceRadius_MetaData), NewProp_ForwardTraceRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_DownwardTraceRadius = { "DownwardTraceRadius", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMantleTraceSettings, DownwardTraceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DownwardTraceRadius_MetaData), NewProp_DownwardTraceRadius_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_MaxLedgeHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_MinLedgeHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_ReachDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_ForwardTraceRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewProp_DownwardTraceRadius,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSMantleTraceSettings",
	Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::PropPointers),
	sizeof(FALSMantleTraceSettings),
	alignof(FALSMantleTraceSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSMantleTraceSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMantleTraceSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSMantleTraceSettings.InnerSingleton, Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSMantleTraceSettings.InnerSingleton;
}
// ********** End ScriptStruct FALSMantleTraceSettings *********************************************

// ********** Begin ScriptStruct FALSMovementSettings **********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSMovementSettings;
class UScriptStruct* FALSMovementSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMovementSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSMovementSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSMovementSettings, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSMovementSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FALSMovementSettings.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSMovementSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunSpeed_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementCurve_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationRateCurve_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementCurve;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RotationRateCurve;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSMovementSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementSettings, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_RunSpeed = { "RunSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementSettings, RunSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunSpeed_MetaData), NewProp_RunSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementSettings, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSpeed_MetaData), NewProp_SprintSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_MovementCurve = { "MovementCurve", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementSettings, MovementCurve), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementCurve_MetaData), NewProp_MovementCurve_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_RotationRateCurve = { "RotationRateCurve", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementSettings, RotationRateCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationRateCurve_MetaData), NewProp_RotationRateCurve_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSMovementSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_RunSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_SprintSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_MovementCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewProp_RotationRateCurve,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMovementSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSMovementSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSMovementSettings",
	Z_Construct_UScriptStruct_FALSMovementSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMovementSettings_Statics::PropPointers),
	sizeof(FALSMovementSettings),
	alignof(FALSMovementSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMovementSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSMovementSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSMovementSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMovementSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSMovementSettings.InnerSingleton, Z_Construct_UScriptStruct_FALSMovementSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSMovementSettings.InnerSingleton;
}
// ********** End ScriptStruct FALSMovementSettings ************************************************

// ********** Begin ScriptStruct FALSMovementStanceSettings ****************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSMovementStanceSettings;
class UScriptStruct* FALSMovementStanceSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMovementStanceSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSMovementStanceSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSMovementStanceSettings, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSMovementStanceSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FALSMovementStanceSettings.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Standing_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Crouching_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Standing;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Crouching;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSMovementStanceSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::NewProp_Standing = { "Standing", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementStanceSettings, Standing), Z_Construct_UScriptStruct_FALSMovementSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Standing_MetaData), NewProp_Standing_MetaData) }; // 4104518745
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::NewProp_Crouching = { "Crouching", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementStanceSettings, Crouching), Z_Construct_UScriptStruct_FALSMovementSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Crouching_MetaData), NewProp_Crouching_MetaData) }; // 4104518745
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::NewProp_Standing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::NewProp_Crouching,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSMovementStanceSettings",
	Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::PropPointers),
	sizeof(FALSMovementStanceSettings),
	alignof(FALSMovementStanceSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSMovementStanceSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMovementStanceSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSMovementStanceSettings.InnerSingleton, Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSMovementStanceSettings.InnerSingleton;
}
// ********** End ScriptStruct FALSMovementStanceSettings ******************************************

// ********** Begin ScriptStruct FALSMovementStateSettings *****************************************
static_assert(std::is_polymorphic<FALSMovementStateSettings>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FALSMovementStateSettings cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSMovementStateSettings;
class UScriptStruct* FALSMovementStateSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMovementStateSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSMovementStateSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSMovementStateSettings, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSMovementStateSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FALSMovementStateSettings.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VelocityDirection_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookingDirection_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Aiming_MetaData[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_VelocityDirection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LookingDirection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Aiming;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSMovementStateSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::NewProp_VelocityDirection = { "VelocityDirection", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementStateSettings, VelocityDirection), Z_Construct_UScriptStruct_FALSMovementStanceSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VelocityDirection_MetaData), NewProp_VelocityDirection_MetaData) }; // 4103205189
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::NewProp_LookingDirection = { "LookingDirection", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementStateSettings, LookingDirection), Z_Construct_UScriptStruct_FALSMovementStanceSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookingDirection_MetaData), NewProp_LookingDirection_MetaData) }; // 4103205189
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::NewProp_Aiming = { "Aiming", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSMovementStateSettings, Aiming), Z_Construct_UScriptStruct_FALSMovementStanceSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Aiming_MetaData), NewProp_Aiming_MetaData) }; // 4103205189
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::NewProp_VelocityDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::NewProp_LookingDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::NewProp_Aiming,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"ALSMovementStateSettings",
	Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::PropPointers),
	sizeof(FALSMovementStateSettings),
	alignof(FALSMovementStateSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSMovementStateSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FALSMovementStateSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSMovementStateSettings.InnerSingleton, Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSMovementStateSettings.InnerSingleton;
}
// ********** End ScriptStruct FALSMovementStateSettings *******************************************

// ********** Begin ScriptStruct FALSRotateInPlaceAsset ********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSRotateInPlaceAsset;
class UScriptStruct* FALSRotateInPlaceAsset::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSRotateInPlaceAsset.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSRotateInPlaceAsset.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSRotateInPlaceAsset, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSRotateInPlaceAsset"));
	}
	return Z_Registration_Info_UScriptStruct_FALSRotateInPlaceAsset.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Animation_MetaData[] = {
		{ "Category", "Rotation System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotName_MetaData[] = {
		{ "Category", "Rotation System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlowTurnRate_MetaData[] = {
		{ "Category", "Rotation System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FastTurnRate_MetaData[] = {
		{ "Category", "Rotation System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlowPlayRate_MetaData[] = {
		{ "Category", "Rotation System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FastPlayRate_MetaData[] = {
		{ "Category", "Rotation System" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Animation;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SlotName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlowTurnRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FastTurnRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlowPlayRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FastPlayRate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSRotateInPlaceAsset>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_Animation = { "Animation", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSRotateInPlaceAsset, Animation), Z_Construct_UClass_UAnimSequenceBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Animation_MetaData), NewProp_Animation_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSRotateInPlaceAsset, SlotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotName_MetaData), NewProp_SlotName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_SlowTurnRate = { "SlowTurnRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSRotateInPlaceAsset, SlowTurnRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlowTurnRate_MetaData), NewProp_SlowTurnRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_FastTurnRate = { "FastTurnRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSRotateInPlaceAsset, FastTurnRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FastTurnRate_MetaData), NewProp_FastTurnRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_SlowPlayRate = { "SlowPlayRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSRotateInPlaceAsset, SlowPlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlowPlayRate_MetaData), NewProp_SlowPlayRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_FastPlayRate = { "FastPlayRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSRotateInPlaceAsset, FastPlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FastPlayRate_MetaData), NewProp_FastPlayRate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_Animation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_SlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_SlowTurnRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_FastTurnRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_SlowPlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewProp_FastPlayRate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	nullptr,
	&NewStructOps,
	"ALSRotateInPlaceAsset",
	Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::PropPointers),
	sizeof(FALSRotateInPlaceAsset),
	alignof(FALSRotateInPlaceAsset),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSRotateInPlaceAsset()
{
	if (!Z_Registration_Info_UScriptStruct_FALSRotateInPlaceAsset.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSRotateInPlaceAsset.InnerSingleton, Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSRotateInPlaceAsset.InnerSingleton;
}
// ********** End ScriptStruct FALSRotateInPlaceAsset **********************************************

// ********** Begin ScriptStruct FALSHitFX *********************************************************
static_assert(std::is_polymorphic<FALSHitFX>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FALSHitFX cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FALSHitFX;
class UScriptStruct* FALSHitFX::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FALSHitFX.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FALSHitFX.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FALSHitFX, (UObject*)Z_Construct_UPackage__Script_ALS_System(), TEXT("ALSHitFX"));
	}
	return Z_Registration_Info_UScriptStruct_FALSHitFX.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FALSHitFX_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceType_MetaData[] = {
		{ "Category", "Surface" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[] = {
		{ "Category", "Sound" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundSpawnType_MetaData[] = {
		{ "Category", "Sound" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundAttachmentType_MetaData[] = {
		{ "Category", "Sound" },
		{ "EditCondition", "SoundSpawnType == EALSSpawnType::Attached" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundLocationOffset_MetaData[] = {
		{ "Category", "Sound" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundRotationOffset_MetaData[] = {
		{ "Category", "Sound" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecalMaterial_MetaData[] = {
		{ "Category", "Decal" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecalSpawnType_MetaData[] = {
		{ "Category", "Decal" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecalAttachmentType_MetaData[] = {
		{ "Category", "Decal" },
		{ "EditCondition", "DecalSpawnType == EALSSpawnType::Attached" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecalLifeSpan_MetaData[] = {
		{ "Category", "Decal" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecalSize_MetaData[] = {
		{ "Category", "Decal" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecalLocationOffset_MetaData[] = {
		{ "Category", "Decal" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecalRotationOffset_MetaData[] = {
		{ "Category", "Decal" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraSystem_MetaData[] = {
		{ "Category", "Niagara" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraSpawnType_MetaData[] = {
		{ "Category", "Niagara" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraAttachmentType_MetaData[] = {
		{ "Category", "Niagara" },
		{ "EditCondition", "NiagaraSpawnType == EALSSpawnType::Attached" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraLocationOffset_MetaData[] = {
		{ "Category", "Niagara" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraRotationOffset_MetaData[] = {
		{ "Category", "Niagara" },
		{ "ModuleRelativePath", "Public/Library/ALSCharacterStructLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SurfaceType;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Sound;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SoundSpawnType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SoundSpawnType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SoundAttachmentType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SoundLocationOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SoundRotationOffset;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DecalMaterial;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DecalSpawnType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DecalSpawnType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DecalAttachmentType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DecalLifeSpan;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DecalSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DecalLocationOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DecalRotationOffset;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_NiagaraSystem;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NiagaraSpawnType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NiagaraSpawnType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NiagaraAttachmentType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NiagaraLocationOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NiagaraRotationOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FALSHitFX>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SurfaceType = { "SurfaceType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, SurfaceType), Z_Construct_UEnum_PhysicsCore_EPhysicalSurface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceType_MetaData), NewProp_SurfaceType_MetaData) }; // 161619406
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, Sound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sound_MetaData), NewProp_Sound_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundSpawnType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundSpawnType = { "SoundSpawnType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, SoundSpawnType), Z_Construct_UEnum_ALS_System_EALSSpawnType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundSpawnType_MetaData), NewProp_SoundSpawnType_MetaData) }; // 1788513559
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundAttachmentType = { "SoundAttachmentType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, SoundAttachmentType), Z_Construct_UEnum_Engine_EAttachLocation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundAttachmentType_MetaData), NewProp_SoundAttachmentType_MetaData) }; // 2784615398
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundLocationOffset = { "SoundLocationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, SoundLocationOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundLocationOffset_MetaData), NewProp_SoundLocationOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundRotationOffset = { "SoundRotationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, SoundRotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundRotationOffset_MetaData), NewProp_SoundRotationOffset_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalMaterial = { "DecalMaterial", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, DecalMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecalMaterial_MetaData), NewProp_DecalMaterial_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalSpawnType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalSpawnType = { "DecalSpawnType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, DecalSpawnType), Z_Construct_UEnum_ALS_System_EALSSpawnType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecalSpawnType_MetaData), NewProp_DecalSpawnType_MetaData) }; // 1788513559
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalAttachmentType = { "DecalAttachmentType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, DecalAttachmentType), Z_Construct_UEnum_Engine_EAttachLocation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecalAttachmentType_MetaData), NewProp_DecalAttachmentType_MetaData) }; // 2784615398
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalLifeSpan = { "DecalLifeSpan", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, DecalLifeSpan), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecalLifeSpan_MetaData), NewProp_DecalLifeSpan_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalSize = { "DecalSize", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, DecalSize), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecalSize_MetaData), NewProp_DecalSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalLocationOffset = { "DecalLocationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, DecalLocationOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecalLocationOffset_MetaData), NewProp_DecalLocationOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalRotationOffset = { "DecalRotationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, DecalRotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecalRotationOffset_MetaData), NewProp_DecalRotationOffset_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraSystem = { "NiagaraSystem", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, NiagaraSystem), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraSystem_MetaData), NewProp_NiagaraSystem_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraSpawnType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraSpawnType = { "NiagaraSpawnType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, NiagaraSpawnType), Z_Construct_UEnum_ALS_System_EALSSpawnType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraSpawnType_MetaData), NewProp_NiagaraSpawnType_MetaData) }; // 1788513559
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraAttachmentType = { "NiagaraAttachmentType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, NiagaraAttachmentType), Z_Construct_UEnum_Engine_EAttachLocation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraAttachmentType_MetaData), NewProp_NiagaraAttachmentType_MetaData) }; // 2784615398
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraLocationOffset = { "NiagaraLocationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, NiagaraLocationOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraLocationOffset_MetaData), NewProp_NiagaraLocationOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraRotationOffset = { "NiagaraRotationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FALSHitFX, NiagaraRotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraRotationOffset_MetaData), NewProp_NiagaraRotationOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FALSHitFX_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SurfaceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_Sound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundSpawnType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundSpawnType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundAttachmentType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundLocationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_SoundRotationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalSpawnType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalSpawnType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalAttachmentType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalLifeSpan,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalLocationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_DecalRotationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraSpawnType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraSpawnType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraAttachmentType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraLocationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FALSHitFX_Statics::NewProp_NiagaraRotationOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSHitFX_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FALSHitFX_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"ALSHitFX",
	Z_Construct_UScriptStruct_FALSHitFX_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSHitFX_Statics::PropPointers),
	sizeof(FALSHitFX),
	alignof(FALSHitFX),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FALSHitFX_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FALSHitFX_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FALSHitFX()
{
	if (!Z_Registration_Info_UScriptStruct_FALSHitFX.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FALSHitFX.InnerSingleton, Z_Construct_UScriptStruct_FALSHitFX_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FALSHitFX.InnerSingleton;
}
// ********** End ScriptStruct FALSHitFX ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Library_ALSCharacterStructLibrary_h__Script_ALS_System_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FALSComponentAndTransform::StaticStruct, Z_Construct_UScriptStruct_FALSComponentAndTransform_Statics::NewStructOps, TEXT("ALSComponentAndTransform"), &Z_Registration_Info_UScriptStruct_FALSComponentAndTransform, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSComponentAndTransform), 905585028U) },
		{ FALSCameraSettings::StaticStruct, Z_Construct_UScriptStruct_FALSCameraSettings_Statics::NewStructOps, TEXT("ALSCameraSettings"), &Z_Registration_Info_UScriptStruct_FALSCameraSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSCameraSettings), 4129584515U) },
		{ FALSCameraGaitSettings::StaticStruct, Z_Construct_UScriptStruct_FALSCameraGaitSettings_Statics::NewStructOps, TEXT("ALSCameraGaitSettings"), &Z_Registration_Info_UScriptStruct_FALSCameraGaitSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSCameraGaitSettings), 3426981484U) },
		{ FALSCameraStateSettings::StaticStruct, Z_Construct_UScriptStruct_FALSCameraStateSettings_Statics::NewStructOps, TEXT("ALSCameraStateSettings"), &Z_Registration_Info_UScriptStruct_FALSCameraStateSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSCameraStateSettings), 242001079U) },
		{ FALSMantleAsset::StaticStruct, Z_Construct_UScriptStruct_FALSMantleAsset_Statics::NewStructOps, TEXT("ALSMantleAsset"), &Z_Registration_Info_UScriptStruct_FALSMantleAsset, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSMantleAsset), 676673026U) },
		{ FALSMantleParams::StaticStruct, Z_Construct_UScriptStruct_FALSMantleParams_Statics::NewStructOps, TEXT("ALSMantleParams"), &Z_Registration_Info_UScriptStruct_FALSMantleParams, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSMantleParams), 226287506U) },
		{ FALSMantleTraceSettings::StaticStruct, Z_Construct_UScriptStruct_FALSMantleTraceSettings_Statics::NewStructOps, TEXT("ALSMantleTraceSettings"), &Z_Registration_Info_UScriptStruct_FALSMantleTraceSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSMantleTraceSettings), 1721508361U) },
		{ FALSMovementSettings::StaticStruct, Z_Construct_UScriptStruct_FALSMovementSettings_Statics::NewStructOps, TEXT("ALSMovementSettings"), &Z_Registration_Info_UScriptStruct_FALSMovementSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSMovementSettings), 4104518745U) },
		{ FALSMovementStanceSettings::StaticStruct, Z_Construct_UScriptStruct_FALSMovementStanceSettings_Statics::NewStructOps, TEXT("ALSMovementStanceSettings"), &Z_Registration_Info_UScriptStruct_FALSMovementStanceSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSMovementStanceSettings), 4103205189U) },
		{ FALSMovementStateSettings::StaticStruct, Z_Construct_UScriptStruct_FALSMovementStateSettings_Statics::NewStructOps, TEXT("ALSMovementStateSettings"), &Z_Registration_Info_UScriptStruct_FALSMovementStateSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSMovementStateSettings), 1090940969U) },
		{ FALSRotateInPlaceAsset::StaticStruct, Z_Construct_UScriptStruct_FALSRotateInPlaceAsset_Statics::NewStructOps, TEXT("ALSRotateInPlaceAsset"), &Z_Registration_Info_UScriptStruct_FALSRotateInPlaceAsset, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSRotateInPlaceAsset), 1425377104U) },
		{ FALSHitFX::StaticStruct, Z_Construct_UScriptStruct_FALSHitFX_Statics::NewStructOps, TEXT("ALSHitFX"), &Z_Registration_Info_UScriptStruct_FALSHitFX, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FALSHitFX), 2650895836U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Library_ALSCharacterStructLibrary_h__Script_ALS_System_3411957090(TEXT("/Script/ALS_System"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Library_ALSCharacterStructLibrary_h__Script_ALS_System_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Library_ALSCharacterStructLibrary_h__Script_ALS_System_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
