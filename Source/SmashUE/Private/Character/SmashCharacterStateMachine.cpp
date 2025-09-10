﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SmashCharacterStateMachine.h"

#include "SmashCharacterState.h"
#include "Character/SmashCharacter.h"
#include "Character/SmashCharacterStateID.h"

void USmashCharacterStateMachine::Init(ASmashCharacter* InCharacter)
{
	Character = InCharacter;
	FindStates();
	InitStates();
}

ASmashCharacter* USmashCharacterStateMachine::GetCharacter() const
{
	return Character;
}

void USmashCharacterStateMachine::FindStates()
{
	TArray<UActorComponent*> FoundComponents = Character->K2_GetComponentsByClass(USmashCharacterState::StaticClass());
	for (UActorComponent* StateComponent : FoundComponents)
	{
		USmashCharacterState* State = Cast<USmashCharacterState>(StateComponent);
		if (State == nullptr) continue;
		if (State->GetStateID() == ESmashCharacterStateID::None) continue;

		AllState.Add(State);
	}
}

void USmashCharacterStateMachine::InitStates()
{
	for (USmashCharacterState* State : AllState)
	{
		State->StateInit(this);
	}
}