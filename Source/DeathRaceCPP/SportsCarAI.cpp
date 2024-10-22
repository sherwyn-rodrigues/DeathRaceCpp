// Fill out your copyright notice in the Description page of Project Settings.


#include "SportsCarAI.h"
#include "Road.h"
#include "ChaosVehicleMovementComponent.h"
#include "Components/SplineComponent.h"

ASportsCarAI::ASportsCarAI()
{
	// Left and right points on car for checking steering direction
	LeftPoint = CreateDefaultSubobject<USceneComponent>(TEXT("LeftPoint"));
	LeftPoint->SetupAttachment(RootComponent);
	RightPoint = CreateDefaultSubobject<USceneComponent>(TEXT("RightPoint"));
	RightPoint->SetupAttachment(RootComponent);
}


void ASportsCarAI::BeginPlay()
{
	Super::BeginPlay();

	// setting reference to Spline
	if (IsValid(Road))
	{
		SplineReference = Road->RoadSpline;
	}


	FTimerHandle MyTimerHandleSpeedControl;
	FTimerHandle MyTimerHandleSteerControl;
	
	//framerate independent function calls for performance reasons
	GetWorldTimerManager().SetTimer(MyTimerHandleSpeedControl, this, &ASportsCarAI::SpeedControl, 0.1f, true);
	GetWorldTimerManager().SetTimer(MyTimerHandleSteerControl, this, &ASportsCarAI::SteerControl, 0.05f, true);

	/*GetWorldTimerManager().SetTimer(MyTimerHandle, [this]()
		{
			SpeedControl(1);

		}, 0.2f, true);
	*/

}

void ASportsCarAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
	EndTargetPoint.Z += 300.0f;//for draw debug line
	DrawDebugLine(GetWorld(), TargetPoint, EndTargetPoint, FColor::Red, false, 3.f, 0, 10.0f);


	//increase the target spline distance as you go closer to change targetpoint as you move along the map
	if (FVector::Dist(TargetPoint, GetActorLocation()) < CheckGap)
	{
		DistanceAlongSpline += 300;
	}


	if (FVector::Dist(TargetPoint, RightPoint->GetComponentLocation()) < FVector::Dist(TargetPoint, LeftPoint->GetComponentLocation()))
	{
		AISteering(0.7f);
	}
	else
	{
		AISteering(-0.7f);
	}

}
