// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CProjectTPSActor.generated.h"

UCLASS()
class CPROJECTTPS_API ACProjectTPSActor : public ACharacter
{
	GENERATED_BODY()

public:

	ACProjectTPSActor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharSettings") float Health;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "CharSettings") float Stamina;

	UPROPERTY(BlueprintReadOnly, EditInstanceOnly, Category = "CharSettings") int Level;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "CharSettings")
	virtual float GetCharHealth()
	{
		return Health = FMath::Clamp(Health, 0.0f, 100.0f);
	};


protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
