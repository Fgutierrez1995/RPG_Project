#pragma once
#include "Enemy.h"
#include <memory>

class DarkMage : public Enemy {
public:
	/*
	* @brief Default Constructor to initalize data members.
	*/
	DarkMage() = default;

	/*
	* @brief Constructor to initalize data members
	* @params attackPower The attack power of the dark mage.
	* @params defense The defense level of the dark mage.
	* @params health The health of the dark mage.
	* @params name The name of the dark mage.
	*/
	DarkMage(double attackPower, double defense, double health, const std::string& name);

	/** @brief Default Destructor.*/
	~DarkMage() = default;

	/*
	* @brief Method to simulate a dark mage object using his special ability on a character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void useAbility(Character& target) override;

	/** @brief Method to display all the dark mage levels. */
	virtual void displayInfo() const override;

	/*
	* @breif Static method to create and return a shared pointer to a dark mage object.
	* @params attackPower The attack power of the dark mage.
	* @params defense The defense level of the dark mage.
	* @params health The health of the dark mage.
	* @params name The name of the dark mage.
	*/
	static std::shared_ptr<DarkMage> makeDarkMage(double attackPower, double defense, double health, const std::string& name);
};