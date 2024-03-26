// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	{
		PrimaryActorTick.bCanEverTick = true;
		PrimaryActorTick.bStartWithTickEnabled = true;
	}

	// Don't rotate character to camera direction
	{
		bUseControllerRotationPitch = false;
		bUseControllerRotationYaw = false;
		bUseControllerRotationRoll = false;
	}

	// Configure character movement
	{
		GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
		GetCharacterMovement()->bConstrainToPlane = true;	//true : 위치 벡터를 평면 제약 조건으로 제한한다. 평면 이동으로 제한한다.
		GetCharacterMovement()->bSnapToPlaneAtStart = true; //true : 활성화된 경우 평면에 묶어둔다.
	}

	// Create a SpringArmComponent, and Settings
	{
		m_SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARMCOMPONENT"));
		m_SpringArmComponent->SetupAttachment(RootComponent);
		m_SpringArmComponent->SetUsingAbsoluteRotation(true);	//true : 캐릭터가 회전할 때 SpringArm이 회전하지 않음.
		m_SpringArmComponent->TargetArmLength = 800.0f;	// Character to Camera Length
		m_SpringArmComponent->SetRelativeRotation(FRotator(-60.0f, 0.0f, 0.0f));
		m_SpringArmComponent->bDoCollisionTest = false; // False : 카메라 충돌시 카메라가 당겨짐 / true : 카메라 충돌시 카메라가 당겨짐
	}

	// Create a CameraCompoenent, and Settings
	{
		m_TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TOPDOWNCAMERACOMPONENT"));
		m_TopDownCameraComponent->SetupAttachment(m_SpringArmComponent, USpringArmComponent::SocketName);
		m_TopDownCameraComponent->bUsePawnControlRotation = false; // 카메라가 Arm의 회전에 따라가지 않는다.
	}
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerBase::SetPlayerAnimState(AnimState _AnimState)
{
	if (GetAnimMontageToAnimState(_AnimState) == nullptr)
	{
		return;
	}

	m_AnimState = _AnimState;
}

AnimState APlayerBase::GetAnimState() const
{
	return m_AnimState;
}

UAnimMontage* APlayerBase::GetAnimMontageToAnimState(AnimState _AnimState) const
{
	if (m_Player_All_Animations.FindRef(_AnimState) == nullptr)
	{
		return nullptr;
	}
	return m_Player_All_Animations.FindRef(_AnimState);
}

TMap<AnimState, UAnimMontage*> APlayerBase::GetAllAnimations() const
{
	if (m_Player_All_Animations.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s(%u) PlayeBase has not some animations.."), __FUNCTION__, __LINE__);
	}

	return m_Player_All_Animations;
}

















