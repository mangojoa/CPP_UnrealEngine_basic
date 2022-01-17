// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// 부모을 가리키는 Super
	Super::NativeUpdateAnimation(DeltaSeconds);

	// pawn 에 접속하여 speed의 사이즈를 접근하는 방식 (정석)
	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn)) {
		Speed = pawn->GetVelocity().Size();
	}
}
