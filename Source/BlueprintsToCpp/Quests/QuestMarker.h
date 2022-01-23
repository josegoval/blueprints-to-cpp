// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestManager.h"
#include "GameFramework/Actor.h"
#include "QuestMarker.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AQuestMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestMarker();
protected:
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
    AQuestManager* GetQuestManager() const;

	UFUNCTION(BlueprintCallable)
	void RefreshVisibility() const;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* RootSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* ParticleSystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName QuestName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ShowAtProgress;
};
