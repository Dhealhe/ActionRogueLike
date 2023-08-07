// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{

	// Defaulting Attributes
	Health = 100;
	MaxHealth = 100;
}

bool USAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool USAttributeComponent::ApplyHealthChange(float Delta)
{
	float NewHealth = Health + Delta;
	if (NewHealth < 0.0f) {
		Health = 0.0f;
	}
	else if (NewHealth > MaxHealth)
	{
		Health = MaxHealth;
	}
	else
	{
		Health = NewHealth;
	}


	// TODO - Change this so it is not changed unless there was an actual change in HP
	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);

	return true;
}

