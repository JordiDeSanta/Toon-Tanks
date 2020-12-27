// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void LaunchProjectile(float Speed);

	void OnTimerExpire();

	UPROPERTY(EditAnywhere, Category = "Damage")
		float ProjectileDamage = 20.f;

	// Sounds
	UPROPERTY(EditAnywhere, Category = "Sound")
		class USoundWave* ShootInit = nullptr;
	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundWave* ShootHit = nullptr;

private:
	class UProjectileMovementComponent* ProjectileMovement = nullptr;

	// Mesh component
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* CollisionMesh = nullptr;

	// Particle components
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UParticleSystemComponent* LaunchBlast = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* ImpactBlast = nullptr;
};
