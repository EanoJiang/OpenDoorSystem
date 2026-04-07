// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction.h"
#include "GameFramework/Pawn.h"
#include "SandboxCharacter_Mover.generated.h"

UCLASS()
class OPENDOORSYSTEM_API ASandboxCharacter_Mover : public APawn, public IInteraction
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASandboxCharacter_Mover();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	//检测可以交互的门
	UFUNCTION(BlueprintPure, Category = "Detect")
	void DetectInteractableDoor(bool& IsHit, FHitResult& OutHit);
};
