#pragma once

class Character {
public:

	/*
	* @brief Default Constructor to initalize data members.
	*/
	Character() = default;

	/*
	* @brief Constructor to initalize data members
	* @params health The health of the character.
	* @params attackPower The attack power of the character.
	* @params defense The defense level of the character.
	* @params combatLevel The combat level of the character.
	*/
	Character(int health, int attackPower, int defense, int combatLevel);

	/*
	* @brief Default Destructor.
	*/
	virtual ~Character() = default;

	// Pure Virtual functions for common character actions.
	virtual void attack(Character& target) = 0;
	virtual void defend(int incomingDage) = 0;
	virtual void useAbility(Character& target) = 0;
	virtual void heal(int amount) = 0;
	virtual void levelUp() = 0;
	virtual void displayInfo() const = 0;

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

	/** @brief Returns the health of the character.*/
	int getHealth() const;

	/** @brief Returns the attack power of the character.*/
	int getAttackPower() const;

	/** @brief Returns the defense level of the character.*/
	int getDefenseLevel() const;

	/** @brief Returns the combat level of the character.*/
	int getCombatLevel() const;

private:
	int health_ = 0;
	int attackPower_ = 0;
	int defense_ = 0;
	int combatLevel_ = 1;

};