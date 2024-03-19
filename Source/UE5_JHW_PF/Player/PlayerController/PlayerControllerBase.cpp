// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"
#include "EnhancedInputSubsystems.h"

void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	// 향상된 입력 시스템을 플레이어와 연동. 시스템에 MappingContext를 추가한다.(0번째)
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(m_MappingContext, 0);
	}
}

void APlayerControllerBase::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);


}

void APlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	//T* Template CastCheck를 통해 향상된 입력 컴포넌트가 오작동(Error)시 return;
	m_EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	if (!m_EnhancedInputComponent)
	{
		return;
	}
}

UInputMappingContext* APlayerControllerBase::GetMappingContext() const
{
	if (m_MappingContext == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s(%u) PlayerControllerBase_m_MappingContext = nullptr!"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return m_MappingContext;
}

void APlayerControllerBase::SetMappingContext(UInputMappingContext* _MappingContext)
{
	if (m_MappingContext == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s(%u) PlayerControllerBase_m_MappingContext = nullptr!"), __FUNCTION__, __LINE__);
		return;
	}

	if (_MappingContext == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s(%u) PlayerControllerBase_Function_SetMappingContext_Parameter*_MappingContext = nullptr"), __FUNCTION__, __LINE__);
		return;
	}
	
	m_MappingContext = _MappingContext;
}
