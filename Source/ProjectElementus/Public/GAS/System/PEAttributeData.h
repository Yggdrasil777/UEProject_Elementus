// Author: Lucas Vilas-Boas
// Year: 2022
// Repo: https://github.com/lucoiso/UEProject_Elementus

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PEAttributeData.generated.h"

/**
 *
 */
USTRUCT(BlueprintType, Category = "Custom GAS | Data")
struct FPELevelingData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FPELevelingData() :
		BonusMaxHealth(0.f),
		BonusMaxMana(0.f),
		BonusMaxStamina(0.f),
		BonusAttackRate(0.f),
		BonusDefenseRate(0.f),
		RequiredExp(0.f)
	{
	};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BonusMaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BonusMaxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BonusMaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BonusAttackRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BonusDefenseRate;

	/* Required experience to pass to next level */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Required Xp to Level Up"))
		float RequiredExp;
};

/**
 *
 */
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

 /**
  *
  */