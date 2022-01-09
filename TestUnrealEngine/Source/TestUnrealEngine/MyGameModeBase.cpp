// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase() {
//    DefaultPawnClass = AMyCharacter::StaticClass();
    
    static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("/Users/mango_mac/CPP_UnrealEngine_basic/TestUnrealEngine/Content/BluePrints/BP_MyCharacter.BP_MyCharacter_C"));
    // 블루 프린트 경로의 경우에는 마지막 경로에 '_C'를 널어줘f야 한다.
    
    if (BP_Char.Succeeded()){
        DefaultPawnClass = BP_Char.Class;
    }
}
