#pragma once
#include "string"

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
	* @params name The name of the character.
	*/
	Character(int attackPower, int defense, const std::string& name);

	/*
	* @brief Default Destructor.
	*/
	virtual ~Character() = default;

	// Pure Virtual functions for common character actions.
	virtual void attack(Character& target) = 0;
	virtual void useAbility(Character& target) = 0;
	virtual void heal(int amount) = 0;
	virtual void levelUp() = 0;
	virtual void displayInfo() const = 0;
	virtual bool isDead() const = 0;

	/*
	* @breif Sets the health of the character.
	* @param health The health assigned to the character.
	*/
	void setHealth(int health);

	/*
	* @breif Sets the attack power of the character.
	* @param attackPower The attack power assigned to the character.
	*/
	void setAttackPower(int attackPower);

	/*
	* @breif Sets the defense level of the character.
	* @param defense The defense level assigned to the character.
	*/
	void setDefenseLevel(int defense);

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


	/** @brief Returns the health of the character.*/
	int getHealth() const;

	/** @brief Returns the attack power of the character.*/
	int getAttackPower() const;

	/** @brief Returns the defense level of the character.*/
	int getDefenseLevel() const;

	/** @brief Returns the combat level of the character.*/
	int getCombatLevel() const;

	/** @brief Returns the total experience of the character.*/
	int getExperience() const;

	/** @brief Returns the name of the character.*/
	std::string getName() const;

private:
	int attackPower_ = 1;
	int defense_ = 1;
	int combatLevel_ = (attackPower_ + defense_) / 2;
	int health_ = (attackPower_ + defense_) * 2;
	int totalExperience_ = 0;
	std::string name_ = "";

};