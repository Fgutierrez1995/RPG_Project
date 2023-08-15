#include <iostream>
#include "WeaponItem.h"
#include "ArmourItem.h"
#include "ConsumableItem.h"
#include "CharacterCreation.h"
#include "CombatSystem.h"
#include "Orc.h"
#include "DarkMage.h"
#include "Goblin.h"


int main() {

	auto warrior = CharacterCreation::createCharacter();
	auto orc = Orc::makeOrc(50, 20, 100, "Orc");
	auto darkMage = DarkMage::makeDarkMage(20, 0, 75, "Dark Mage");
	auto goblin = Goblin::makeGoblin(18, 2, 50, "Goblin");

	warrior->addItem(std::move(WeaponItem::makeWeapon("Long Sword", "Great sword", 50)));
	warrior->addItem(std::move(ArmourItem::makeArmour("Black Armour", "Excellent Armour.", 30)));
	warrior->addItem(std::move(ConsumableItem::makeConsumable("Shark", "Excellent cooked shark.", 1000)));

	CombatSystem combat(warrior, goblin);

	combat.startBattle();

	return 0;
}