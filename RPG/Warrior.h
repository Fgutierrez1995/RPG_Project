#pragma once
#include "Character.h"
#include <iostream>


class Warrior : public Character {
public:
	/*
	* @brief Default Constructor to initalize data members.
	*/
	Warrior() = default;

	/*
	* @brief Constructor to initalize data members
	* @params health The health of the warrior.
	* @params attackPower The attack power of the warrior.
	* @params defense The defense level of the warrior.
	* @params combatLevel The combat level of the warrior.
	*/
	Warrior(int health, int attackPower, int defense, int combatLevel);

	/*
	* @brief Default Destructor.
	*/
	 ~Warrior() = default;

	virtual void attack(Character& target) override;
	virtual void defend(int incomingDage) override;
	virtual void useAbility(Character& target) override;
	virtual void heal(int amount) override;
	virtual void levelUp() override;
	virtual void displayInfo() const override;

private:
	int warriorExperience_ = 0;
	int experienceRecieved_ = 1;
};