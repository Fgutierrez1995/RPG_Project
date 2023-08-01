#pragma once
#include "Character.h"
#include <iostream>


class Mage : public Character {
public:
	/*
	* @brief Default Constructor to initalize data members.
	*/
	Mage() = default;

	/*
	* @brief Constructor to initalize data members
	* @params attackPower The attack power of the mage.
	* @params defense The defense level of the mage.
	* @params health The health of the mage.
	* @params name The name of the mage.
	*/
	Mage(double attackPower, double defense, double health, const std::string& name);

	/** @brief Default Destructor. */
	~Mage() = default;

	/*
	* @brief Method to simulate a Mage object attacking a Character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void attack(Character& target) override;

	/*
	* @brief Method to simulate a Mage object using his special ability on a Character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void useAbility(Character& target) override;

	/*
	* @brief Method to simulate a mage healing themselves.
	* @param amount The amount the mage is healed by.
	*/
	virtual void heal() override;

	/** @brief Method is used to level up the mage object. This method increased the mage attack, defense, combat, health level. */
	virtual void levelUp() override;

	/** @brief Method to check if the mage is dead (health is zero or less). */
	virtual bool isDead() const override;

	/** @brief Method to check if the mage is alive (health is greater than zero). */
	virtual bool isAlive() const override;

	/** @brief Method to display all the mage levels. */
	virtual void displayInfo() const override;

private:

};