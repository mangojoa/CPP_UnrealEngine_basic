// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS() // 언리얼 클래스이다.
class TESTUNREALENGINE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// VisibleAnywhere 를 사용하면 액터의 시능을 어디서든 볼 수 있다.
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	// 인게임에서 사용할 정보 (액터의 특성!?) 등을 여기에 같이 선언 할 수 있다.
	UPROPERTY(VisibleAnywhere, Category=BattleStat)
	int32 HP;

	UPROPERTY(VisibleAnywhere, Category = BattleStat)
	int32 MP;
	// 하지만 이렇게 넣고 빌드할 시, 어디에도 나타나지 않는다...
};
