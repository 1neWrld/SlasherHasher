// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Bird.generated.h"

// Forward Declaration
class UCapsuleComponent;
class USkeletelMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class SLASHERHASHER_API ABird : public APawn
{
	GENERATED_BODY()

public:

	ABird();
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* BirdMappingContext;
	

	/**
		Defined variables of type UInputAction
		Connect IA_InputActions in editor to UInputAction Variables
	*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;
	

	/** Callback...bind to our input action */
	void Move(const FInputActionValue& Value);
	void LookAt(const FInputActionValue& Value);



private:

	//Variable pointers set to visible anywhere in UE
	
	UPROPERTY(VisibleAnywhere)
	 UCapsuleComponent* Capsule;

	 UPROPERTY(VisibleAnywhere)
	 USkeletalMeshComponent* BirdMesh;

	  UPROPERTY(VisibleAnywhere)
	 USpringArmComponent* SpringArm;

	  UPROPERTY(VisibleAnywhere)
	 UCameraComponent* ViewCamera;

};
