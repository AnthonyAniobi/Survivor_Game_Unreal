// Fill out your copyright notice in the Description page of Project Settings.


#include "TFPlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ATFPlayerCharacter::ATFPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;
	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Third Person Camera"));
	ThirdPersonCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	ThirdPersonCamera->bUsePawnControlRotation = false;
	ThirdPersonCamera->Deactivate();
	ThirdPersonCamera->bAutoActivate = false;
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCamera->SetupAttachment(GetMesh(), "head");
	FirstPersonCamera->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	FirstPersonCamera->SetRelativeLocation(FVector(15, 20, 2.5));
	FirstPersonCamera->bUsePawnControlRotation = true;
	FirstPersonCamera->Activate();
}

void ATFPlayerCharacter::Move(const FInputActionValue& value)
{
	
	FVector2D MovementVector = value.Get<FVector2D>();
	
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		
		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ATFPlayerCharacter::Look(const FInputActionValue& value)
{
	FVector2D LookVector = value.Get<FVector2D>();
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookVector.X);
		AddControllerPitchInput(LookVector.Y);
	}
}

void ATFPlayerCharacter::PlayerJump()
{
	
	if (ATFCharacterBase::CanCharacterJump() && !GetMovementComponent()->IsFalling())
	{
		ATFCharacterBase::HasJumped();
	}
}

void ATFPlayerCharacter::TogglePerspective()
{
	bInFirstPerson = !bInFirstPerson;
	if (!bInFirstPerson)
	{
		FirstPersonCamera->Deactivate();
		ThirdPersonCamera->Activate();
		bUseControllerRotationPitch = false;
		bUseControllerRotationYaw = false;
		bUseControllerRotationRoll = false;
		return;
	}
	ThirdPersonCamera->Deactivate();
	ThirdPersonCamera->Activate();
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = true;
	return;
}

// Called when the game starts or when spawned
void ATFPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATFPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATFPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ATFPlayerCharacter::PlayerJump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATFPlayerCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATFPlayerCharacter::Look);
		EnhancedInputComponent->BindAction(ToggleCameraPerspective, ETriggerEvent::Completed, this, &ATFPlayerCharacter::TogglePerspective);
		// reminder for future functionality
		// EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ATFPlayerCharacter::SprintOn);
		// EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ATFPlayerCharacter::SprintOff);
		// EnhancedInputComponent->BindAction(SneakAction, ETriggerEvent::Started, this, &ATFPlayerCharacter::SneakOn);
		// EnhancedInputComponent->BindAction(SneakAction, ETriggerEvent::Completed, this, &ATFPlayerCharacter::SneakOff);
		// EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ATFPlayerCharacter::OnInteract);
		// //TODO: Fix for proper BP native event usage
		// EnhancedInputComponet->BindAction(InventoryAction, ETriggerEvent::Completed, this, &ATFPlayerCharacter::TogglePlayerInventory_Implementation);
		// EnhancedInputComponent->BindAction(LeanAction, ETriggerEvent::Triggered, this, &ATFPlayerCharacter::Lean);
		// EnhancedInputComponent->BindAction(LeanAction, ETriggerEvent::Completed, this, &ATFPlayerCharacter::Lean);
		
	}
}

