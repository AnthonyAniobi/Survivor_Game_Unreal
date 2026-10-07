using UnrealBuildTool;

public class TFCharacters : ModuleRules
{
    public TFCharacters(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "SlateCore", 
                "EnhancedInput",
            }
        );
    }
}