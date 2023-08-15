#pragma once
#include "CharacterCreation.h"
#include "Enemy.h"
#include <iostream>


class CombatSystem {
public:
	/*
	* @brief Constructor to initalize player and enemey characters.
	* @param player The main character.
	* @param enemy The enemey character.
	*/
	CombatSystem(std::shared_ptr<Character> player, std::shared_ptr<Enemy> enemy);


	/** @breif Method to simulate a turn base battle. */
	void startBattle();





private:

	/** @brief Determines if the battle is over. Checks player health and enemy health to see if one has died. */
	bool battleOver();

	/** @breif Method for player to pick a combat option. */
	void playerTurn();

	/** @breif Method for npc to pick a combat option. */
	void enemyTurn();

	/** @breif Helper method to see if player used his turn on healing while accessing inventory. */
	void playerHealed();

	/** @breif Method to access the characters inventory. */
	void accessInventory();

	/** @breif Method to make sure the user input is valid. */
	int safeInputInt();

	std::shared_ptr<Character> player_;
	std::shared_ptr<Enemy> enemy_;

	bool playerHealed_ = false;
};

