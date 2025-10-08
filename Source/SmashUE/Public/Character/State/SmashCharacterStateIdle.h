﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/SmashCharacterState.h"
#include "SmashCharacterStateIdle.generated.h"


UCLASS(ClassGroup=(SmashCharacterState), meta=(BlueprintSpawnableComponent))
class SMASHUE_API USmashCharacterStateIdle : public USmashCharacterState
{
	GENERATED_BODY()

public:
	
	USmashCharacterStateIdle();
	virtual ESmashCharacterStateID GetStateID() override;

	
	virtual void StateEnter(ESmashCharacterStateID PreviousStateID) override;

	virtual void StateExit(ESmashCharacterStateID NextStateID) override;

	virtual void StateTick(float DeltaTime) override;

	UFUNCTION()
	void OnInputMoveXFast(float CharaInputMoveX);

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* AnimIdle;

public:
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
