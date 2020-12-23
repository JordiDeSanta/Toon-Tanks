// Fill out your copyright notice in the Description page of Project Settings.


#include "FireTask.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Pawns/BasePawn.h"

EBTNodeResult::Type UFireTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto Pawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PawnCasted = Cast<ABasePawn>(Pawn);
	
	PawnCasted->Fire();

	return EBTNodeResult::Succeeded;
}