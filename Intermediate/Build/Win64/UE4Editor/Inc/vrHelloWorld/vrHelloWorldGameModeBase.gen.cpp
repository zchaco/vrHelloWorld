// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "vrHelloWorld/vrHelloWorldGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodevrHelloWorldGameModeBase() {}
// Cross Module References
	VRHELLOWORLD_API UClass* Z_Construct_UClass_AvrHelloWorldGameModeBase_NoRegister();
	VRHELLOWORLD_API UClass* Z_Construct_UClass_AvrHelloWorldGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_vrHelloWorld();
// End Cross Module References
	void AvrHelloWorldGameModeBase::StaticRegisterNativesAvrHelloWorldGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AvrHelloWorldGameModeBase_NoRegister()
	{
		return AvrHelloWorldGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AvrHelloWorldGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AvrHelloWorldGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_vrHelloWorld,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AvrHelloWorldGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "vrHelloWorldGameModeBase.h" },
		{ "ModuleRelativePath", "vrHelloWorldGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AvrHelloWorldGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AvrHelloWorldGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AvrHelloWorldGameModeBase_Statics::ClassParams = {
		&AvrHelloWorldGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AvrHelloWorldGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AvrHelloWorldGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AvrHelloWorldGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AvrHelloWorldGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AvrHelloWorldGameModeBase, 3609089168);
	template<> VRHELLOWORLD_API UClass* StaticClass<AvrHelloWorldGameModeBase>()
	{
		return AvrHelloWorldGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AvrHelloWorldGameModeBase(Z_Construct_UClass_AvrHelloWorldGameModeBase, &AvrHelloWorldGameModeBase::StaticClass, TEXT("/Script/vrHelloWorld"), TEXT("AvrHelloWorldGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AvrHelloWorldGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
