// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidsManager.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values
ABoidsManager::ABoidsManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABoidsManager::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

// Called every frame
void ABoidsManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	for (ASingleBoid* Boid : BoidsCollection)
	{
		Boid->BoidRules(BoidsCollection);
	}
}

void ABoidsManager::Init()
{
	int counter = 0;

	while (counter < NbBoids)
	{
		FTransform BaseTransform = UKismetMathLibrary::MakeTransform(FVector(GetActorLocation() + FMath::VRand() * 150.0f), FRotator(0, 0, 0));
		ASingleBoid* Boid = Cast<ASingleBoid>(GetWorld()->SpawnActor(ASingleBoid::StaticClass(), &BaseTransform));
		if (Boid)
		{
			FVector RandomVelocity = FMath::VRand();
			Boid->Init(BaseTransform, RandomVelocity, CohesionFactor,AligmentFactor,SeparationFactor);
			BoidsCollection.Add(Boid);
		}
		
		counter++;
	}
}

