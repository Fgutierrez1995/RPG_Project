#pragma once
#include "Enemy.h"
#include <memory>

class Orc : public Enemy {
public:
	/*
	* @brief Default Constructor to initalize data members.
	*/
	Orc() = default;

	/*
	* @brief Constructor to initalize data members
	* @params attackPower The attack power of the ork.
	* @params defense The defense level of the ork.
	* @params health The health of the ork.
	* @params name The name of the ork.
	*/
	Orc(double attackPower, double defense, double health, const std::string& name);

	/** @brief Default Destructor.*/
	~Orc() = default;

	/*
	* @brief Method to simulate a orc object using his special ability on a character target.
	* @parmas target The character target that is under attack.
	*/
	virtual void useAbility(Character& target) override;

	/** @brief Method to display all the orc levels. */
	virtual void displayInfo() const override;

	/*
	* @breif Static method to create and return a shared pointer to a Orc object.
	* @params attackPower The attack power of the ork.
	* @params defense The defense level of the ork.
	* @params health The health of the ork.
	* @params name The name of the ork.
	*/
	static std::shared_ptr<Orc> makeOrc(double attackPower, double defense, double health, const std::string& name);


private:

};