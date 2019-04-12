// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface.h"
#include "CustomPickupActorInterface.generated.h"

/**
 * The interface you will use to communicate between CustomMotionController and PickupCube.
 */
UINTERFACE(Blueprintable)
class PROJECT1_API UCustomPickupActorInterface : public UInterface
{
	GENERATED_BODY()
};

class PROJECT1_API ICustomPickupActorInterface
{
	GENERATED_BODY()

public:

	//classes using this interface must implement Pickup (optional)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Grab Handling")
		void Pickup(USceneComponent* AttachTo);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Grab Handling")
		void Drop();
};