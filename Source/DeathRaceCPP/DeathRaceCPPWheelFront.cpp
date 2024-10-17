// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeathRaceCPPWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UDeathRaceCPPWheelFront::UDeathRaceCPPWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}