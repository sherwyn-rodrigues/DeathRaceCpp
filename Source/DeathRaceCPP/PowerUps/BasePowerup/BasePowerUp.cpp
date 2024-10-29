// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRaceCPP/PowerUps/BasePowerup/BasePowerUp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ABasePowerUp::ABasePowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = Mesh;
	Mesh->SetCollisionProfileName(TEXT("NoCollision"));
	Mesh->SetGenerateOverlapEvents(false);
	Mesh->SetSimulatePhysics(false);

	//SphereCollider
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	SphereCollider->SetGenerateOverlapEvents(true);
	SphereCollider->SetSimulatePhysics(false);
	SphereCollider->InitSphereRadius(100.0f);

}

// Called when the game starts or when spawned
void ABasePowerUp::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasePowerUp::OnPick()
{
}

void ABasePowerUp::OnDrop()
{
}

void ABasePowerUp::OnUse()
{
}

// Called every frame
void ABasePowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

