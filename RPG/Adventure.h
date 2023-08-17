#pragma once
#include "CombatSystem.h"
#include "CharacterCreation.h"
#include "Orc.h"
#include "DarkMage.h"
#include "Goblin.h"
#include "WeaponItem.h"
#include "ConsumableItem.h"
#include "ArmourItem.h"

class Adventure {
public:
	// Constructor
	Adventure(const std::shared_ptr<Character>& player);

	~Adventure() = default;

	void startAdventure();



private:
	void introduction();

	void firstPlayerSelection();

	void secondPlayerSelection();

	void thirdPlayerSelection();

	void speakWithVillagers();

	void exploreWoods();

	void goblinsCamp();

	/** @breif Method to make sure the user input is valid. */
	int safeInputInt();

	void battleGoblinsAndOrc(const std::vector<std::shared_ptr<Goblin>>& goblins, std::shared_ptr<Orc> orc);

	void grantPlayerEquipmentBasedOnClass(const std::string& playerClass, const std::string& weaponName, const std::string& armourName, double power);

	void grantPlayerConsumableItems(const std::string& itemName, const std::string& description, int count);

	void conclusion();


	std::shared_ptr<Character> player_;
};
