// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeathRaceCPPPawn.h"
#include "DeathRaceCPPSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class DEATHRACECPP_API ADeathRaceCPPSportsCar : public ADeathRaceCPPPawn
{
	GENERATED_BODY()
	
public:

	ADeathRaceCPPSportsCar();
};
