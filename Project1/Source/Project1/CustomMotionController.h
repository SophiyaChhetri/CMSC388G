// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "CustomMotionController.generated.h"



USTRUCT(Blueprintable)
struct FTeleportDestinationTransform
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Transform")
		FVector DestinationLocation;
	UPROPERTY(BlueprintReadWrite, Category = "Transform")
		FRotator DestinationRotation;
};

UCLASS(Abstract)
class PROJECT1_API ACustomMotionController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACustomMotionController();

	UFUNCTION(BlueprintCallable, Category = "Teleporation")
		void ClearArc();

	UFUNCTION(BlueprintCallable, Category = "Grab Handling")
		AActor* GetActorNearHand();

	UFUNCTION(BlueprintCallable, Category = "Teleportation")
		virtual FTeleportDestinationTransform GetTeleportDestination(); /*PURE_VIRTUAL(ACustomMotionController, UStaticMeshComponent * TeleportCylinder = FindComponentByClass<UStaticMeshComponent>();
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

	return TeleportDestinationTransform;);*/

};

