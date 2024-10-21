// Fill out your copyright notice in the Description page of Project Settings.


#include "SportsCarAI.h"
#include "Road.h"
#include "ChaosVehicleMovementComponent.h"
#include "Components/SplineComponent.h"

ASportsCarAI::ASportsCarAI()
{
	LeftPoint = CreateDefaultSubobject<USceneComponent>(TEXT("LeftPoint"));
	RightPoint = CreateDefaultSubobject<USceneComponent>(TEXT("RightPoint"));

}


void ASportsCarAI::BeginPlay()
{
	Super::BeginPlay();

	// setting reference to Spline
	if (IsValid(Road))
	{
		SplineReference = Road->RoadSpline;
		UE_LOG(LogTemp, Warning, TEXT("Is Valid"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Is InValid"));
	}

	FTimerHandle MyTimerHandleSpeedControl;
	FTimerHandle MyTimerHandleSteerControl;
	
	GetWorldTimerManager().SetTimer(MyTimerHandleSpeedControl, this, &ASportsCarAI::SpeedControl, 0.1f, true);
	GetWorldTimerManager().SetTimer(MyTimerHandleSteerControl, this, &ASportsCarAI::SteerControl, 0.1f, true);
	/*GetWorldTimerManager().SetTimer(MyTimerHandle, [this]()
		{
			SpeedControl(1);

		}, 0.2f, true);
	*/

}

void ASportsCarAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//SpeedControl();
}


void ASportsCarAI::SpeedControl()
{
	// if speed of car is les then max speed then accelerate otherwise deaccelerate;
	float SelectAccelerationAmount = ((GetVehicleMovementComponent()->GetForwardSpeed()) * 0.036) < MaxAISpped ? 1.0f : 0.0f;
	AIThrottle(SelectAccelerationAmount);
}

void ASportsCarAI::SteerControl()
{
	if (SplineReference)
	{
		TargetPoint = SplineReference->GetLocationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World);

	}
	FVector EndTargetPoint = TargetPoint;
	EndTargetPoint.Z += 300.0f;

	DrawDebugLine(GetWorld(), TargetPoint, EndTargetPoint, FColor::Red, true, 10.f, 0, 10.0f);
}
