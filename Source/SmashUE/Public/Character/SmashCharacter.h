// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SmashCharacterSettings.h"
#include "GameFramework/Character.h"
#include "SmashCharacter.generated.h"

class USmashCharacterStateMachine;
class USmashCharacterInputData;

UCLASS()
class SMASHUE_API ASmashCharacter : public ACharacter
{
	GENERATED_BODY()

#pragma region Unreal Default
public:
	ASmashCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
#pragma endregion Unreal Default

#pragma region Orient

public:
	float GetOrientX() const;

	void SetOrientX(float NewOrientX);

protected:
	UPROPERTY(BlueprintReadOnly)
	float OrientX = 1.f;

	void RotateMeshUsingOrientX() const;

#pragma endregion Orient

#pragma region State Machine
	
public:
	void CreateStateMachine();

	void InitStateMachine();

	void TickStateMachine(float DeltaTime) const;

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USmashCharacterStateMachine> StateMachine;

#pragma endregion State Machine

#pragma region Inputs Data / Mapping Context
public:
	UPROPERTY()
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY()
	TObjectPtr<USmashCharacterInputData> InputData;

protected:
	void SetupMappingContextIntoController() const;

	#pragma endregion Inputs Data / Mapping Context
	
};