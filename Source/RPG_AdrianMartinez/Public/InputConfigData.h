// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputConfigData.generated.h"

class UInputAction;
/**
 * 
 */
UCLASS()
class RPG_ADRIANMARTINEZ_API UInputConfigData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* mpInputMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UInputAction* mpInputAct;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TArray<UInputAction*> mpInputSkills;
};
