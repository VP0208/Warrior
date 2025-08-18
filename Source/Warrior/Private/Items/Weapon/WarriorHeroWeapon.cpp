// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapon/WarriorHeroWeapon.h"

void AWarriorHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedAbilitiesSpecHandle = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AWarriorHeroWeapon::GetGrantedAbilitiesSpecHandle() const
{
	return GrantedAbilitiesSpecHandle;
}
