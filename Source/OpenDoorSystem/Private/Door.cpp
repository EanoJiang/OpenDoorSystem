// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::Interact_Implementation(bool& IsValid, APawn* Player)
{
	IInteraction::Interact_Implementation(IsValid, Player);

	if (!IsInteractAllowed)
	{
		return;
	}
	
	PlayerRef = Player;
	//调用事件：开始交互
	Execute_OnInteract(this);
	
	IsInteractAllowed = false;
}

void ADoor::OnInteract_Implementation()
{
	IInteraction::OnInteract_Implementation();
}

// void ADoor::OnInteract_Implementation()
// {
// 	IInteraction::OnInteract_Implementation();
//
// 	UKismetSystemLibrary::PrintString(this, TEXT("On Interact"));
// 	
// 	if (!PlayerRef) return;
//
// 	USkeletalMeshComponent* PlayerMesh = PlayerRef->GetComponentByClass<USkeletalMeshComponent>();
// 	if (!PlayerMesh) return;
//
// 	UAnimInstance* AnimInstance = PlayerMesh->GetAnimInstance();
// 	if (!AnimInstance) return;
//
// 	if (!OpenLockedDoorMontage) return;
//
// 	// 执行动画
// 	AnimInstance->Montage_Play(OpenLockedDoorMontage);
// 	
// }
