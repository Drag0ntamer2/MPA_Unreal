// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMPA_Unreal_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MPA_Unreal;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MPA_Unreal()
	{
		if (!Z_Registration_Info_UPackage__Script_MPA_Unreal.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MPA_Unreal",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x3C355060,
				0xB01A4F10,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MPA_Unreal.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MPA_Unreal.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MPA_Unreal(Z_Construct_UPackage__Script_MPA_Unreal, TEXT("/Script/MPA_Unreal"), Z_Registration_Info_UPackage__Script_MPA_Unreal, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x3C355060, 0xB01A4F10));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
