// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TFCharacterBase.h"
#include "TFPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class TFCHARACTERS_API ATFPlayerCharacter : public ATFCharacterBase
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
	UCameraComponent* ThirdPersonCamera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
	UCameraComponent* FirstPersonCamera;

#pragma region Input	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	UInputAction* ToggleCameraPerspective;
#pragma endregion Input
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	bool bInFirstPerson = true;
	
protected:
	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);
	void PlayerJump();
	void TogglePerspective();
	virtual void BeginPlay() override;

public:
	
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetThirdPersonCamera() const { return ThirdPersonCamera; }
	FORCEINLINE UCameraComponent* GetFirstPersonCamera() const { return FirstPersonCamera; }
	
	ATFPlayerCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
