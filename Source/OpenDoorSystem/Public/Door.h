// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction.h"
#include "Kinematic.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

class ASandboxCharacter_Mover;

UCLASS()
class OPENDOORSYSTEM_API ADoor : public AActor, public IInteraction, public IKinematic
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 交互蒙太奇完成时回调函数
	UFUNCTION()
	void OnInteractMontageEnded(UAnimMontage* Montage, bool bInterrupted);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, Category="Interaction")
	bool IsInteractAllowed = true;
	UPROPERTY(BlueprintReadWrite, Category="Interaction")
	TObjectPtr<AActor> PlayerRef;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Interaction|Montage")
	TObjectPtr<UAnimMontage> OpenLockedDoorMontage;

#pragma region IInteraction在Door的实现
	//交互请求(在Door的实现)
	UFUNCTION(BlueprintCallable, Category="Interaction")
	virtual void Interact_Implementation(bool& IsValid, AActor* Player) override;

	//交互逻辑(在Door的实现)
	UFUNCTION(BlueprintCallable, Category="Interaction")
	virtual void OnInteract_Implementation() override;
	
	//交互完成事件
	UFUNCTION(BlueprintCallable, Category="Interaction")
	virtual void OnInteractOver_Implementation() override;
#pragma endregion

	//播放交互蒙太奇
	UFUNCTION(BlueprintCallable, Category="Interaction|PlayMontage", meta = (HideSelfPin = "true"))
	void PlayInteractMontage();

	//玩家移动到目标点位
	UFUNCTION(BlueprintCallable, Category="Interaction|MoveTo", meta = (HideSelfPin = "true"))
	void PlayerMoveTo(USceneComponent* BackSidePosition);

	
};
