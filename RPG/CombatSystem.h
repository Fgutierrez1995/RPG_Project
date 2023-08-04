#pragma once
#include "CharacterCreation.h"
#include <iostream>


class CombatSystem {
public:
	/*
	* @brief Constructor to initalize player and enemey characters.
	* @param player The main character.
	* @param enemy The enemey character.
	*/
	CombatSystem(std::shared_ptr<Character> player, std::shared_ptr<Character> enemy);

	/** @brief Determines if the battle is over. Checks player health and enemy health to see if one has died. */
	bool battleOver();

	/** @breif Method for player to pick a combat option. */
	void playerTurn();

	/** @breif Method for npc to pick a combat option. */
	void enemyTurn();

	/** @breif Method to simulate a turn base battle. */
	void startBattle();

private:
	std::shared_ptr<Character> player_;
	std::shared_ptr<Character> enemy_;
};

