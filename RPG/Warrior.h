#pragma once
#include "Character.h"
#include <iostream>
#include <memory>


class Warrior : public Character {
public:
	/*
	* @brief Default Constructor to initalize data members.
	*/
	Warrior() = default;

	/*
	* @brief Constructor to initalize data members
	* @params attackPower The attack power of the warrior.
	* @params defense The defense level of the warrior.
	* @params health The health of the warrior.
	* @params name The name of the warrior.
	*/
	Warrior(double attackPower, double defense, double health, const std::string& name);

	/** @brief Default Destructor.*/
	 ~Warrior() = default;

	/*
	* @brief Method to simulate a Warrior object attacking a Character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void attack(Character& target) override;


	/*
	* @brief Method to simulate a Warrior object using his special ability on a Character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void useAbility(Character& target) override;

	/*
	* @brief Method to simulate a Warrior healing themselves.
	* @param amount The amount the Warrior is healed by.
	*/
	virtual void heal() override;

	/** @brief Method is used to level up the warrior object. This method increased the warriors attack, defense, combat, health level.*/
	virtual void levelUp() override;

	/** @brief Method to check if the Warrior is dead (health is zero or less). */
	virtual bool isDead() const override;

	/** @brief Method to check if the Warrior is alive (health is greater than zero). */
	virtual bool isAlive() const override;

	/** @brief Method to display all the Warrior levels. */
	virtual void displayInfo() const override;

private:

};