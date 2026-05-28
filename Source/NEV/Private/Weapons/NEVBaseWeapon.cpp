// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/NEVBaseWeapon.h"

// 
ANEVBaseWeapon::ANEVBaseWeapon()
{

	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);

}

// 
void ANEVBaseWeapon::BeginPlay()
{
	Super::BeginPlay();

	check(WeaponMesh);
	
}

// 
void ANEVBaseWeapon::Attack()
{
	

}


