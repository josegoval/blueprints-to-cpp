// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

// Sets default values
AQuestManager::AQuestManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();
}

FQuestInfo AQuestManager::GetQuest(FName QuestId) const
{
	return QuestList[GetQuestIndex(QuestId)];
}

// Called every frame
void AQuestManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AQuestManager::CompleteQuest_Implementation(FName QuestId, bool CompleteWholeQuest)
{
	const int32 QuestIndex = GetQuestIndex(QuestId);
	if (QuestIndex == -1) return;

	FQuestInfo& Quest = QuestList[QuestIndex];
	Quest.Progress = CompleteWholeQuest ? Quest.ProgressTotal : FMath::Min(Quest.Progress + 1, Quest.ProgressTotal);
	CompletedQuest.Broadcast(QuestIndex);
}
