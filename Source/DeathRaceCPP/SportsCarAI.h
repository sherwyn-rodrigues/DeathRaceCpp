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

	//location needs to be placed on the left side of car
	UPROPERTY(EditAnywhere)
	USceneComponent* LeftPoint;

	//location needs to be placed on the Right side of car
	UPROPERTY(EditAnywhere)
	USceneComponent* RightPoint;

	UPROPERTY(EditAnywhere, Category = "Steer Control")
	ARoad* Road = nullptr;

	UPROPERTY(BlueprintReadOnly)
	USplineComponent* SplineReference;

	/** For max speed of AI cars */
	UPROPERTY(EditAnywhere)
	float MaxAISpped = 60;

	UFUNCTION()
	void SpeedControl();

	UFUNCTION()
	void SteerControl();

	// The distance along the spline from the start 
	float DistanceAlongSpline = 0;

	//TargetPoint on the spline where the car is supposed to move or look towards
	FVector TargetPoint;

	//To check the distance between car and Targetpoint
	float CheckGap = 1000;

	UPROPERTY(EditAnywhere)
	float SteerAmount = 0.7;
};
