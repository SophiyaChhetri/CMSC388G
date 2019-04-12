// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupCube.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/StaticMesh.h"

// Sets default values
APickupCube::APickupCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Mesh"));
	UStaticMesh* ObjectRef = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL,
		TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'")));
	MeshComponent->SetStaticMesh(ObjectRef);

	MeshComponent->SetRelativeScale3D(FVector(0.2f));

	//TODO - Set up Physics on the cube.
	MeshComponent->SetSimulatePhysics(true);
}

void APickupCube::Pickup_Implementation(USceneComponent* AttachTo)
{
	//UStaticMeshComponent* PickUp = FindComponentByClass<UStaticMeshComponent>();
	MeshComponent->SetSimulatePhysics(false);
	USceneComponent* target = GetRootComponent();
	target->AttachToComponent(AttachTo, FAttachmentTransformRules::KeepWorldTransform);
	//TODO - Implement Pickup call
}

void APickupCube::Drop_Implementation()
{
	//UStaticMeshComponent* Drop = FindComponentByClass<UStaticMeshComponent>();
	//TODO - Implement Drop Call
	MeshComponent->SetSimulatePhysics(true);
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}
