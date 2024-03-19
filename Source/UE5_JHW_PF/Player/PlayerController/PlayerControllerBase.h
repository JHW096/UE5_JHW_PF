// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "PlayerControllerBase.generated.h"


/**
 * 
 */
UCLASS()
class UE5_JHW_PF_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
protected:
//	override from PlayerController
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

public:
// Input MappingContext : Key Collection 

	class UInputMappingContext* GetMappingContext() const;
	void SetMappingContext(class UInputMappingContext* _MappingContext);

protected:
//MappingContext and InputComponent Variable

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* m_MappingContext;
	TMap<FName, class UInputAction> m_UInputAction_Map;
	UEnhancedInputComponent* m_EnhancedInputComponent;

};
