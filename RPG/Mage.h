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
	* @brief Method to simulate a Mage object using his special ability on a Character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void useAbility(Enemy& target) override;

	/** @brief Method to display all the mage levels. */
	virtual void displayInfo() const override;

	/** @breif Getter method to return the classType of the character. */
	virtual std::string getClassType() const override;

private:
	std::string classType_ = "Mage";
};