// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/NEVBaseCharacter.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "InputAction.h"

#include "NEVPlayerCharacter.generated.h"


class USkeletalMeshComponent;
/**
 * 
 */
UCLASS()
class NEV_API ANEVPlayerCharacter : public ANEVBaseCharacter
{
	GENERATED_BODY()

	//** METHODS **//

public:

	ANEVPlayerCharacter();

	UFUNCTION(BlueprintCallable, Category = "NEV|Input")
	virtual void DoJumpStart();

	UFUNCTION(BlueprintCallable, Category = "NEV|Input")
	virtual void DoJumpEnd();

	virtual void HealthChanged(float Health, float DeltaHealth) override;

	/** Returns the first person mesh **/
	USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMesh; }

	/** Returns first person camera component **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

protected:

	virtual void BeginPlay() override;

	virtual void OnDeath() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	/** Called from Input Actions for movement input */
	void MoveInput(const FInputActionValue& Value);

	/** Called from Input Actions for looking input */
	void LookInput(const FInputActionValue& Value);

private:



	//** PROPERTIES **//

public:



protected:


	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category = "NEV|Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category = "NEV|Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category = "NEV|Input")
	class UInputAction* LookAction;


private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NEV|Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NEV|Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* FirstPersonMesh;
	
};
