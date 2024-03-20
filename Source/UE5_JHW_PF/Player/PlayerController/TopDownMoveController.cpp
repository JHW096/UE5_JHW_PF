// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownMoveController.h"
#include "PlayerControllerBase.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>
#include "Kismet/KismetMathLibrary.h"

ATopDownMoveController::ATopDownMoveController()
{
	//Mouse Cursor Show Display? = true;
	bShowMouseCursor = true;

	m_CachedDestination = FVector::ZeroVector;
}

void ATopDownMoveController::BeginPlay()
{
	Super::BeginPlay();
}

void ATopDownMoveController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ATopDownMoveController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Bind_SetUp_Mouse_RightButton_
	{
		m_EnhancedInputComponent->BindAction(
			Input_Mouse_RightButton, ETriggerEvent::Started, this, &ATopDownMoveController::OnInputMouseRightButtonDownStarted
		);
		m_EnhancedInputComponent->BindAction(
			Input_Mouse_RightButton, ETriggerEvent::Triggered, this, &ATopDownMoveController::OnSetDestinationTriggered
		);
		m_EnhancedInputComponent->BindAction(
			Input_Mouse_RightButton, ETriggerEvent::Completed, this, &ATopDownMoveController::OnSetDestinationReleased
		);
		m_EnhancedInputComponent->BindAction(
			Input_Mouse_RightButton, ETriggerEvent::Canceled, this, &ATopDownMoveController::OnSetDestinationReleased
		);
	}

}

void ATopDownMoveController::OnInputMouseRightButtonDownStarted()
{
}

void ATopDownMoveController::OnSetDestinationTriggered()
{
	followTime += GetWorld()->GetDeltaSeconds();

	if (HitSucceeded())
	{
		SetCacheDestination(m_CursorHitResult.Location);
	}

	APawn* PlayerPawn = GetPawn();

	if (PlayerPawn != nullptr) // null check
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, m_CachedDestination);
	}
}

void ATopDownMoveController::OnSetDestinationReleased()
{
	followTime = 0.0f; 
}

bool ATopDownMoveController::HitSucceeded()
{
	return GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, m_CursorHitResult) == true ? true : false;
}
