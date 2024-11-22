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

	//For the front and back spawn points
	//added in this call because this is the parent of both ai as well as sports car 
	UPROPERTY(EditAnywhere)
	USceneComponent* FrontSpawnPoint;

	UPROPERTY(EditAnywhere)
	USceneComponent* BackSpawnPoint;

	UPROPERTY(EditAnywhere)
	USceneComponent* MidSpawnPoint;
};
