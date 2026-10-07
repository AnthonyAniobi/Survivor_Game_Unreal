// Fill out your copyright notice in the Description page of Project Settings.


#include "TFCharacterBase.h"


// Sets default values
ATFCharacterBase::ATFCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATFCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ATFCharacterBase::CanCharacterJump() const
{
	return CanJump();
}

void ATFCharacterBase::HasJumped()
{
}

// Called every frame
void ATFCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATFCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

