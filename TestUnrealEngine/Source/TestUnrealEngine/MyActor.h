// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TESTUNREALENGINE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
    // 게임을 시작하거나 처음 이 Actor가 spawn 될 때, 호출이 되는 기능
	virtual void BeginPlay() override;
    
public:
    // 매 프레임 마다 호출이 되는 기능
	virtual void Tick(float DeltaTime) override;

private:
    /* 이제 MyActor에 기능을 추가해보자. (Mesh를 적용해보자!) */
    UPROPERTY()
    UStaticMeshComponent* Mesh;
};
