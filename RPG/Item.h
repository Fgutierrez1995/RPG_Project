#pragma once
#include <string>
#include <iostream>
#include "Character.h"
#include <memory>

class Character;	// Forward declaration

enum class ItemType
{
	Consumable,
	Weapon,
	Armour
};

class Item {
public:
	/*
	* @breif Constructor to initalize the data members with values.
	* @param name The name of the item.
	* @param description The description of the item.
	* @param type The type of Item (e.g ItemType::Consumable, ItemType::Weapon, ItemType::Armour)
	*/
	Item(const std::string& name, const std::string& description, ItemType type);

	/** @breif Destructor to clean up necessary objects. */
	virtual ~Item() = default;

	/**@breif virtual abstract function that will represent the use method of each item. */
	virtual void use(Character& character) = 0;
	virtual void displayStats() = 0;
	virtual void equip(Character& character) = 0;
	virtual void unEquip(Character& character) = 0;

	/** @brief Method to get the name of the item.*/
	std::string getName() const;

	/** @brief Method to get the description of the item.*/
	std::string getDescription() const;

	/** @brief Method to get the name of the type of item.*/
	ItemType getType() const;

	/** @brief Method to set the name of the item. */
	void setName(const std::string& name);

	/** @brief Method to set the description of the item. */
	void setDescription();

	/** @brief Method set the itemEquiped_ to true or false. */
	void setWeaponEquippedStatus();

	/** @breif Method to check if the item is already equip. */
	bool isWeaponEquipped() const;

	/** @brief Method set the itemEquiped_ to true or false. */
	void setArmourEquippedStatus();

	/** @breif Method to check if the item is already equip. */
	bool isArmourEquipped() const;

private:
	std::string name_ = "";
	std::string description_ = "";
	ItemType type_;
	bool weaponEquipped_ = false;
	bool armourEquipped_ = false;
};