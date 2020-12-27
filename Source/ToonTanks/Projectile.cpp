// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/BasePawn.h"


// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Components
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollisionMesh"));
	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("LaunchParticles"));
	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ImpactParticles"));

	// Setting components
	SetRootComponent(CollisionMesh);
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform, TEXT("ImpactSocket"));
	LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform, TEXT("BlastSocket"));
	ProjectileMovement->bAutoActivate = false;
	ImpactBlast->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	// Setting hit option
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	// Hide launch particles and mesh and show impact effect
	ImpactBlast->Activate();
	LaunchBlast->Deactivate();
	CollisionMesh->DestroyComponent();

	UGameplayStatics::ApplyDamage(
		OtherActor,
		ProjectileDamage,
		GetInstigatorController(),
		GetOwner(),
		UDamageType::StaticClass()
	);

	// Timer to destroy the projectile
	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AProjectile::OnTimerExpire, 0.4, false);
}

void AProjectile::LaunchProjectile(float Speed)
{
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
}

void AProjectile::OnTimerExpire()
{
	Destroy();
}



