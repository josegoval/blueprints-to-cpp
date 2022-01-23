// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMarker.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AQuestMarker::AQuestMarker()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	SetRootComponent(RootSceneComponent);
	ParticleSystemComponent->SetupAttachment(RootSceneComponent);
}
