// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControllerBase.h"
#include "TopDownMoveController.generated.h"

/**
 * 
 */
UCLASS()
class UE5_JHW_PF_API ATopDownMoveController : public APlayerControllerBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* Input_Mouse_RightButton;


protected:

	ATopDownMoveController();

	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

public:

	//Related Character Movement on Game.
	void OnInputMouseRightButtonDownStarted();
	void OnSetDestinationTriggered(); 
	void OnSetDestinationReleased();

public:

	bool HitSucceeded();

	FORCEINLINE FHitResult GetCursorHitResult() const
	{
		return m_CursorHitResult;
	}

	FORCEINLINE FVector GetCacheDestination() const
	{
		return m_CachedDestination;
	}

	FORCEINLINE void SetCacheDestination(FVector _ChachedDestination)
	{
		m_CachedDestination = _ChachedDestination;
	}

private:

	FHitResult m_CursorHitResult;
	FVector m_CachedDestination;
	float followTime;
};
