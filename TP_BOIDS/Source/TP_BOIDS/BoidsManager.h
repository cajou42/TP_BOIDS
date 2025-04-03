// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SingleBoid.h"
#include "BoidsManager.generated.h"

UCLASS()
class TP_BOIDS_API ABoidsManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoidsManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Init();

	UPROPERTY()
	TArray<ASingleBoid*> BoidsCollection;
	UPROPERTY(EditAnywhere)
	int NbBoids = 50;

	UPROPERTY(EditAnywhere)
	float CohesionFactor = 100.0f;
	UPROPERTY(EditAnywhere)
	float AligmentFactor = 0.5f;
	UPROPERTY(EditAnywhere)
	float SeparationFactor = 10.0f;
};
