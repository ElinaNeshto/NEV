// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/NEV0PlayerController.h"
#include "EnhancedInputSubsystems.h"


//
void ANEV0PlayerController::BeginPlay()
{
	Super::BeginPlay();
}


//
void ANEV0PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Context
		if (Subsystem)
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

		}
	}
}
