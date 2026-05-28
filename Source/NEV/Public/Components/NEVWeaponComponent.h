// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NEVWeaponComponent.generated.h"

class ANEVBaseWeapon;
class ANEVBaseCharacter;
class ANEVPlayerCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEV_API UNEVWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

	//** METHODS **//

public:	

	UNEVWeaponComponent();



	UFUNCTION(BlueprintCallable)
	void InitWeaponComponent();

protected:

	virtual void BeginPlay() override;


	UFUNCTION()
	void AttachWeaponToSocket(ANEVBaseWeapon* WeaponToEquip, const FName& SocketName);


private:

	UFUNCTION()
	void SpawnWeapon();

	//** PROPERTIES **//

public:


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "NEV|Weapon")
	ANEVBaseWeapon* CurrentWeapon = nullptr;

protected:


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "NEV|Weapons", meta = (AllowPrivateAccess = "true", DisplayName = "Weapon class"))
	TSubclassOf<ANEVBaseWeapon> WeaponClass;


	UPROPERTY(EditDefaultsOnly)
	FName WeaponSocketName = "WeaponSocket";

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	ANEVBaseCharacter* Owner;
	ANEVPlayerCharacter* Player;
private:
		
};
