// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomPickupActorInterface.h"
#include "ConstructorHelpers.h"
#include "PickupCube.generated.h"

UCLASS()
class PROJECT1_API APickupCube : public AActor, public ICustomPickupActorInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupCube();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MyCategory")
		void Pickup(USceneComponent* AttachTo);
	virtual void Pickup_Implementation(USceneComponent* AttachTo) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MyCategory")
		void Drop();
	virtual void Drop_Implementation() override;

protected:

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComponent;
};
