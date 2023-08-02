#pragma once
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "Character.h"
#include <memory>
#include <map>
#include <functional> // for std::function

class CharacterCreation {
public:
	/** @brief This method is used to create characters in the RPG game using the 3 provided classes (e.g Warrior, Mage or Rogue). */
	static std::shared_ptr<Character> createCharacter();

	/** @brief Method to display Character selection. */
	static void displayCharactersChoices();

private:

	/** @brief creates a unique_ptr Warrior object. */
	static std::shared_ptr<Warrior> createWarrior();

	/** @brief creates a unique_ptr Warrior object. */
	static std::shared_ptr<Mage> createMage();

	/** @brief creates a unique_ptr Warrior object. */
	static std::shared_ptr<Rogue> createRogue();

};