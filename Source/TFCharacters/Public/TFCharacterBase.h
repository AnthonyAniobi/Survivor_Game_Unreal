// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TFCharacterBase.generated.h"

UCLASS()
class TFCHARACTERS_API ATFCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATFCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool CanCharacterJump() const;
	void HasJumped();
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
