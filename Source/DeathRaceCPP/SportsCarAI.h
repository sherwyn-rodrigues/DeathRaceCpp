// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeathRaceCPPSportsCar.h"
#include "SportsCarAI.generated.h"

class ARoad;
class USplineComponent;
/**
 * 
 */
UCLASS()
class DEATHRACECPP_API ASportsCarAI : public ADeathRaceCPPSportsCar
{
	GENERATED_BODY()
	

private:


protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:

	ASportsCarAI();

	UPROPERTY(EditAnywhere)
	USceneComponent* LeftPoint;

	UPROPERTY(EditAnywhere)
	USceneComponent* RightPoint;

	UPROPERTY(EditAnywhere)
	ARoad* Road = nullptr;

	UPROPERTY(BlueprintReadOnly)
	USplineComponent* SplineReference;

	UFUNCTION()
	void SpeedControl();

	UFUNCTION()
	void SteerControl();
};
