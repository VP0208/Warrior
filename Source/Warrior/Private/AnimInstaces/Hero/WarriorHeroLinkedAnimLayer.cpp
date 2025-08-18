// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstaces/Hero/WarriorHeroLinkedAnimLayer.h"
#include "AnimInstaces/Hero/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
