// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/NEVWeaponComponent.h"
#include "Weapons/NEVBaseWeapon.h"
#include "Player/NEVBaseCharacter.h"
#include "Player/NEVPlayerCharacter.h"

// 
UNEVWeaponComponent::UNEVWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


//
void UNEVWeaponComponent::InitWeaponComponent()
{
	Owner = Cast<ANEVBaseCharacter>(GetOwner());
	Player = Cast<ANEVPlayerCharacter>(GetOwner());

	if (!Owner)
	{
		return;
	}


	if (IsValid(CurrentWeapon))
		CurrentWeapon->Destroy();

	CurrentWeapon = nullptr;

	SpawnWeapon();
	if (!CurrentWeapon)
	{
		return;
	}


}


// 
void UNEVWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

//
void UNEVWeaponComponent::AttachWeaponToSocket(ANEVBaseWeapon* WeaponToEquip, const FName& SocketName)
{
	//auto lCharMesh = Owner->GetMesh();
	auto lFirstPersonMesh = Player->GetFirstPersonMesh();
	if (!lFirstPersonMesh || !WeaponToEquip)
		return;

	FAttachmentTransformRules lAttachmentRules(EAttachmentRule::SnapToTarget, true);
	WeaponToEquip->AttachToComponent(lFirstPersonMesh, lAttachmentRules, SocketName);
}

//
void UNEVWeaponComponent::SpawnWeapon()
{
	if (!GetWorld())
		return;

	
	if (!WeaponClass)
		return;

	ANEVBaseWeapon* SpawnedWeapon = GetWorld()->SpawnActor<ANEVBaseWeapon>(WeaponClass);

	if (!SpawnedWeapon)
		return;

	SpawnedWeapon->SetOwner(Owner);
	AttachWeaponToSocket(SpawnedWeapon, WeaponSocketName);
	CurrentWeapon = SpawnedWeapon;

	
}



