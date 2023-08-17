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
	* @brief Method to simulate a Warrior object using his special ability on a Character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void useAbility(Enemy& target) override;

	/** @brief Method to display all the Warrior levels. */
	virtual void displayInfo() const override;

	/** @breif Getter method to return the classType of the character. */
	virtual std::string getClassType() const override;

private:
	std::string classType_ = "Warrior";
};