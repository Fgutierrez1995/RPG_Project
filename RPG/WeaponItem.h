#pragma once
#include "Item.h"

class WeaponItem : public Item {
public:
	/*
	* @breif Constructor for WeaponItem class, initializing with the provided arguments.
	* @param name The name of the weapon.
	* @param description The description of the weapon.
	* @param attackPower The attack power of the weapon.
	*/
	WeaponItem(const std::string& name, const std::string& description, double attackPower);

	/** @breif The destructor for the WeaponItem class to clean up necessary resources. */
	~WeaponItem() = default;

	/** @breif Method to perform the action of using the weapon item. */
	virtual void use(Character& character) override;

	/** @breif Method to display the stats of the weapon item. */
	virtual void displayStats() override;

	/** @breif Method to equip the weapon item to a character, enhancing their attack power. */
	virtual void equip(Character& character) override;

	/** @breif Method to unequip the weapon item from a character, reverting the attack power. */
	virtual void unEquip(Character& character) override;

	/** @breif Getter method to retrieve the attack power of the weapon item. */
	double getAttackPower() const;

	/** @breif Setter method to update the attack power of the weapon item. */
	void setAttackPower(double attackPower);

	/*
	* @breif Static method to create and return a unique pointer to a WeaponItem object.
	* @param weaponName The name of the weapon.
	* @param descr The description of the weapon.
	* @param power The attack power of the weapon.
	*/
	static std::unique_ptr<WeaponItem> makeWeapon(const std::string& weaponName, const std::string& descr, double power);
private:
	double attackPower_;
};