// Fill out your copyright notice in the Description page of Project Settings.

#include "BounceComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values for this component's properties
UBounceComponent::UBounceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBounceComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBounceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBounceComponent::Launch()
{
	auto Comp = GetOwner()->GetComponentByClass(UCharacterMovementComponent::StaticClass());
	if (!Comp) { return; }
	auto MovementComp = Cast<UCharacterMovementComponent>(Comp);
	if (!MovementComp) { return; }
	if (GetOwner()->GetVelocity().Z > 0) { return; }
	
	UE_LOG(LogTemp, Warning, TEXT("Launch called!"));

	MovementComp->Velocity += FVector(0, 0, LaunchBaseSpeed * -GetOwner()->GetVelocity().Z);
}

