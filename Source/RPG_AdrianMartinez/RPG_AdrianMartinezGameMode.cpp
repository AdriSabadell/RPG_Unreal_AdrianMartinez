// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPG_AdrianMartinezGameMode.h"
#include "RPG_AdrianMartinezPlayerController.h"
#include "RPG_AdrianMartinezCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPG_AdrianMartinezGameMode::ARPG_AdrianMartinezGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARPG_AdrianMartinezPlayerController::StaticClass();

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