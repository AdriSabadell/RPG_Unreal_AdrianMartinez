#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "ClassDataRow.generated.h"

UENUM(BlueprintType)
enum EClass
{
	MAGO,
	ARQUERO
};

USTRUCT(Blueprintable, BlueprintType)
struct FClassDataRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,	BlueprintReadWrite)
	TEnumAsByte<EClass> Name {EClass::MAGO};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;

	
};
