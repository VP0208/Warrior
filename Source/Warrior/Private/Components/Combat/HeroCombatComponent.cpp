// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/HeroCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "DebugHelper.h"
#include "WarriorGameplayTags.h"
#include "Characters/WarriorEnemyCharacter.h"
#include "Items/Weapon/WarriorHeroWeapon.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UHeroCombatComponent::GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
	return GetHeroCurrentEquippedWeapon()->HeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor)) return;

	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData Data;
	Data.Instigator = Cast<APawn>(GetOwner());
	Data.Target = HitActor;
	

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwner(),
		WarriorGameplayTags::Shared_Event_MeleeHit,
		Data);

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwner(),
		WarriorGameplayTags::Player_Event_HitPause,
		FGameplayEventData());
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwner(),
		WarriorGameplayTags::Player_Event_HitPause,
		FGameplayEventData());
}



