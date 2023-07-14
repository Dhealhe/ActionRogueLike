// Fill out your copyright notice in the Description page of Project Settings.


#include "SBlackholeProjectile.h"
#include <PhysicsEngine/RadialForceComponent.h>
#include <Components/SphereComponent.h>
#include <Particles/ParticleSystemComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>

ASBlackholeProjectile::ASBlackholeProjectile()
{
	ForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("ForceComp"));
	ForceComp->Radius = 3000.0f;
	ForceComp->bIgnoreOwningActor = true;
	ForceComp->ForceStrength = -500000;
	ForceComp->ImpulseStrength = 0; 
	ForceComp->SetupAttachment(SphereComp);

	MovementComp->InitialSpeed = 400.f;
}
