// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "SkillDataRow.h"
#include "ClassDataRow.h"
#include "RPGPlayerController.generated.h"

class ARPGPlayerCharacter;
class UInputConfigData;
class UInputMappingContext;
class UNiagaraSystem;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLocationClick, FVector, aClickLocation, const FSkillDataRow&, aSkillData);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDirectonSkillCast, FRotator, aRotation, FSkillDataRow, aSkillData);


UCLASS()
class RPG_ADRIANMARTINEZ_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		ARPGPlayerCharacter* mpPlayerCharacter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = mInputs)
		UInputMappingContext* mpInputContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = mInputs)
		UInputConfigData* mpInputData;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		UNiagaraSystem* mpFXCursor;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		float mThresholdPress;


#pragma region SKILLS
	FSkillDataRow* GetSkill(ESkill skill);

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category=mSkill)
	TArray<TEnumAsByte<ESkill>> mSkills;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=mCLASS)
	UDataTable* mClassDB;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category=mSkill)
	UDataTable* mSkillDB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category=mSkill)
		FSkillDataRow mSkillSelected;
	
#pragma  endregion

#pragma region EVENTS

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FOnLocationClick evOnLocationClick;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FOnDirectonSkillCast evOnDirectionSkillCast;

#pragma endregion
	
protected:
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	void OnSetDestinationPressed(const FInputActionValue& aValue);
	void OnSetDestinationReleased(const FInputActionValue& aValue);

	void OnSkillPressed(int aButtonPressed);
	void OnActPressed(const FInputActionValue& aValue);

	void GetClassData();
	
private:
	FHitResult mHitResult {};
	bool mSetDestination{false};
	float mFollowTime{0.f};
};
