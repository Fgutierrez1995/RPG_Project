#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include "Character.h"

class Character;	// Forward declaration. 

class Enemy {
public:
	/*
	* @brief Default Constructor to initalize data members.
	*/
	Enemy() = default;

	/*
	* @brief Constructor to initalize data members
	* @params attackPower The attack power of the enemy.
	* @params defense The defense level of the enemy.
	* @params health The health of the enemy.
	* @params name The name of the enemy.
	*/
	Enemy(double attackPower, double defense, double health, const std::string& name);

	/*
	* @brief Default Destructor.
	*/
	virtual ~Enemy() = default;

	// Pure Virtual functions for common character actions.
	virtual void useAbility(Character& target) = 0;
	virtual void displayInfo() const = 0;

	/*
	* @breif Sets the health of the enemy.
	* @param health The health assigned to the enemy.
	*/
	void setHealth(double health);

	/*
	* @breif Sets the attack power of the enemy.
	* @param attackPower The attack power assigned to the enemy.
	*/
	void setAttackPower(double attackPower);

	/*
	* @breif Sets the defense level of the enemy.
	* @param defense The defense level assigned to the enemy.
	*/
	void setDefenseLevel(double defense);


	/*
	* @breif Sets the name of the enemy.
	* @param name The name assigned to the enemy.
	*/
	void setName(const std::string& name);

	/*
	* @breif Sets the cool down for the enemy after using their useAbility() method.
	* @param coolDown The value set to the coolDown_ to the enemy.
	*/
	void setCoolDown(int coolDown);


	/** @brief Returns the health of the enemy.*/
	double getHealth() const;

	/** @brief Returns the attack power of the enemy.*/
	double getAttackPower() const;

	/** @brief Returns the defense level of the enemy.*/
	double getDefenseLevel() const;

	/** @brief Returns the name of the enemy.*/
	std::string getName() const;

	/** @breif Returns the cool down of the enemy. */
	int getCoolDown() const;

	/*
	* @brief Method to return random number between min and max.
	* @params min The min iterator range.
	* @params max The max iterator range.
	*/
	static int getRandomNumber(int min, int max);

	/** @breif Method to determine how hard the enemy hits. */
	double damageGiven(Character& target);

	/*
	* @brief Method to simulate a character object attacking a character target.
	* @parmas target The character target that is under attack.
	*/
	void attack(Character& target);

	/** @brief Method to check if the enemy is dead (health is zero or less). */
	bool isDead() const;

	/** @brief Method to check if the enemy is alive (health is greater than zero). */
	bool isAlive() const;


private:
	double attackPower_ = 1;
	double defense_ = 1;
	double health_ = 0;
	int coolDown_ = 0;
	std::string name_ = "";
};
