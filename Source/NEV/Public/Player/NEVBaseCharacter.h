// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NEVBaseCharacter.generated.h"

UCLASS()
class NEV_API ANEVBaseCharacter : public ACharacter
{
	GENERATED_BODY()

	//** METHODS **//

public:

	ANEVBaseCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	virtual void HealthChanged(float Health, float HealthDelta);

	UFUNCTION(BlueprintCallable)
	bool GetAimPoint(FHitResult& HitResult, FVector& OutPoint, float MaxDistance) const;

	UFUNCTION(BlueprintCallable, BlueprintPure) const
		UNEVWeaponComponent* GetWeaponComponent()
	{
		return WeaponComponent;
	}

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnDeath();

private:	


	//** PROPERTIES **//

public:



protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UNEVHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UNEVWeaponComponent* WeaponComponent;

private:



};
