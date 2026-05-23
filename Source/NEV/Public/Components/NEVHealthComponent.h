// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NEVHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEV_API UNEVHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	//** METHODS **//

public:	

	UNEVHealthComponent();

	UFUNCTION()
	void InitHealthComponent();

	UFUNCTION(BlueprintCallable)
	void HealActor(float healthToAdd);

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetHealth() { return Health; }

	UFUNCTION()
	void GetDamage(AActor* DamageActor,
		float Damage,
		const UDamageType* DamageType,
		AController* InstigatedBy,
		AActor* DamageCauser);


	UFUNCTION(BlueprintCallable)
	void SetHealth(float newHealth);

	UFUNCTION()
	bool IsDead() const
	{
		return FMath::IsNearlyZero(Health);
	};

	//** PROPERTIES **//

public:

	UPROPERTY(BlueprintReadWrite)
	float MaxHealth = 100.0f;

	//FOnDeathSignature OnDeath;

	//FOnHealthChangedSignature OnHealthChanged;

protected:


private:

	UPROPERTY()
	float Health = 0.0f;


		
};
