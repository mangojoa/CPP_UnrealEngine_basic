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

	// 리플렉션 기능의 개념이다. 
	// 런타임시 사용하는 컴파일 주석이라고 보면 된다. 
	UPROPERTY();
	// staticMesh 를 사용하는 기능이다.
	UStaticMeshComponent* Mesh;
};
