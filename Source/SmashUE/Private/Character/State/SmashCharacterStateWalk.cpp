// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/SmashCharacterStateWalk.h"

#include "Character/SmashCharacterStateID.h"


USmashCharacterStateWalk::USmashCharacterStateWalk()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USmashCharacterStateWalk::BeginPlay()
{
	Super::BeginPlay();
}

void USmashCharacterStateWalk::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

ESmashCharacterStateID USmashCharacterStateWalk::GetStateID()
{
	return ESmashCharacterStateID::Walk;
}