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


