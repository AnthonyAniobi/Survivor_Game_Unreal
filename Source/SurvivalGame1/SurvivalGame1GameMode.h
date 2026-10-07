// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SurvivalGame1GameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class ASurvivalGame1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	ASurvivalGame1GameMode();
};



