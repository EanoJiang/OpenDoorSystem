// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

class ASandboxCharacter_Mover;

UCLASS()
class OPENDOORSYSTEM_API ADoor : public AActor, public IInteraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, Category="Interact")
	bool IsInteractAllowed = true;
	UPROPERTY(BlueprintReadWrite, Category="Interact")
	TObjectPtr<APawn> PlayerRef;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Interact|Montage")
	TObjectPtr<UAnimMontage> OpenLockedDoorMontage;
	
	//交互请求(在Door的实现)
	UFUNCTION(BlueprintCallable, Category="Interact")
	virtual void Interact_Implementation(bool& IsValid, APawn* Player) override;

	UFUNCTION(BlueprintCallable, Category="Interact")
	virtual void OnInteract_Implementation() override;
};
