// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SingleBoid.generated.h"

UCLASS()
class TP_BOIDS_API ASingleBoid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASingleBoid();
	void Init(FTransform Transform, FVector GivenVelocity, float CFactor, float AFactor, float SFactor);
	void BoidRules(TArray<ASingleBoid*> &BoidsList);
	void TraceCollision();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector Direction;
	float GoldenRatio = 1.618f;
	float NbTrace = 10.0f;
	float CohesionFactor;
	float AligmentFactor;
	float SeparationFactor;
	FHitResult Hit;
	FCollisionQueryParams TraceParams;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	float Speed = 300.0f;
	UPROPERTY(EditAnywhere)
	float MaxVisionAngle = 1000.0f;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;



};
