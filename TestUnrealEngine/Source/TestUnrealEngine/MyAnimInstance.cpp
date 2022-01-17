// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// �θ��� ����Ű�� Super
	Super::NativeUpdateAnimation(DeltaSeconds);

	// pawn �� �����Ͽ� speed�� ����� �����ϴ� ��� (����)
	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn)) {
		Speed = pawn->GetVelocity().Size();
	}
}
