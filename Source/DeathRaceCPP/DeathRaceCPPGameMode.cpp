// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeathRaceCPPGameMode.h"
#include "DeathRaceCPPPlayerController.h"

ADeathRaceCPPGameMode::ADeathRaceCPPGameMode()
{
	PlayerControllerClass = ADeathRaceCPPPlayerController::StaticClass();
}
