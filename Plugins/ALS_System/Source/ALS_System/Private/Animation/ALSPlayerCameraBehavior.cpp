// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/ALSPlayerCameraBehavior.h"
#include "ALSBaseCharacter.h"

void UALSPlayerCameraBehavior::SetRotationMode(EALSRotationMode RotationMode)
{
	bVelocityDirection = RotationMode == EALSRotationMode::VelocityDirection;
	bLookingDirection = RotationMode == EALSRotationMode::LookingDirection;
	bAiming = RotationMode == EALSRotationMode::Aiming;
}
