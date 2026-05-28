// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NEVBaseWeapon.generated.h"

UCLASS()
class NEV_API ANEVBaseWeapon : public AActor
{
	GENERATED_BODY()

	//** METHODS **//
	
public:	

	ANEVBaseWeapon();

	void Attack();

protected:

	virtual void BeginPlay() override;

private:

	//** PROPERTIES **//

public:

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UE08|Weapon")
	//EEquippedWeaponType EquippedWeaponType;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "NEV|Component")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NEV|Component")
	float DamageLevel = 0.0f;

private:

};
