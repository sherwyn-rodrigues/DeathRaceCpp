// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeathRaceCPPWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UDeathRaceCPPWheelRear::UDeathRaceCPPWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}