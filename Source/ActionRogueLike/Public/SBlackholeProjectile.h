// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SBaseProjectile.h"
#include "SBlackholeProjectile.generated.h"


class URadialForceComponent;

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASBlackholeProjectile : public ASBaseProjectile
{
	GENERATED_BODY()
	

	public:
		// Sets default values for this actor's properties
		ASBlackholeProjectile();

	protected:

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		URadialForceComponent* ForceComp;
};
