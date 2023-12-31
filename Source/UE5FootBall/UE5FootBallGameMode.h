// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "UE5FootBallGameMode.generated.h"

UCLASS(minimalapi)
class AUE5FootBallGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUE5FootBallGameMode();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UClassNames)
	TSubclassOf<UUserProfile> UPBlueprintClassName;
};



