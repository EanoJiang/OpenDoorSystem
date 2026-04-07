#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Kinematic.generated.h"

UINTERFACE(BlueprintType)
class OPENDOORSYSTEM_API UKinematic : public UInterface
{
	GENERATED_BODY()
};

class OPENDOORSYSTEM_API IKinematic
{
	GENERATED_BODY()

public:

	//移动
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent , Category="Kinematic")
	void MoveTo(FVector TargetLoc, FRotator TargetRot);

	//限制鼠标旋转
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="IKinematic")
	void ShouldUseControllerRotaion(bool ShouldUse);

	//设置玩家控制器的朝向
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="IKinematic")
	void SetPlayerControllerRotation(FRotator TargetRot);
};
