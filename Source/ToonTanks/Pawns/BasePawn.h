// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"


UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// Projectile
	UPROPERTY(EditAnywhere, Category = "Projectile")
		TSubclassOf<class AProjectile> ProjectileBlueprint = nullptr;
	UPROPERTY(EditAnywhere, Category = "Projectile")
		float LaunchSpeed = 4000.f;
	UPROPERTY(EditAnywhere, Category = "Projectile")
		float ReloadTime = 1.5;

	UFUNCTION(BlueprintImplementableEvent)
		void OnDeath();

	void Fire();

	// Health
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
		float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
		float MaxHealth = 100.f;

	// Necessary components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAcces = "true"))
		class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAcces = "true"))
		class UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAcces = "true"))
		UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAcces = "true"))
		class USceneComponent* ProjectileSpawnPoint;

private:
	bool bCanShoot = true;

	void Reload();
};
