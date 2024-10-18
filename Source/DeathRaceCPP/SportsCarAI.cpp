// Fill out your copyright notice in the Description page of Project Settings.


#include "SportsCarAI.h"
#include "Road.h"

void ASportsCarAI::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle MyTimerHandle;


	/*
	GetWorldTimerManager().SetTimer(MyTimerHandle, this, &ASportsCarAI::SpeedControl, 001f, true);
	GetWorldTimerManager().SetTimer(MyTimerHandle, [this]()
		{
			SpeedControl(1);

		}, 0.2f, true);
	*/

}

void ASportsCarAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SpeedControl();
}

ASportsCarAI::ASportsCarAI()
{
	LeftPoint = CreateDefaultSubobject<USceneComponent>(TEXT("LeftPoint"));
	RightPoint = CreateDefaultSubobject<USceneComponent>(TEXT("RightPoint"));

	if (IsValid(Road))
	{
		SplineReference = Road->RoadSpline;
	}
}

void ASportsCarAI::SpeedControl()
{
	AIThrottle(1.0f);
}

void ASportsCarAI::SteerControl()
{

}
