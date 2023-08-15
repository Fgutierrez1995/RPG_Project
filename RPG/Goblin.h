#pragma once
#include "Enemy.h"
#include <memory>

class Goblin : public Enemy {
public:
	/*
	* @brief Default Constructor to initalize data members.
	*/
	Goblin() = default;

	/*
	* @brief Constructor to initalize data members
	* @params attackPower The attack power of the goblin.
	* @params defense The defense level of the goblin.
	* @params health The health of the goblin.
	* @params name The name of the goblin.
	*/
	Goblin(double attackPower, double defense, double health, const std::string& name);

	/** @brief Default Destructor.*/
	~Goblin() = default;

	/*
	* @brief Method to simulate a goblin object using his special ability on a character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void useAbility(Character& target) override;

	/** @brief Method to display all the goblin levels. */
	virtual void displayInfo() const override;

	/*
	* @breif Static method to create and return a shared pointer to a goblin object.
	* @params attackPower The attack power of the goblin.
	* @params defense The defense level of the goblin.
	* @params health The health of the goblin
	* @params name The name of the goblin.
	*/
	static std::shared_ptr<Goblin> makeGoblin(double attackPower, double defense, double health, const std::string& name);
};