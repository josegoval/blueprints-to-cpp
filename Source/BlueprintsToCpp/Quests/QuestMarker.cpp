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

void AQuestMarker::BeginPlay()
{
	GetQuestManager()->CompletedQuest.AddDynamic(this, &AQuestMarker::OnCompleteQuest);
	RefreshVisibility();
}

void AQuestMarker::RefreshVisibility() const
{
	const AQuestManager* QuestManager = GetQuestManager();
	const FQuestInfo& Quest = QuestManager->GetQuest(QuestName);
	const bool isVisible = Quest.Progress == ShowAtProgress && QuestManager->IsActiveQuest(QuestName);
	ParticleSystemComponent->SetVisibility(isVisible);
}

void AQuestMarker::OnCompleteQuest(int32 Index)
{
	RefreshVisibility();
}
