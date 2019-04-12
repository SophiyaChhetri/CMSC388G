// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomMotionController.h"
#include "CustomPickupActorInterface.h"
#include "Components/SplineMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACustomMotionController::ACustomMotionController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ACustomMotionController::ClearArc()
{
	//TODO - Clear blue laser arc every frame
	USplineComponent* ArcSpline = FindComponentByClass <USplineComponent>();
	//USplineMeshComponent* splineMeshes = FindComponentByClass <UActorComponent>();
	TArray<USplineMeshComponent*> SplineMeshes;
	GetComponents(SplineMeshes, true);


	for (USplineMeshComponent* a : SplineMeshes) {
		a->DestroyComponent();
	}

	ArcSpline->ClearSplinePoints(true);


}

AActor* ACustomMotionController::GetActorNearHand()
{
	USphereComponent* GrabSphere = FindComponentByClass<USphereComponent>();
	AActor* NearestOverlappingActor = nullptr;
	float NearestOverlap = 10000;
	FVector location = GrabSphere->GetComponentLocation();
	TArray<AActor*> overlappingActors;
	GrabSphere->GetOverlappingActors(overlappingActors, nullptr);
	//GetComponents(overlappingActors, true);

	for (AActor* actorElem : overlappingActors)
	{
		FVector ActorLocation = actorElem->GetActorLocation();
		float VectorLength = UKismetMathLibrary::VSize(ActorLocation - location);
		
		if (UKismetSystemLibrary::DoesImplementInterface(actorElem, UCustomPickupActorInterface::StaticClass()) == true)
		{
			if (VectorLength < NearestOverlap)		
			{
				//set nearest overlap to vectorlength
				NearestOverlap = VectorLength;
				NearestOverlappingActor = actorElem;
			}
		}
		
	}
	//return nearest overlapping actor
	return NearestOverlappingActor;
}

FTeleportDestinationTransform ACustomMotionController::GetTeleportDestination()
{
	UStaticMeshComponent* TeleportCylinder = FindComponentByClass<UStaticMeshComponent>();
	FVector TeleportLocation = TeleportCylinder->GetComponentLocation();

	FVector DevicePosition;
	FRotator DeviceRotation;
	UHeadMountedDisplayFunctionLibrary::GetOrientationAndPosition(DeviceRotation, DevicePosition);
	const FVector IgnoreHeightDifferenceVector = FVector(DevicePosition.X, DevicePosition.Y, 0);

	FRotator TeleportRotator;
	FVector RotatedVector = TeleportRotator.RotateVector(IgnoreHeightDifferenceVector);

	FVector DiffFromCamera = TeleportLocation - RotatedVector;

	FTeleportDestinationTransform TeleportDestinationTransform;

	TeleportDestinationTransform.DestinationLocation = DiffFromCamera;
	TeleportDestinationTransform.DestinationRotation = TeleportRotator;

	return TeleportDestinationTransform;
}
