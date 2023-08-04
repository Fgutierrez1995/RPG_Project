#pragma once
#include "string"
#include <random>
#include <iostream>

class Character {
public:

	/*
	* @brief Default Constructor to initalize data members.
	*/
	Character() = default;

	/*
	* @brief Constructor to initalize data members
	* @params attackPower The attack power of the character.
	* @params defense The defense level of the character.
	* @params health The health of the character.
	* @params name The name of the character.
	*/
	Character(double attackPower, double defense, double health, const std::string& name);

	/*
	* @brief Default Destructor.
	*/
	virtual ~Character() = default;

	// Pure Virtual functions for common character actions.
	virtual void attack(Character& target) = 0;
	virtual void useAbility(Character& target) = 0;
	virtual void heal() = 0;
	virtual void levelUp() = 0;
	virtual void displayInfo() const = 0;
	virtual bool isDead() const = 0;
	virtual bool isAlive() const = 0;

	/*
	* @breif Sets the health of the character.
	* @param health The health assigned to the character.
	*/
	void setHealth(double health);

	/*
	* @breif Sets the attack power of the character.
	* @param attackPower The attack power assigned to the character.
	*/
	void setAttackPower(double attackPower);

	/*
	* @breif Sets the defense level of the character.
	* @param defense The defense level assigned to the character.
	*/
	void setDefenseLevel(double defense);

	/*
	* @breif Sets the combat level of the character.
	* @param combatLevel The combatLevel assigned to the character.
	*/
	void setCombatLevel(int combatLevel);

	/*
	* @breif Sets the total experience of the character.
	* @param experience The experience assigned to the character.
	*/
	void setExperience(int experience);

	/*
	* @breif Sets the name of the character.
	* @param name The name assigned to the character.
	*/
	void setName(const std::string& name);

	/*
	* @breif Sets the max health of the character
	* @param maxHealth The max health assigned to the character.
	*/
	void setMaxHealth(double maxHealth);

	/*
	* @breif Sets the cool down for the character after using their useAbility() method.
	* @param coolDown The value set to the coolDown_ to the character.
	*/
	void setCoolDown(int coolDown);


	/** @brief Returns the health of the character.*/
	double getHealth() const;

	/** @brief Returns the attack power of the character.*/
	double getAttackPower() const;

	/** @brief Returns the defense level of the character.*/
	double getDefenseLevel() const;

	/** @brief Returns the combat level of the character.*/
	int getCombatLevel() const;

	/** @brief Returns the total experience of the character.*/
	int getExperience() const;

	/** @brief Returns the name of the character.*/
	std::string getName() const;

	/** @breif Returns the max health of the charcter. */
	double getMaxHealth() const;

	/** @breif Returns the cool down of the character. */
	int getCoolDown() const;

	/*
	* @brief Method to return random number between min and max.
	* @params min The min iterator range.
	* @params max The max iterator range.
	*/
	static int getRandomNumber(int min, int max);

	// Method to determine how hard the character hits.
	double damageGiven(Character& target);


private:
	double attackPower_ = 1;
	double defense_ = 1;
	int combatLevel_ = (attackPower_ + defense_) / 2;
	double health_ = 0;
	double maxHealth_ = health_;
	int totalExperience_ = 0;
	int coolDown_ = 0;
	std::string name_ = "";

};