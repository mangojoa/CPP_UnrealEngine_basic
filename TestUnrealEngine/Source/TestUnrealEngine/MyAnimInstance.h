// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VehicleAnimInstance.h"
#include "MyAnimInstance.generated.h"

/** [22.01.17] 캐릭터의 애니메이션을 넣기 위한 C++ 클래스 이다
 * 
 */
UCLASS()
class TESTUNREALENGINE_API UMyAnimInstance : public UVehicleAnimInstance
{
	GENERATED_BODY()

		// 캐릭터의 움직임 즉 speed를 관리해주는 함수라고 보면된다.
		// 이를 애님인스턴스에 선언하는 것이 일반적이다.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Pawn, Meta=(AllowPrivateAccess=true))
		float Speed;
};

// 