// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxCharacter_Mover.h"

#include "Animation/AnimInstanceProxy.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ASandboxCharacter_Mover::ASandboxCharacter_Mover()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASandboxCharacter_Mover::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASandboxCharacter_Mover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASandboxCharacter_Mover::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASandboxCharacter_Mover::DetectInteractableDoor(bool& IsHit, FHitResult& OutHit)
{
	FVector Start = this->GetActorLocation() + FVector(0, 0, 15);
	FVector End = Start + this->GetActorForwardVector() * 100;
	IsHit = UKismetSystemLibrary::SphereTraceSingle(this, Start, End, 20, TraceTypeQuery1, false, TArray<AActor*>(), EDrawDebugTrace::ForOneFrame, OutHit, true);
}

void ASandboxCharacter_Mover::MoveTo_Implementation(FVector TargetLoc, FRotator TargetRot)
{
	IKinematic::MoveTo_Implementation(TargetLoc, TargetRot);

	// 构造 LatentActionInfo
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this; 
	LatentInfo.ExecutionFunction = FName("OnMoveCompleted"); 
	LatentInfo.Linkage = 0; 
	LatentInfo.UUID = 100;
	
	//移动
	UKismetSystemLibrary::MoveComponentTo(
		GetRootComponent(), 
		TargetLoc, 
		TargetRot, 
		true,              // bEaseOut
		true,              // bEaseIn
		0.5f,               // OverTime
		false,              // bForceShortestRotationPath
		EMoveComponentAction::Move, 
		LatentInfo
	);
	
}

void ASandboxCharacter_Mover::ShouldUseControllerRotaion_Implementation(bool ShouldUse)
{
	IKinematic::ShouldUseControllerRotaion_Implementation(ShouldUse);

	bUseControllerRotationYaw = ShouldUse;
}

void ASandboxCharacter_Mover::SetPlayerControllerRotation_Implementation(FRotator TargetRot)
{
	IKinematic::SetPlayerControllerRotation_Implementation(TargetRot);

	GetController()->SetControlRotation(TargetRot);
}


