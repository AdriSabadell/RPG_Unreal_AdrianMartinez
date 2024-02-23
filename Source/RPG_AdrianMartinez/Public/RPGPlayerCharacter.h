// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ClassDataRow.h"
#include "RPGPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class RPG_ADRIANMARTINEZ_API ARPGPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ARPGPlayerCharacter();

	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UCameraComponent* GetTopDownCameraComponent() const { return mpTopDownCameraComponent; }
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return mpCameraBoom; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mHealth = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EClass> mCharacterClass {};

protected:

	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess= "true"))
		UCameraComponent* mpTopDownCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess= "true"))
		USpringArmComponent* mpCameraBoom;


	
	

};
