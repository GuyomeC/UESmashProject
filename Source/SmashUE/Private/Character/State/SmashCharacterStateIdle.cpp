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
