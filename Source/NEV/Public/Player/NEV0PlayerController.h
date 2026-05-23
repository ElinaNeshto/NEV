// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NEV0PlayerController.generated.h"



/**
 * 
 */
UCLASS()
class NEV_API ANEV0PlayerController : public APlayerController
{
	GENERATED_BODY()

	//** METHODS **//
	
public:

protected:

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;



private:


	//** PROPERTIES **//

public:

protected:

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category = "NEV|Input|Input Mappings")
	TArray<class UInputMappingContext*> DefaultMappingContexts;

private:

};
