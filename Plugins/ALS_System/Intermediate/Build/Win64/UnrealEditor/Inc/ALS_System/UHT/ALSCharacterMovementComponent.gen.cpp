// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ALSCharacterMovementComponent.h"
#include "Library/ALSCharacterStructLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeALSCharacterMovementComponent() {}

// ********** Begin Cross Module References ********************************************************
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSCharacterMovementComponent();
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSCharacterMovementComponent_NoRegister();
ALS_SYSTEM_API UEnum* Z_Construct_UEnum_ALS_System_EALSGait();
ALS_SYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FALSMovementSettings();
ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
UPackage* Z_Construct_UPackage__Script_ALS_System();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UALSCharacterMovementComponent Function Server_SetAllowedGait ************
struct ALSCharacterMovementComponent_eventServer_SetAllowedGait_Parms
{
	EALSGait NewAllowedGait;
};
static FName NAME_UALSCharacterMovementComponent_Server_SetAllowedGait = FName(TEXT("Server_SetAllowedGait"));
void UALSCharacterMovementComponent::Server_SetAllowedGait(EALSGait NewAllowedGait)
{
	ALSCharacterMovementComponent_eventServer_SetAllowedGait_Parms Parms;
	Parms.NewAllowedGait=NewAllowedGait;
	UFunction* Func = FindFunctionChecked(NAME_UALSCharacterMovementComponent_Server_SetAllowedGait);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/ALSCharacterMovementComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewAllowedGait_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewAllowedGait;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::NewProp_NewAllowedGait_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::NewProp_NewAllowedGait = { "NewAllowedGait", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSCharacterMovementComponent_eventServer_SetAllowedGait_Parms, NewAllowedGait), Z_Construct_UEnum_ALS_System_EALSGait, METADATA_PARAMS(0, nullptr) }; // 302578120
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::NewProp_NewAllowedGait_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::NewProp_NewAllowedGait,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSCharacterMovementComponent, nullptr, "Server_SetAllowedGait", Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::PropPointers), sizeof(ALSCharacterMovementComponent_eventServer_SetAllowedGait_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ALSCharacterMovementComponent_eventServer_SetAllowedGait_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSCharacterMovementComponent::execServer_SetAllowedGait)
{
	P_GET_ENUM(EALSGait,Z_Param_NewAllowedGait);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_SetAllowedGait_Implementation(EALSGait(Z_Param_NewAllowedGait));
	P_NATIVE_END;
}
// ********** End Class UALSCharacterMovementComponent Function Server_SetAllowedGait **************

// ********** Begin Class UALSCharacterMovementComponent Function SetAllowedGait *******************
struct Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics
{
	struct ALSCharacterMovementComponent_eventSetAllowedGait_Parms
	{
		EALSGait NewAllowedGait;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/ALSCharacterMovementComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewAllowedGait_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewAllowedGait;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::NewProp_NewAllowedGait_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::NewProp_NewAllowedGait = { "NewAllowedGait", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSCharacterMovementComponent_eventSetAllowedGait_Parms, NewAllowedGait), Z_Construct_UEnum_ALS_System_EALSGait, METADATA_PARAMS(0, nullptr) }; // 302578120
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::NewProp_NewAllowedGait_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::NewProp_NewAllowedGait,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSCharacterMovementComponent, nullptr, "SetAllowedGait", Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::PropPointers), sizeof(Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::ALSCharacterMovementComponent_eventSetAllowedGait_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::ALSCharacterMovementComponent_eventSetAllowedGait_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSCharacterMovementComponent::execSetAllowedGait)
{
	P_GET_ENUM(EALSGait,Z_Param_NewAllowedGait);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAllowedGait(EALSGait(Z_Param_NewAllowedGait));
	P_NATIVE_END;
}
// ********** End Class UALSCharacterMovementComponent Function SetAllowedGait *********************

// ********** Begin Class UALSCharacterMovementComponent Function SetMovementSettings **************
struct Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics
{
	struct ALSCharacterMovementComponent_eventSetMovementSettings_Parms
	{
		FALSMovementSettings NewMovementSettings;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement Settings" },
		{ "ModuleRelativePath", "Public/ALSCharacterMovementComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewMovementSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::NewProp_NewMovementSettings = { "NewMovementSettings", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSCharacterMovementComponent_eventSetMovementSettings_Parms, NewMovementSettings), Z_Construct_UScriptStruct_FALSMovementSettings, METADATA_PARAMS(0, nullptr) }; // 4104518745
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::NewProp_NewMovementSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UALSCharacterMovementComponent, nullptr, "SetMovementSettings", Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::ALSCharacterMovementComponent_eventSetMovementSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::ALSCharacterMovementComponent_eventSetMovementSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UALSCharacterMovementComponent::execSetMovementSettings)
{
	P_GET_STRUCT(FALSMovementSettings,Z_Param_NewMovementSettings);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMovementSettings(Z_Param_NewMovementSettings);
	P_NATIVE_END;
}
// ********** End Class UALSCharacterMovementComponent Function SetMovementSettings ****************

// ********** Begin Class UALSCharacterMovementComponent *******************************************
void UALSCharacterMovementComponent::StaticRegisterNativesUALSCharacterMovementComponent()
{
	UClass* Class = UALSCharacterMovementComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Server_SetAllowedGait", &UALSCharacterMovementComponent::execServer_SetAllowedGait },
		{ "SetAllowedGait", &UALSCharacterMovementComponent::execSetAllowedGait },
		{ "SetMovementSettings", &UALSCharacterMovementComponent::execSetMovementSettings },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UALSCharacterMovementComponent;
UClass* UALSCharacterMovementComponent::GetPrivateStaticClass()
{
	using TClass = UALSCharacterMovementComponent;
	if (!Z_Registration_Info_UClass_UALSCharacterMovementComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ALSCharacterMovementComponent"),
			Z_Registration_Info_UClass_UALSCharacterMovementComponent.InnerSingleton,
			StaticRegisterNativesUALSCharacterMovementComponent,
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
	return Z_Registration_Info_UClass_UALSCharacterMovementComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UALSCharacterMovementComponent_NoRegister()
{
	return UALSCharacterMovementComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UALSCharacterMovementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "ALSCharacterMovementComponent.h" },
		{ "ModuleRelativePath", "Public/ALSCharacterMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequestMovementSettingsChange_MetaData[] = {
		{ "ModuleRelativePath", "Public/ALSCharacterMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowedGait_MetaData[] = {
		{ "ModuleRelativePath", "Public/ALSCharacterMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMovementSettings_MetaData[] = {
		{ "Category", "ALS|Movement System" },
		{ "ModuleRelativePath", "Public/ALSCharacterMovementComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_bRequestMovementSettingsChange;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AllowedGait_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AllowedGait;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentMovementSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UALSCharacterMovementComponent_Server_SetAllowedGait, "Server_SetAllowedGait" }, // 1583748087
		{ &Z_Construct_UFunction_UALSCharacterMovementComponent_SetAllowedGait, "SetAllowedGait" }, // 3060817865
		{ &Z_Construct_UFunction_UALSCharacterMovementComponent_SetMovementSettings, "SetMovementSettings" }, // 2751416835
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UALSCharacterMovementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UALSCharacterMovementComponent_Statics::NewProp_bRequestMovementSettingsChange = { "bRequestMovementSettingsChange", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSCharacterMovementComponent, bRequestMovementSettingsChange), nullptr, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequestMovementSettingsChange_MetaData), NewProp_bRequestMovementSettingsChange_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UALSCharacterMovementComponent_Statics::NewProp_AllowedGait_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UALSCharacterMovementComponent_Statics::NewProp_AllowedGait = { "AllowedGait", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSCharacterMovementComponent, AllowedGait), Z_Construct_UEnum_ALS_System_EALSGait, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowedGait_MetaData), NewProp_AllowedGait_MetaData) }; // 302578120
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UALSCharacterMovementComponent_Statics::NewProp_CurrentMovementSettings = { "CurrentMovementSettings", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UALSCharacterMovementComponent, CurrentMovementSettings), Z_Construct_UScriptStruct_FALSMovementSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMovementSettings_MetaData), NewProp_CurrentMovementSettings_MetaData) }; // 4104518745
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UALSCharacterMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSCharacterMovementComponent_Statics::NewProp_bRequestMovementSettingsChange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSCharacterMovementComponent_Statics::NewProp_AllowedGait_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSCharacterMovementComponent_Statics::NewProp_AllowedGait,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UALSCharacterMovementComponent_Statics::NewProp_CurrentMovementSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UALSCharacterMovementComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UALSCharacterMovementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UALSCharacterMovementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UALSCharacterMovementComponent_Statics::ClassParams = {
	&UALSCharacterMovementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UALSCharacterMovementComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UALSCharacterMovementComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UALSCharacterMovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UALSCharacterMovementComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UALSCharacterMovementComponent()
{
	if (!Z_Registration_Info_UClass_UALSCharacterMovementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UALSCharacterMovementComponent.OuterSingleton, Z_Construct_UClass_UALSCharacterMovementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UALSCharacterMovementComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UALSCharacterMovementComponent);
UALSCharacterMovementComponent::~UALSCharacterMovementComponent() {}
// ********** End Class UALSCharacterMovementComponent *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h__Script_ALS_System_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UALSCharacterMovementComponent, UALSCharacterMovementComponent::StaticClass, TEXT("UALSCharacterMovementComponent"), &Z_Registration_Info_UClass_UALSCharacterMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UALSCharacterMovementComponent), 3310938097U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h__Script_ALS_System_2191371957(TEXT("/Script/ALS_System"),
	Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h__Script_ALS_System_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSCharacterMovementComponent_h__Script_ALS_System_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
