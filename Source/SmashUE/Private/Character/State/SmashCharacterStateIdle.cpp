// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/SmashCharacterStateIdle.h"

#include "Character/SmashCharacterStateID.h"


USmashCharacterStateIdle::USmashCharacterStateIdle()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USmashCharacterStateIdle::BeginPlay()
{
	Super::BeginPlay();
	
}

void USmashCharacterStateIdle::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

ESmashCharacterStateID USmashCharacterStateIdle::GetStateID()
{
	return ESmashCharacterStateID::Idle;
}

void USmashCharacterStateIdle::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Cyan,
		TEXT("Enter StateIdle"));
}

void USmashCharacterStateIdle::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateEnter(NextStateID);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		TEXT("Exit StateIdle"));
}
