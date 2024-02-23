// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RPG_AdrianMartinez : ModuleRules
{
	public RPG_AdrianMartinez(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
