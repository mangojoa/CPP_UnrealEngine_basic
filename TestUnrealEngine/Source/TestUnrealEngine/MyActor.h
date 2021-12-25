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

	// VisibleAnywhere 를 사용하면 액터를 어디서든 볼 수 있다.
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	// EditAnywhere 를 사용하면 액터의 기능을 수정할 수 있다. 
	UPROPERTY(EditAnywhere, Category=BattleStat)
	int32 HP;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	int32 MP;
};
