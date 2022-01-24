// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"

#include "GameFramework/PawnMovementComponent.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
}


void AFirstPersonCharacter::MoveForward(float AxisValue) 
{
	GetMovementComponent()->AddInputVector(GetActorForwardVector() * AxisValue);
}

void AFirstPersonCharacter::MoveRight(float AxisValue) 
{
	GetMovementComponent()->AddInputVector(GetActorRightVector() * AxisValue);
}


void AFirstPersonCharacter::StartGrabbing()
{
	GetGrabber()->Grab();
}

void AFirstPersonCharacter::StopGrabbing()
{
	GetGrabber()->Release();
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AFirstPersonCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Grab"), EInputEvent::IE_Pressed, this, &AFirstPersonCharacter::StartGrabbing);
	PlayerInputComponent->BindAction(TEXT("Grab"), EInputEvent::IE_Released, this,&AFirstPersonCharacter::StopGrabbing);
}
