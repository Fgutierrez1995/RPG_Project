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
	* @brief Method to simulate a Rogue object using his special ability on a Character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void useAbility(Character& target) override;


	/** @brief Method to display all the rogue levels. */
	virtual void displayInfo() const override;

private:

};