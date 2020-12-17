// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Declare components by sub-objects
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));
	ProjectileSpawnPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileSpawnPoint"));

	// Root and attachments
	SetRootComponent(CapsuleComp);
	BaseMesh->SetupAttachment(CapsuleComp);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

