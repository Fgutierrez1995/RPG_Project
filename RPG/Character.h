#pragma once
#include "string"
#include <random>
#include <vector>
#include <memory>
#include <iostream>
#include "Item.h"


class Item; // Forward declaration.

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
	//virtual void attack(Character& target) = 0;
	virtual void useAbility(Character& target) = 0;
	//virtual void levelUp() = 0;
	virtual void displayInfo() const = 0;
	//virtual bool isDead() const = 0;
	//virtual bool isAlive() const = 0;

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

	/** @breif Method to determine how hard the character hits. */ 
	double damageGiven(Character& target);

	/*
	* @brief Method to simulate a character object attacking a character target.
	* @parmas target The character target that is under attack.
	*/
	void attack(Character& target);

	/** @brief Method is used to level up the warrior object. This method increased the warriors attack, defense, combat, health level.*/
	void levelUp();

	/** @brief Method to check if the character is dead (health is zero or less). */
	bool isDead() const;

	/** @brief Method to check if the character is alive (health is greater than zero). */
	bool isAlive() const;

	/** @brief Method to simulate a Character healing themselves. */
	void heal();

	void displayConsumableInInventory();

	/** @breif Method to determine if the inventory_ is empty or not. */
	bool isInventoryEmpty() const;

	/** @breif Add item to inventory. */
	void addItem(std::unique_ptr<Item> item);

	/*
	* @breif Method to sort the inventory by ItemType (e.g ItemType::Consumable, ItemType::Weapon, ItemType::Armour).
	* @param item1 The first comparison item object.
	* @param item2 The second comparison item oject.
	*/
	static bool compareType(const std::unique_ptr<Item>& item1, const std::unique_ptr<Item>& item2);

	/** @brief Method to display the items in the inventory. */
	void displayInventory();

	/** @brief Method to display the items that are currently equipped by the character. */
	void displayEquippedItems();

	/** @brief Method to display the weapon and armour items in the inventory. */
	void displayWeaponsandArmourItems();

	/** @brief Method to display if the character has a weapon equipped. */
	bool hasWeaponEquipped();

	/** @brief Method to display if the character has a armour equipped. */
	bool hasArmourEquipped();

	/** @brief Method to display if the character has consumable item available. */
	bool hasConsumableItems();

	/** @breif Method to equip a item in the inventory. */
	void equipItem();

	/** @breif Method to unequip a item in the inventory. */
	void unequippedItem();

	/** @bried Method to remove a item in the inventory. */
	void removeItem();

	/** @breif Method to make sure the user input is valid. */
	int safeInputInt(); 


private:
	double attackPower_ = 1;
	double defense_ = 1;
	int combatLevel_ = (attackPower_ + defense_) / 2;
	double health_ = 0;
	double maxHealth_ = health_;
	int totalExperience_ = 0;
	int coolDown_ = 0;
	std::string name_ = "";
	std::vector<std::unique_ptr<Item>> inventory_;
};