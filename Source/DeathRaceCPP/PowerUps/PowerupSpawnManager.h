// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerupSpawnManager.generated.h"

UCLASS()
class DEATHRACECPP_API APowerupSpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerupSpawnManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Spawning", meta = (MakeEditWidget = "true"))
	TArray<FVector> SpawnPoints;

	//UPROPERTY(EditAnywhere, Category = "Spawning")
	//TArray<UBasePowerups> Powerups;

};
