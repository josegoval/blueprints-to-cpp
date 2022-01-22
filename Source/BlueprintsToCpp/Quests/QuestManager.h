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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	int32 GetQuestIndex(FName QuestId);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	/**
	 * @brief Completes the given quest if possible. It returns -1 if the
	 * `FQuestInfo` with QuestId wasn't found.
	 * @param QuestId 
	 * @param CompleteWholeQuest 
	 * @return 
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 CompleteQuest(FName QuestId, bool CompleteWholeQuest);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestInfo> QuestList;
};
