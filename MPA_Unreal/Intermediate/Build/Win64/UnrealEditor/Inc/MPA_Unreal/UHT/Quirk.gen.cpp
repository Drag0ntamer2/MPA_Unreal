// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MPA_Unreal/Quirk.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuirk() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	MPA_UNREAL_API UClass* Z_Construct_UClass_UQuirk();
	MPA_UNREAL_API UClass* Z_Construct_UClass_UQuirk_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MPA_Unreal();
// End Cross Module References
	void UQuirk::StaticRegisterNativesUQuirk()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuirk);
	UClass* Z_Construct_UClass_UQuirk_NoRegister()
	{
		return UQuirk::StaticClass();
	}
	struct Z_Construct_UClass_UQuirk_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Category;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Section_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Section;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuirk_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_MPA_Unreal,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuirk_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuirk_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Quirk.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Quirk.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuirk_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "Quirk" },
		{ "ModuleRelativePath", "Quirk.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuirk_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuirk, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuirk_Statics::NewProp_Name_MetaData), Z_Construct_UClass_UQuirk_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuirk_Statics::NewProp_Category_MetaData[] = {
		{ "Category", "Quirk" },
		{ "ModuleRelativePath", "Quirk.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuirk_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuirk, Category), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuirk_Statics::NewProp_Category_MetaData), Z_Construct_UClass_UQuirk_Statics::NewProp_Category_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuirk_Statics::NewProp_Section_MetaData[] = {
		{ "Category", "Quirk" },
		{ "ModuleRelativePath", "Quirk.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuirk_Statics::NewProp_Section = { "Section", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuirk, Section), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuirk_Statics::NewProp_Section_MetaData), Z_Construct_UClass_UQuirk_Statics::NewProp_Section_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuirk_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuirk_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuirk_Statics::NewProp_Category,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuirk_Statics::NewProp_Section,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuirk_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuirk>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuirk_Statics::ClassParams = {
		&UQuirk::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UQuirk_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuirk_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuirk_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuirk_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuirk_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UQuirk()
	{
		if (!Z_Registration_Info_UClass_UQuirk.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuirk.OuterSingleton, Z_Construct_UClass_UQuirk_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UQuirk.OuterSingleton;
	}
	template<> MPA_UNREAL_API UClass* StaticClass<UQuirk>()
	{
		return UQuirk::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuirk);
	UQuirk::~UQuirk() {}
	struct Z_CompiledInDeferFile_FID_github_MPA_Unreal_MPA_Unreal_Source_MPA_Unreal_Quirk_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_github_MPA_Unreal_MPA_Unreal_Source_MPA_Unreal_Quirk_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UQuirk, UQuirk::StaticClass, TEXT("UQuirk"), &Z_Registration_Info_UClass_UQuirk, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuirk), 1112971856U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_github_MPA_Unreal_MPA_Unreal_Source_MPA_Unreal_Quirk_h_1127637085(TEXT("/Script/MPA_Unreal"),
		Z_CompiledInDeferFile_FID_github_MPA_Unreal_MPA_Unreal_Source_MPA_Unreal_Quirk_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_github_MPA_Unreal_MPA_Unreal_Source_MPA_Unreal_Quirk_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
