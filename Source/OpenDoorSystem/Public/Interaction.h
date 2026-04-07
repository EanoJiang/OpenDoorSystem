#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interaction.generated.h"

UINTERFACE(BlueprintType)
class OPENDOORSYSTEM_API UInteraction : public UInterface
{
	GENERATED_BODY()
};

class OPENDOORSYSTEM_API IInteraction
{
	GENERATED_BODY()

public:

	//发出交互请求
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent , Category="Interaction")
	void Interact(bool& IsValid, APawn* Player);

	//交互逻辑
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent , Category="Interaction")
	void OnInteract();
};
