// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5FootBallGameMode.h"
#include "UE5FootBallPlayerController.h"
#include "UE5FootBallCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5FootBallGameMode::AUE5FootBallGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AUE5FootBallPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}