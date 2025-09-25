// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/SmashCharacterStateWalk.h"

#include "Character/SmashCharacter.h"
#include "Character/SmashCharacterStateID.h"
#include "Character/SmashCharacterStateMachine.h"
#include "GameFramework/CharacterMovementComponent.h"


USmashCharacterStateWalk::USmashCharacterStateWalk()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USmashCharacterStateWalk::BeginPlay()
{
	Super::BeginPlay();
	MoveSpeedMax = 200.f;
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

void USmashCharacterStateWalk::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Cyan,
		TEXT("Enter StateWalk"));

	Character->GetCharacterMovement()->MaxWalkSpeed = MoveSpeedMax;

	Character->PlayAnimMontage(AnimWalk);
}

void USmashCharacterStateWalk::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateEnter(NextStateID);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		TEXT("Exit StateWalk"));
}

void USmashCharacterStateWalk::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	GEngine->AddOnScreenDebugMessage(
		-1,
		0.1f,
		FColor::Green,
		TEXT("Tick StateWalk"));
	MoveForward(Character->GetOrientX());

	if (FMath::Abs(Character->GetInputMoveX()) < 0.1f)
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Idle);
	}
	else
	{
		Character->SetOrientX(Character->GetInputMoveX());
		Character->AddMovementInput(FVector::ForwardVector, Character->GetOrientX());
	}
}

void USmashCharacterStateWalk::MoveForward(float Value)
{
	FVector MoveDirection = FVector(1.f, 0.f, 0.f);
	Character->AddMovementInput(MoveDirection, Value);
}
