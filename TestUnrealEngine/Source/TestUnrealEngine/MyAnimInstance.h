// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VehicleAnimInstance.h"
#include "MyAnimInstance.generated.h"

/** [22.01.17] ĳ������ �ִϸ��̼��� �ֱ� ���� C++ Ŭ���� �̴�
 * 
 */
UCLASS()
class TESTUNREALENGINE_API UMyAnimInstance : public UVehicleAnimInstance
{
	GENERATED_BODY()

		// ĳ������ ������ �� speed�� �������ִ� �Լ���� ����ȴ�.
		// �̸� �ִ��ν��Ͻ��� �����ϴ� ���� �Ϲ����̴�.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Pawn, Meta=(AllowPrivateAccess=true))
		float Speed;
};

// 