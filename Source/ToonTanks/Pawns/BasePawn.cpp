// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ABasePawn::ABasePawn()
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
	TurretMesh->SetupAttachment(BaseMesh, TEXT("TurretSocket"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh, TEXT("ProjectileSocket"));
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

