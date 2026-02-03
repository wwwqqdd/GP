// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ALSPlayerCameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeALSPlayerCameraManager() {}

// ********** Begin Cross Module References ********************************************************
ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSBaseCharacter_NoRegister();
ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSPlayerCameraManager();
ALS_SYSTEM_API UClass* Z_Construct_UClass_AALSPlayerCameraManager_NoRegister();
ALS_SYSTEM_API UClass* Z_Construct_UClass_UALSDebugComponent_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_ALS_System();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AALSPlayerCameraManager Function CalculateAxisIndependentLag *************
struct Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics
{
	struct ALSPlayerCameraManager_eventCalculateAxisIndependentLag_Parms
	{
		FVector CurrentLocation;
		FVector TargetLocation;
		FRotator CameraRotation;
		FVector LagSpeeds;
		float DeltaTime;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LagSpeeds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_CurrentLocation = { "CurrentLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCalculateAxisIndependentLag_Parms, CurrentLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCalculateAxisIndependentLag_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_CameraRotation = { "CameraRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCalculateAxisIndependentLag_Parms, CameraRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_LagSpeeds = { "LagSpeeds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCalculateAxisIndependentLag_Parms, LagSpeeds), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCalculateAxisIndependentLag_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCalculateAxisIndependentLag_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_CurrentLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_TargetLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_CameraRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_LagSpeeds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AALSPlayerCameraManager, nullptr, "CalculateAxisIndependentLag", Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::PropPointers), sizeof(Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::ALSPlayerCameraManager_eventCalculateAxisIndependentLag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04882401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::Function_MetaDataParams), Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::ALSPlayerCameraManager_eventCalculateAxisIndependentLag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AALSPlayerCameraManager::execCalculateAxisIndependentLag)
{
	P_GET_STRUCT(FVector,Z_Param_CurrentLocation);
	P_GET_STRUCT(FVector,Z_Param_TargetLocation);
	P_GET_STRUCT(FRotator,Z_Param_CameraRotation);
	P_GET_STRUCT(FVector,Z_Param_LagSpeeds);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=AALSPlayerCameraManager::CalculateAxisIndependentLag(Z_Param_CurrentLocation,Z_Param_TargetLocation,Z_Param_CameraRotation,Z_Param_LagSpeeds,Z_Param_DeltaTime);
	P_NATIVE_END;
}
// ********** End Class AALSPlayerCameraManager Function CalculateAxisIndependentLag ***************

// ********** Begin Class AALSPlayerCameraManager Function CustomCameraBehavior ********************
struct Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics
{
	struct ALSPlayerCameraManager_eventCustomCameraBehavior_Parms
	{
		float DeltaTime;
		FVector Location;
		FRotator Rotation;
		float FOV;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FOV;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCustomCameraBehavior_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCustomCameraBehavior_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCustomCameraBehavior_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_FOV = { "FOV", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventCustomCameraBehavior_Parms, FOV), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ALSPlayerCameraManager_eventCustomCameraBehavior_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ALSPlayerCameraManager_eventCustomCameraBehavior_Parms), &Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_FOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AALSPlayerCameraManager, nullptr, "CustomCameraBehavior", Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::PropPointers), sizeof(Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::ALSPlayerCameraManager_eventCustomCameraBehavior_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C80401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::Function_MetaDataParams), Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::ALSPlayerCameraManager_eventCustomCameraBehavior_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AALSPlayerCameraManager::execCustomCameraBehavior)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_FOV);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CustomCameraBehavior(Z_Param_DeltaTime,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_Out_FOV);
	P_NATIVE_END;
}
// ********** End Class AALSPlayerCameraManager Function CustomCameraBehavior **********************

// ********** Begin Class AALSPlayerCameraManager Function DrawDebugTargets ************************
struct ALSPlayerCameraManager_eventDrawDebugTargets_Parms
{
	FVector PivotTargetLocation;
};
static FName NAME_AALSPlayerCameraManager_DrawDebugTargets = FName(TEXT("DrawDebugTargets"));
void AALSPlayerCameraManager::DrawDebugTargets(FVector PivotTargetLocation)
{
	ALSPlayerCameraManager_eventDrawDebugTargets_Parms Parms;
	Parms.PivotTargetLocation=PivotTargetLocation;
	UFunction* Func = FindFunctionChecked(NAME_AALSPlayerCameraManager_DrawDebugTargets);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PivotTargetLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::NewProp_PivotTargetLocation = { "PivotTargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventDrawDebugTargets_Parms, PivotTargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::NewProp_PivotTargetLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AALSPlayerCameraManager, nullptr, "DrawDebugTargets", Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::PropPointers), sizeof(ALSPlayerCameraManager_eventDrawDebugTargets_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::Function_MetaDataParams), Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ALSPlayerCameraManager_eventDrawDebugTargets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AALSPlayerCameraManager Function DrawDebugTargets **************************

// ********** Begin Class AALSPlayerCameraManager Function GetCameraBehaviorParam ******************
struct Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics
{
	struct ALSPlayerCameraManager_eventGetCameraBehaviorParam_Parms
	{
		FName CurveName;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_CurveName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::NewProp_CurveName = { "CurveName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventGetCameraBehaviorParam_Parms, CurveName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventGetCameraBehaviorParam_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::NewProp_CurveName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AALSPlayerCameraManager, nullptr, "GetCameraBehaviorParam", Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::PropPointers), sizeof(Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::ALSPlayerCameraManager_eventGetCameraBehaviorParam_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::Function_MetaDataParams), Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::ALSPlayerCameraManager_eventGetCameraBehaviorParam_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AALSPlayerCameraManager::execGetCameraBehaviorParam)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_CurveName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCameraBehaviorParam(Z_Param_CurveName);
	P_NATIVE_END;
}
// ********** End Class AALSPlayerCameraManager Function GetCameraBehaviorParam ********************

// ********** Begin Class AALSPlayerCameraManager Function OnPossess *******************************
struct Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics
{
	struct ALSPlayerCameraManager_eventOnPossess_Parms
	{
		AALSBaseCharacter* NewCharacter;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewCharacter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::NewProp_NewCharacter = { "NewCharacter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALSPlayerCameraManager_eventOnPossess_Parms, NewCharacter), Z_Construct_UClass_AALSBaseCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::NewProp_NewCharacter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AALSPlayerCameraManager, nullptr, "OnPossess", Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::PropPointers), sizeof(Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::ALSPlayerCameraManager_eventOnPossess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::Function_MetaDataParams), Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::ALSPlayerCameraManager_eventOnPossess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AALSPlayerCameraManager::execOnPossess)
{
	P_GET_OBJECT(AALSBaseCharacter,Z_Param_NewCharacter);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPossess(Z_Param_NewCharacter);
	P_NATIVE_END;
}
// ********** End Class AALSPlayerCameraManager Function OnPossess *********************************

// ********** Begin Class AALSPlayerCameraManager **************************************************
void AALSPlayerCameraManager::StaticRegisterNativesAALSPlayerCameraManager()
{
	UClass* Class = AALSPlayerCameraManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CalculateAxisIndependentLag", &AALSPlayerCameraManager::execCalculateAxisIndependentLag },
		{ "CustomCameraBehavior", &AALSPlayerCameraManager::execCustomCameraBehavior },
		{ "GetCameraBehaviorParam", &AALSPlayerCameraManager::execGetCameraBehaviorParam },
		{ "OnPossess", &AALSPlayerCameraManager::execOnPossess },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AALSPlayerCameraManager;
UClass* AALSPlayerCameraManager::GetPrivateStaticClass()
{
	using TClass = AALSPlayerCameraManager;
	if (!Z_Registration_Info_UClass_AALSPlayerCameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ALSPlayerCameraManager"),
			Z_Registration_Info_UClass_AALSPlayerCameraManager.InnerSingleton,
			StaticRegisterNativesAALSPlayerCameraManager,
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
	return Z_Registration_Info_UClass_AALSPlayerCameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_AALSPlayerCameraManager_NoRegister()
{
	return AALSPlayerCameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AALSPlayerCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "ALSPlayerCameraManager.h" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControlledCharacter_MetaData[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBehavior_MetaData[] = {
		{ "Category", "ALS|Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmoothedPivotTarget_MetaData[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PivotLocation_MetaData[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetCameraLocation_MetaData[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetCameraRotation_MetaData[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugViewRotation_MetaData[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugViewOffset_MetaData[] = {
		{ "Category", "ALS|Camera" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ALSDebugComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ALSPlayerCameraManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ControlledCharacter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBehavior;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SmoothedPivotTarget;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PivotLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetCameraLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetCameraRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DebugViewRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DebugViewOffset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ALSDebugComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AALSPlayerCameraManager_CalculateAxisIndependentLag, "CalculateAxisIndependentLag" }, // 647582559
		{ &Z_Construct_UFunction_AALSPlayerCameraManager_CustomCameraBehavior, "CustomCameraBehavior" }, // 408685960
		{ &Z_Construct_UFunction_AALSPlayerCameraManager_DrawDebugTargets, "DrawDebugTargets" }, // 3584183955
		{ &Z_Construct_UFunction_AALSPlayerCameraManager_GetCameraBehaviorParam, "GetCameraBehaviorParam" }, // 175627784
		{ &Z_Construct_UFunction_AALSPlayerCameraManager_OnPossess, "OnPossess" }, // 1658147586
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AALSPlayerCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_ControlledCharacter = { "ControlledCharacter", nullptr, (EPropertyFlags)0x0114000000020005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AALSPlayerCameraManager, ControlledCharacter), Z_Construct_UClass_AALSBaseCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControlledCharacter_MetaData), NewProp_ControlledCharacter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_CameraBehavior = { "CameraBehavior", nullptr, (EPropertyFlags)0x01140000000a000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AALSPlayerCameraManager, CameraBehavior), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBehavior_MetaData), NewProp_CameraBehavior_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_SmoothedPivotTarget = { "SmoothedPivotTarget", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AALSPlayerCameraManager, SmoothedPivotTarget), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmoothedPivotTarget_MetaData), NewProp_SmoothedPivotTarget_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_PivotLocation = { "PivotLocation", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AALSPlayerCameraManager, PivotLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PivotLocation_MetaData), NewProp_PivotLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_TargetCameraLocation = { "TargetCameraLocation", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AALSPlayerCameraManager, TargetCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetCameraLocation_MetaData), NewProp_TargetCameraLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_TargetCameraRotation = { "TargetCameraRotation", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AALSPlayerCameraManager, TargetCameraRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetCameraRotation_MetaData), NewProp_TargetCameraRotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_DebugViewRotation = { "DebugViewRotation", nullptr, (EPropertyFlags)0x0020080000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AALSPlayerCameraManager, DebugViewRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugViewRotation_MetaData), NewProp_DebugViewRotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_DebugViewOffset = { "DebugViewOffset", nullptr, (EPropertyFlags)0x0020080000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AALSPlayerCameraManager, DebugViewOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugViewOffset_MetaData), NewProp_DebugViewOffset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_ALSDebugComponent = { "ALSDebugComponent", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AALSPlayerCameraManager, ALSDebugComponent), Z_Construct_UClass_UALSDebugComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ALSDebugComponent_MetaData), NewProp_ALSDebugComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AALSPlayerCameraManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_ControlledCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_CameraBehavior,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_SmoothedPivotTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_PivotLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_TargetCameraLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_TargetCameraRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_DebugViewRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_DebugViewOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AALSPlayerCameraManager_Statics::NewProp_ALSDebugComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AALSPlayerCameraManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AALSPlayerCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_ALS_System,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AALSPlayerCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AALSPlayerCameraManager_Statics::ClassParams = {
	&AALSPlayerCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AALSPlayerCameraManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AALSPlayerCameraManager_Statics::PropPointers),
	0,
	0x009003ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AALSPlayerCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AALSPlayerCameraManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AALSPlayerCameraManager()
{
	if (!Z_Registration_Info_UClass_AALSPlayerCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AALSPlayerCameraManager.OuterSingleton, Z_Construct_UClass_AALSPlayerCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AALSPlayerCameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AALSPlayerCameraManager);
AALSPlayerCameraManager::~AALSPlayerCameraManager() {}
// ********** End Class AALSPlayerCameraManager ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h__Script_ALS_System_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AALSPlayerCameraManager, AALSPlayerCameraManager::StaticClass, TEXT("AALSPlayerCameraManager"), &Z_Registration_Info_UClass_AALSPlayerCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AALSPlayerCameraManager), 3301528989U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h__Script_ALS_System_1541424581(TEXT("/Script/ALS_System"),
	Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h__Script_ALS_System_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_GameplayProject_Plugins_ALS_System_Source_ALS_System_Public_ALSPlayerCameraManager_h__Script_ALS_System_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
