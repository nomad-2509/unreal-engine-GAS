// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAS_tutorialGameMode.h"
#include "GAS_tutorialCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAS_tutorialGameMode::AGAS_tutorialGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
