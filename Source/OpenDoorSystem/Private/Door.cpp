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

void ADoor::Interact_Implementation(bool& IsValid, AActor* Player)
{
	IInteraction::Interact_Implementation(IsValid, Player);

	if (!IsInteractAllowed)
	{
		return;
	}
	
	PlayerRef = Player;
	//执行交互逻辑事件
	Execute_OnInteract(this);

	//交互请求只发出一次
	IsInteractAllowed = false;
}

void ADoor::OnInteract_Implementation()
{
	IInteraction::OnInteract_Implementation();
	
}

void ADoor::OnInteractMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (Montage != OpenLockedDoorMontage) return;
	//执行交互完成事件
	Execute_OnInteractOver(this);
}

void ADoor::OnInteractOver_Implementation()
{
	IInteraction::OnInteractOver_Implementation();
	
	//允许再次交互
	IsInteractAllowed = true;
	//允许玩家控制鼠标旋转
	Execute_ShouldUseControllerRotaion(PlayerRef, true);
	
	UKismetSystemLibrary::PrintString(this, TEXT("✅ 交互结束，可再次开门"));
}

void ADoor::PlayInteractMontage()
{
	if (!PlayerRef) return;

	USkeletalMeshComponent* PlayerMesh = PlayerRef->GetComponentByClass<USkeletalMeshComponent>();
	if (!PlayerMesh) return;

	UAnimInstance* AnimInstance = PlayerMesh->GetAnimInstance();
	if (!AnimInstance) return;

	if (!OpenLockedDoorMontage) return;
	
	// 执行动画
	AnimInstance->Montage_Play(OpenLockedDoorMontage);

	//绑定回调函数
	FOnMontageEnded EndDelegate;
	EndDelegate.BindUObject(this, &ADoor::OnInteractMontageEnded);
	AnimInstance->Montage_SetEndDelegate(EndDelegate, OpenLockedDoorMontage);
}

void ADoor::PlayerMoveTo(USceneComponent* BackSidePosition)
{
	FVector TargetLoc = BackSidePosition->GetComponentLocation();
	TargetLoc.Z = PlayerRef->GetActorLocation().Z;	//目标位置的z轴高度保持玩家自身的属性不变
	
	FRotator TargetRot = BackSidePosition->GetComponentRotation();
	
	Execute_MoveTo(PlayerRef, TargetLoc, TargetRot);
}



