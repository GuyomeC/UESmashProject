// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/SmashCharacterStateRun.h"

#include "Character/SmashCharacter.h"
#include "Character/SmashCharacterStateID.h"
#include "Character/SmashCharacterStateMachine.h"
#include "GameFramework/CharacterMovementComponent.h"

USmashCharacterStateRun::USmashCharacterStateRun()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USmashCharacterStateRun::BeginPlay()
{
	Super::BeginPlay();
	MoveSpeedMax = 600.f;
}

void USmashCharacterStateRun::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

ESmashCharacterStateID USmashCharacterStateRun::GetStateID()
{
	return ESmashCharacterStateID::Run;
}

void USmashCharacterStateRun::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Cyan,
		TEXT("Enter StateRun"));

	Character->GetCharacterMovement()->MaxWalkSpeed = MoveSpeedMax;

	Character->PlayAnimMontage(AnimRun);
}

void USmashCharacterStateRun::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateEnter(NextStateID);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		TEXT("Exit StateRun"));
}

void USmashCharacterStateRun::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	
	if (FMath::Abs(Character->GetInputMoveX()) < Settings->InputMoveXThreshold)
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Idle);
	}
	else
	{
		Character->SetOrientX(Character->GetInputMoveX());
		Character->AddMovementInput(FVector::ForwardVector, Character->GetOrientX());
	}
	MoveForward(Character->GetOrientX());
}

void USmashCharacterStateRun::MoveForward(float Value)
{
	FVector MoveDirection = FVector(1.f, 0.f, 0.f);
	Character->AddMovementInput(MoveDirection, Value);
}