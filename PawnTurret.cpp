// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::APawnTurret()
{

}

void ApAWNtURRET::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void APawnTurret::CheckFireCondition()
{
    if(!PlayerPawn){return;}

    if (ReturnDistanceToPlayer() <= FireRange)
    {
        //Fire();
        UE_LOG(LogTemp, Warning, TEXT("Fire range a ok"));
    }
}

float APawnTurret::ReturnDistanceToPlayer()
{
    if(!PlayerPawn)
    {
        return 0.0f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation()); // float distance = 

}