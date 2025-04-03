// Fill out your copyright notice in the Description page of Project Settings.


#include "SingleBoid.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values
ASingleBoid::ASingleBoid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Engine/BasicShapes/Cone"));
	UStaticMesh* Asset = MeshAsset.Object;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	Mesh->SetStaticMesh(Asset);
	Mesh->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionProfileName("NoCollision");
}

void ASingleBoid::Init(FTransform Transform, FVector GivenDirection, float CFactor, float AFactor, float SFactor)
{
	SetActorTransform(Transform);
	Direction = GivenDirection;
	CohesionFactor = CFactor;
	AligmentFactor = AFactor;
	SeparationFactor = SFactor;

	TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.AddIgnoredActor(this);
}

void ASingleBoid::BoidRules(TArray<ASingleBoid*>& BoidsList)
{
	int NeighborCount = 0;
	float DT = GetWorld()->GetDeltaSeconds();
	//FVector Direction= FVector::ZeroVector;

	FVector Alignment = FVector::ZeroVector;
	FVector Separate = FVector::ZeroVector;
	FVector Cohesion = FVector::ZeroVector;

	for(ASingleBoid* OtherBoid : BoidsList)
	{
		/* Check if the iterated boid is not the actual one */
		if (OtherBoid == this) continue;

		Alignment += OtherBoid->Direction;

		float Distance = FVector::Dist(GetActorLocation(), OtherBoid->GetActorLocation());
		//float AngleView = UKismetMathLibrary::DegAcos(UKismetMathLibrary::Dot_VectorVector(GetActorForwardVector(), OtherBoid->GetActorLocation() - GetActorLocation()));

		/* Check if the iterated boid is in the field of view of our actual boid */
		if (Distance < MaxVisionAngle)
		{
			float Ratio = Distance / MaxVisionAngle;
			Separate += ((Direction + (GetActorLocation() - OtherBoid->GetActorLocation()).GetSafeNormal()) * Ratio).GetSafeNormal();
			Cohesion += OtherBoid->GetActorLocation();
			NeighborCount++;
		}
	}

	/* Calculate cohesion in function of the number of neighbor */
	if (NeighborCount > 0)
	{
		Cohesion = (Cohesion / NeighborCount) - GetActorLocation();
	}
	
	Alignment.Normalize();
	Cohesion.Normalize();

	/* Apply Boid's rules */
	Direction += Cohesion * CohesionFactor + Alignment * AligmentFactor + Separate * SeparationFactor;
	Direction.Normalize();
	
}

void ASingleBoid::TraceCollision() 
{
	for (float i = 1.0f; i < NbTrace + 1; i++)
	{
		float T = 1.0f - 2.0f * (i/NbTrace);
		float Theta = UKismetMathLibrary::DegAcos(T);
		float Phi = 360.0f * GoldenRatio * i;
		FVector Point = FVector(UKismetMathLibrary::DegSin(Theta) * UKismetMathLibrary::DegCos(Phi), UKismetMathLibrary::DegSin(Theta) * UKismetMathLibrary::DegSin(Phi), UKismetMathLibrary::DegCos(Theta));
		GetWorld()->LineTraceSingleByChannel(Hit, GetActorLocation(), GetActorLocation() + Point * 100.0f, ECC_Visibility, TraceParams);
	}
}

// Called when the game starts or when spawned
void ASingleBoid::BeginPlay()
{

	Super::BeginPlay();
	
}

// Called every frame
void ASingleBoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation() + Direction * DeltaTime * 100.0f;
	SetActorRotation(Direction.Rotation());
	SetActorLocation(NewLocation);
	TraceCollision();
	
	if (Hit.bBlockingHit)
	{
		DrawDebugLine(
		GetWorld(), 
		GetActorLocation(), 
		Hit.ImpactPoint, 
		FColor::Red, 
		false, 
		0.1f, 
		0, 
		1.0f
		);
		UE_LOG(LogTemp, Display, TEXT("%s"), *Hit.GetActor()->GetName());
		Direction += FVector(Hit.ImpactPoint).GetSafeNormal();
		//Direction = UKismetMathLibrary::GetReflectionVector(Direction,Hit.ImpactNormal);
		Hit.Reset();
	}
}

