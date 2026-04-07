// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction.h"
#include "Kinematic.h"
#include "GameFramework/Pawn.h"
#include "SandboxCharacter_Mover.generated.h"

UCLASS()
class OPENDOORSYSTEM_API ASandboxCharacter_Mover : public APawn, public IInteraction, public IKinematic
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

#pragma region IKinematic在玩家类的实现
	//角色移动
	UFUNCTION(BlueprintCallable, Category="IKinematic")
	virtual void MoveTo_Implementation(FVector TargetLoc, FRotator TargetRot) override;

	//限制鼠标旋转
	UFUNCTION(BlueprintCallable, Category="IKinematic")
	virtual void ShouldUseControllerRotaion_Implementation(bool ShouldUse) override;

	//设置玩家控制器的朝向
	UFUNCTION(BlueprintCallable, Category="IKinematic")
	virtual void SetPlayerControllerRotation_Implementation(FRotator TargetRot) override;

	#pragma endregion

	
};
