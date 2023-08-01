#pragma once
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "Character.h"
#include <memory>

class CharacterCreation {
public:
	/** @brief This method is used to create characters in the RPG game using the 3 provided classes (e.g Warrior, Mage or Rogue). */
	static std::shared_ptr<Character> createCharacter();

private:

	/** @brief creates a unique_ptr Warrior object. */
	static std::shared_ptr<Warrior> createWarrior();

	/** @brief creates a unique_ptr Warrior object. */
	static std::shared_ptr<Mage> createMage();

	/** @brief creates a unique_ptr Warrior object. */
	static std::shared_ptr<Rogue> createRogue();

};