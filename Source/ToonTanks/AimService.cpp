// Fill out your copyright notice in the Description page of Project Settings.


#include "AimService.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Pawns/BasePawn.h"

void UAimService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// Getting pawn
	auto Pawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PawnCasted = Cast<ABasePawn>(Pawn);

	// PLayer reference
	auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();

	// Aim to the location
	if (!Player) { return; };
	PawnCasted->RotateTurret(Player->GetActorLocation());
	

}