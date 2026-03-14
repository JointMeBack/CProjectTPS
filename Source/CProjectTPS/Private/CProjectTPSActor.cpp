// Fill out your copyright notice in the Description page of Project Settings.


#include "CProjectTPSActor.h"
#include "Kismet/KismetMathLibrary.h"


DEFINE_LOG_CATEGORY_STATIC(LogCProjectTPSActor, All, All);

// Sets default values
ACProjectTPSActor::ACProjectTPSActor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACProjectTPSActor::BeginPlay()
{
	Super::BeginPlay();
	NotifyActor(this);
	UE_LOG(LogCProjectTPSActor, Display, TEXT("Notify function has been called"));

}


bool ACProjectTPSActor::TraceForPhysicsBodies_Implementation(AActor* HitActor, UPrimitiveComponent*& HitComponent)
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("TraceForPhysicsBodies is called"));
	return false;

}

void ACProjectTPSActor::MyTraceFunction()
{
	FVector TraceStart = GetActorLocation();
	FVector TraceEnd = TraceStart + GetActorRotation().Vector() * 500.0f;
	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 0.5f, 0, 1);
	bool bIsHit = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, QueryParams);

	if (bIsHit)
	{
		GEngine->AddOnScreenDebugMessage(1, 1, FColor::Green, TEXT("It's hitting something"));
	}
}

// Called every frame
void ACProjectTPSActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MyTraceFunction();

}

// Called to bind functionality to input
void ACProjectTPSActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

