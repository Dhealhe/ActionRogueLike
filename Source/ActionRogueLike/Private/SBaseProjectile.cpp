// Fill out your copyright notice in the Description page of Project Settings.


#include "SBaseProjectile.h"
#include <Components/SphereComponent.h>
#include <Particles/ParticleSystemComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Components/AudioComponent.h>
#include <Sound/SoundCue.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ASBaseProjectile::ASBaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	//SphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	SphereComp->SetCollisionProfileName("Projectile");
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;
	MovementComp->ProjectileGravityScale = 0;

	AudioComp = CreateDefaultSubobject<UAudioComponent>("AudioComp");

}

void ASBaseProjectile::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Explode();
}

void ASBaseProjectile::Explode_Implementation()
{
	if (ensure(IsValid(this)))
	{
		// Add whatever, probably a base implementation of sound / effect and whatever was defined for base hit
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());

		Destroy();
	}
}

// Called when the game starts or when spawned
void ASBaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	/*if (IsValid(FlightSoundComp))
	{
		FlightSoundComp->Play();
	}*/

}

// Called every frame
void ASBaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

