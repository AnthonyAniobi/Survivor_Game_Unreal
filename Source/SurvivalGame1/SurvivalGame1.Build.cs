// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SurvivalGame1 : ModuleRules
{
	public SurvivalGame1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"SurvivalGame1",
			"SurvivalGame1/Variant_Platforming",
			"SurvivalGame1/Variant_Platforming/Animation",
			"SurvivalGame1/Variant_Combat",
			"SurvivalGame1/Variant_Combat/AI",
			"SurvivalGame1/Variant_Combat/Animation",
			"SurvivalGame1/Variant_Combat/Gameplay",
			"SurvivalGame1/Variant_Combat/Interfaces",
			"SurvivalGame1/Variant_Combat/UI",
			"SurvivalGame1/Variant_SideScrolling",
			"SurvivalGame1/Variant_SideScrolling/AI",
			"SurvivalGame1/Variant_SideScrolling/Gameplay",
			"SurvivalGame1/Variant_SideScrolling/Interfaces",
			"SurvivalGame1/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
