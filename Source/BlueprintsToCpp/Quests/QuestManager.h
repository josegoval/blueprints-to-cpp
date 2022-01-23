// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestInfo.h"
#include "GameFramework/Actor.h"
#include "QuestManager.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AQuestManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AQuestManager();

	UFUNCTION(BlueprintPure)
	FQuestInfo GetQuest(FName QuestId) const;

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	bool IsActiveQuest(FName QuestId) const;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	int32 GetQuestIndex(FName QuestId) const;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 CompleteQuest(FName QuestId, bool CompleteWholeQuest);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestInfo> QuestList;
};
