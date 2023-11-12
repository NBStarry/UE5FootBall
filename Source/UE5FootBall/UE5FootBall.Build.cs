// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5FootBall : ModuleRules
{
	public UE5FootBall(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", "Slate", "SlateCore", "UMG" });
    }
}
