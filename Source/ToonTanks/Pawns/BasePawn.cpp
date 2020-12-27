// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "ToonTanks/Projectile.h"
#include "Math/UnrealMathUtility.h"

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
	BaseMesh->SetupAttachment(RootComponent);
	TurretMesh->SetupAttachment(BaseMesh);
	ProjectileSpawnPoint->SetupAttachment(TurretMesh, TEXT("ProjectileSocket"));
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentHealth = MaxHealth;
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

void ABasePawn::Fire()
{
	if (bCanShoot)
	{
		auto ActiveProjectile = GetWorld()->SpawnActor<class AProjectile>(
			ProjectileBlueprint,
			ProjectileSpawnPoint->GetComponentTransform()
			);

		ActiveProjectile->LaunchProjectile(LaunchSpeed);

		bCanShoot = false;

		// Timer to reload
		FTimerHandle Timer;
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &ABasePawn::Reload, ReloadTime, false);
	}
}

void ABasePawn::Reload()
{
	bCanShoot = true;
}


float ABasePawn::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp<int32>(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath();
	}

	return DamageToApply;
}

