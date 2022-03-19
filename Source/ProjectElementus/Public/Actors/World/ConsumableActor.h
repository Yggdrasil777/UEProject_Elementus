// Author: Lucas Vilas-Boas
// Year: 2022
// Repo: https://github.com/lucoiso/UEProject_Elementus

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "ConsumableActor.generated.h"

/**
 *
 */
UCLASS(Abstract, Blueprintable, Category = "Custom Classes | Actors")
class PROJECTELEMENTUS_API AConsumableActor : public AActor
{
	GENERATED_BODY()

public:
	AConsumableActor(const FObjectInitializer& ObjectInitializer);

	FORCEINLINE virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Consumable Actor", GetFName());
	}

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Custom Functions | Behaviors")
		void PerformConsumption(class UAbilitySystemComponent* TargetABSC);
	void PerformConsumption_Implementation(UAbilitySystemComponent* TargetABSC);
	bool PerformConsumption_Validate(UAbilitySystemComponent* TargetABSC);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Properties | Defaults")
		UStaticMeshComponent* ObjectMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Properties | Defaults")
		class UNiagaraComponent* ObjectVFX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Properties | Defaults")
		TSubclassOf<class UGameplayEffect> ObjectEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Properties | Defaults")
		FGameplayTagContainer RequirementsTags;
};
