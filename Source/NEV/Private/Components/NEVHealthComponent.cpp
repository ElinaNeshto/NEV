// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/NEVHealthComponent.h"

// 
UNEVHealthComponent::UNEVHealthComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

}

// 
void UNEVHealthComponent::BeginPlay()
{
	Super::BeginPlay();


}

//
void UNEVHealthComponent::InitHealthComponent()
{

	AActor* Owner = GetOwner();

	if (Owner)
	{
		//Owner->OnTakeAnyDamage.AddDynamic(this, &UUE08HealthComponent::GetDamage);
		//SetHealth(99.0f);
	}

}

//
void UNEVHealthComponent::HealActor(float healthToAdd)
{
	//?? нужна проверка
	if (healthToAdd <= 0.0f)
	{
		return;
	}

	float newHealth = Health + healthToAdd;
	SetHealth(newHealth);
}

//
void UNEVHealthComponent::GetDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	//?? непоняла, что за условие
	if (Damage <= 0.0f || IsDead())
	{
		return;
	}

	float newHealth = Health - Damage;

	SetHealth(newHealth);

	if (IsDead())
	{
		//OnDeath.Broadcast();
	}
}

//
void UNEVHealthComponent::SetHealth(float newHealth)
{
	float UpdatedHealth = FMath::Clamp(newHealth, 0.0f, MaxHealth);
	float HealthDelta = UpdatedHealth - Health;

	Health = UpdatedHealth;

	//OnHealthChanged.Broadcast(Health, HealthDelta);

}


