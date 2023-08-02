#pragma once
#include "Character.h"
#include <iostream>


class Rogue : public Character {
public:
	/*
	* @brief Default Constructor to initalize data members.
	*/
	Rogue() = default;

	/*
	* @brief Constructor to initalize data members
	* @params attackPower The attack power of the rogue.
	* @params defense The defense level of the rogue.
	* @params health The health of the rogue.
	* @params name The name of the rogue.
	*/
	Rogue(double attackPower, double defense, double health, const std::string& name);

	/** @brief Default Destructor. */
	~Rogue() = default;

	/*
	* @brief Method to simulate a Rogue object attacking a Character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void attack(Character& target) override;

	/*
	* @brief Method to simulate a Rogue object using his special ability on a Character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void useAbility(Character& target) override;

	/*
	* @brief Method to simulate a Rogue healing themselves.
	* @param amount The amount the mage is healed by.
	*/
	virtual void heal() override;

	/** @brief Method is used to level up the rogue object. This method increased the mage attack, defense, combat, health level. */
	virtual void levelUp() override;

	/** @brief Method to check if the rogue is dead (health is zero or less). */
	virtual bool isDead() const override;

	/** @brief Method to check if the rogue is alive (health is greater than zero). */
	virtual bool isAlive() const override;

	/** @brief Method to display all the rogue levels. */
	virtual void displayInfo() const override;

private:

};