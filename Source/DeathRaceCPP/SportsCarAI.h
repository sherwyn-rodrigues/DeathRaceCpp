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

	UPROPERTY(EditAnywhere, Category = "Steer Control")
	ARoad* Road = nullptr;

	UPROPERTY(BlueprintReadOnly)
	USplineComponent* SplineReference;

	/** For max speed of AI cars */
	UPROPERTY(EditAnywhere)
	float MaxAISpped = 50;

	UFUNCTION()
	void SpeedControl();

	UFUNCTION()
	void SteerControl();

	/** The distance along the spline from the start */
	UPROPERTY(EditAnywhere, Category = "Steer Control")
	float DistanceAlongSpline = 0;

	UPROPERTY(BlueprintReadOnly)
	FVector TargetPoint;
};
