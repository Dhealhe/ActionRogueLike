// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;
class UAnimMontage;
class USAttributeComponent;

UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> PrimaryAttackClass;

	FTimerHandle TimerHandle_PrimaryAttack;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> BlackholeAttackClass;

	FTimerHandle TimerHandle_BlackholeAttack;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> DashProjectileClass;

	FTimerHandle TimerHandle_DashProjectile;

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;


public:
	// Sets default values for this character's properties
	ASCharacter();

protected:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USAttributeComponent* AttributeComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);

	void MoveRight(float value);

	void PrimaryAttack();

	void PrimaryAttack_TimeElapsed();

	void BlackholeAttack();

	void BlackholeAttack_TimeElapsed();

	void DashProjectile();

	void DashProjectile_TimeElapsed();

	void PrimaryInteract();

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta);

	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private : 
	void SpawnProjectileAttack(TSubclassOf<AActor> ProjectileClass);

};
