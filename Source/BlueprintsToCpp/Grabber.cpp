// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

FVector UGrabber::GetMaxGrabLocation() const
{
	
	return GetComponentLocation() + GetForwardVector() * MaxGrabDistance;
}

FVector UGrabber::GetHoldLocation() const
{
	
	return GetComponentLocation() + GetForwardVector() * HoldDistance;
}

UPhysicsHandleComponent* UGrabber::GetPhysicsComponent() const
{
	return GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}

bool UGrabber::TraceForPhysicsBodies_Implementation(AActor*& HitActor, UPrimitiveComponent*& HitComponent)
{
	return false;
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGrabber::Grab()
{
	AActor* HitActor;
	UPrimitiveComponent* HitComponent;

	if (!TraceForPhysicsBodies(HitActor,HitComponent)) return;
	HitComponent->SetSimulatePhysics(true);
	GetPhysicsComponent()->GrabComponentAtLocationWithRotation(HitComponent, NAME_None, HitComponent->GetCenterOfMass(), FRotator());
}

void UGrabber::Release()
{
	GetPhysicsComponent()->ReleaseComponent();
}

