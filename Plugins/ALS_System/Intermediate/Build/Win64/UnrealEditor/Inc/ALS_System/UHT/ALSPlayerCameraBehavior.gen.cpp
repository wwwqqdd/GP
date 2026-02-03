// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Animation/ALSPlayerCameraBehavior.h"
#include "Components/SkeletalMeshComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeALSPlayerCameraBehavior() {}

// ********** Begin Cross Module References ********************************************************
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSPlayerCameraBehavior();
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSPlayerCameraBehavior_NoRegister();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSGait();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSMovementAction();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSMovementState();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSStance();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSViewMode();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
UPackage* Z_Construct_UPackage__Script_ALS_System();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UALSPlayerCameraBehavior *************************************************
void UALSPlayerCameraBehavior::StaticRegisterNativesUALSPlayerCameraBehavior()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UALSPlayerCameraBehavior;
UClass* UALSPlayerCameraBehavior::GetPrivateStaticClass()
{
	using TClass = UALSPlayerCameraBehavior;
	if (!Z_Registration_Info_UClass_UALSPlayerCameraBehavior.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ALSPlayerCameraBehavior"),
			Z_Registration_Info_UClass_UALSPlayerCameraBehavior.InnerSingleton,
			StaticRegisterNativesUALSPlayerCameraBehavior,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UALSPlayerCameraBehavior.InnerSingleton;
}
UClass* Z_Construct_UClass_UALSPlayerCameraBehavior_NoRegister()
{
	return UALSPlayerCameraBehavior::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UALSPlayerCameraBehavior_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "Animation/ALSPlayerCameraBehavior.h" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementState_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementAction_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLookingDirection_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVelocityDirection_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAiming_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gait_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stance_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewMode_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRightShoulder_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugView_MetaData[] = {
		{ "Category", "Read Only Data|Character Information" },
		{ "ModuleRelativePath", "Public/Animation/ALSPlayerCameraBehavior.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_MovementState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MovementState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MovementAction_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MovementAction;
	static void NewProp_bLookingDirection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLookingDirection;
	static void NewProp_bVelocityDirection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVelocityDirection;
	static void NewProp_bAiming_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAiming;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Gait_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Gait;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Stance_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Stance;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ViewMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ViewMode;
	static void NewProp_bRightShoulder_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRightShoulder;
	static void NewProp_bDebugView_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugView;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UALSPlayerCameraBehavior>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_MovementState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_MovementState = { "MovementState", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSPlayerCameraBehavior, MovementState), Z_Construct_UEnum_ALS_System_EALSMovementState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementState_MetaData), NewProp_MovementState_MetaData) }; // 3499683400
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_MovementAction_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_MovementAction = { "MovementAction", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSPlayerCameraBehavior, MovementAction), Z_Construct_UEnum_ALS_System_EALSMovementAction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementAction_MetaData), NewProp_MovementAction_MetaData) }; // 3592139098
void Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bLookingDirection_SetBit(void* Obj)
{
	((UALSPlayerCameraBehavior*)Obj)->bLookingDirection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bLookingDirection = { "bLookingDirection", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UALSPlayerCameraBehavior), &Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bLookingDirection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLookingDirection_MetaData), NewProp_bLookingDirection_MetaData) };
void Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bVelocityDirection_SetBit(void* Obj)
{
	((UALSPlayerCameraBehavior*)Obj)->bVelocityDirection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bVelocityDirection = { "bVelocityDirection", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UALSPlayerCameraBehavior), &Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bVelocityDirection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVelocityDirection_MetaData), NewProp_bVelocityDirection_MetaData) };
void Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bAiming_SetBit(void* Obj)
{
	((UALSPlayerCameraBehavior*)Obj)->bAiming = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bAiming = { "bAiming", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UALSPlayerCameraBehavior), &Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bAiming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAiming_MetaData), NewProp_bAiming_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_Gait_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_Gait = { "Gait", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSPlayerCameraBehavior, Gait), Z_Construct_UEnum_ALS_System_EALSGait, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gait_MetaData), NewProp_Gait_MetaData) }; // 302578120
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_Stance_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_Stance = { "Stance", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSPlayerCameraBehavior, Stance), Z_Construct_UEnum_ALS_System_EALSStance, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stance_MetaData), NewProp_Stance_MetaData) }; // 3364754934
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_ViewMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_ViewMode = { "ViewMode", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSPlayerCameraBehavior, ViewMode), Z_Construct_UEnum_ALS_System_EALSViewMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewMode_MetaData), NewProp_ViewMode_MetaData) }; // 2043679271
void Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bRightShoulder_SetBit(void* Obj)
{
	((UALSPlayerCameraBehavior*)Obj)->bRightShoulder = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bRightShoulder = { "bRightShoulder", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UALSPlayerCameraBehavior), &Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bRightShoulder_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRightShoulder_MetaData), NewProp_bRightShoulder_MetaData) };
void Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bDebugView_SetBit(void* Obj)
{
	((UALSPlayerCameraBehavior*)Obj)->bDebugView = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bDebugView = { "bDebugView", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UALSPlayerCameraBehavior), &Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bDebugView_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugView_MetaData), NewProp_bDebugView_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_MovementState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_MovementState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_MovementAction_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_MovementAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bLookingDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bVelocityDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bAiming,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_Gait_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_Gait,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_Stance_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_Stance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_ViewMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_ViewMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bRightShoulder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::NewProp_bDebugView,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::ClassParams = {
	&UALSPlayerCameraBehavior::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::Class_MetaDataParams), Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UALSPlayerCameraBehavior()
{
	if (!Z_Registration_Info_UClass_UALSPlayerCameraBehavior.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UALSPlayerCameraBehavior.OuterSingleton, Z_Construct_UClass_UALSPlayerCameraBehavior_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UALSPlayerCameraBehavior.OuterSingleton;
}
UALSPlayerCameraBehavior::UALSPlayerCameraBehavior(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UALSPlayerCameraBehavior);
UALSPlayerCameraBehavior::~UALSPlayerCameraBehavior() {}
// ********** End Class UALSPlayerCameraBehavior ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h__Script_ALS_System_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UALSPlayerCameraBehavior, UALSPlayerCameraBehavior::StaticClass, TEXT("UALSPlayerCameraBehavior"), &Z_Registration_Info_UClass_UALSPlayerCameraBehavior, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UALSPlayerCameraBehavior), 799892880U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h__Script_ALS_System_45507341(TEXT("/Script/ALS_System"),
	Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h__Script_ALS_System_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_Animation_ALSPlayerCameraBehavior_h__Script_ALS_System_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
