// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GridTemplate : ModuleRules
{
	public GridTemplate(ReadOnlyTargetRules Target) : base(Target)
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

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			
		});

		PublicIncludePaths.AddRange(new string[] {
			"GridTemplate",
			"GridTemplate/Variant_Platforming",
			"GridTemplate/Variant_Platforming/Animation",
			"GridTemplate/Variant_Combat",
			"GridTemplate/Variant_Combat/AI",
			"GridTemplate/Variant_Combat/Animation",
			"GridTemplate/Variant_Combat/Gameplay",
			"GridTemplate/Variant_Combat/Interfaces",
			"GridTemplate/Variant_Combat/UI",
			"GridTemplate/Variant_SideScrolling",
			"GridTemplate/Variant_SideScrolling/AI",
			"GridTemplate/Variant_SideScrolling/Gameplay",
			"GridTemplate/Variant_SideScrolling/Interfaces",
			"GridTemplate/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
