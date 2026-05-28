// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/NEVBaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/NEVHealthComponent.h"
#include "Components/NEVWeaponComponent.h"
#include <Kismet/KismetSystemLibrary.h>


// 
ANEVBaseCharacter::ANEVBaseCharacter()
{

	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	GetCapsuleComponent()->SetCapsuleSize(34.0f, 96.0f);

	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->AirControl = 0.5f;

	//Health Component
	HealthComponent = CreateDefaultSubobject<UNEVHealthComponent>("Health Component");

	//WeaponComponent
	WeaponComponent = CreateDefaultSubobject<UNEVWeaponComponent>("Weapon Component");

}

// 
void ANEVBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	WeaponComponent->InitWeaponComponent();

	ANEVBaseWeapon* lCurrentWeapon = WeaponComponent->CurrentWeapon;
	
}

//
void ANEVBaseCharacter::OnDeath()
{
	GetCharacterMovement()->DisableMovement();
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetSimulatePhysics(true);
}

// 
void ANEVBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//
void ANEVBaseCharacter::HealthChanged(float Health, float HealthDelta)
{

}

//
bool ANEVBaseCharacter::GetAimPoint(FHitResult& HitResult, FVector& OutPoint, float MaxDistance) const
{
	APlayerController* lController = GetController<APlayerController>();
	if (!lController)
		return false;

	FVector lViewLocation;
	FRotator lViewRotation;
	lController->GetPlayerViewPoint(lViewLocation, lViewRotation);

	// Trace Direction from camera
	FVector lAimDirection = lViewRotation.Vector();
	FVector lTraceEnd = lViewLocation + lAimDirection * MaxDistance;

	FHitResult lHit;
	FCollisionQueryParams lParams;
	lParams.AddIgnoredActor(this);
	OutPoint = lTraceEnd;
	if (GetWorld()->LineTraceSingleByChannel(lHit, lViewLocation, lTraceEnd, ECC_Visibility, lParams))
	{
		HitResult = lHit;
		OutPoint = lHit.ImpactPoint;
		
	}
	
	UKismetSystemLibrary::DrawDebugLine(GetWorld(), GetActorLocation(), lTraceEnd, FLinearColor::Red, 1.0f, 1.0f);
	return true;
	
}

