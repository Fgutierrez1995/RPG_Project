#pragma once
#include "Item.h"

class ArmourItem : public Item {
public:
	/*
	* @breif Constructor for ArmourItem class, initializing with the provided arguments.
	* @param name The name of the armour.
	* @param description The description of the armour.
	* @param defensePower The defense power of the armour.
	*/
	ArmourItem(const std::string& name, const std::string& description, double defensePower);
	
	/** @breif The destructor for the ArmourItem class to clean up necessary resources. */
	~ArmourItem() = default;

	/*
	* @breif Static method to create and return a unique pointer to a ArmourItem object.
	* @param name The name of the armour.
	* @param description The description of the armour.
	* @param defensePower The defense power of the armour.
	*/
	static std::unique_ptr<ArmourItem> makeArmour(const std::string& name, const std::string& description, double defensePower);

	/** @breif Method to perform the action of using the armour item. */
	virtual void use(Character& character) override;

	/** @breif Method to display the stats of the armour item. */
	virtual void displayStats() override;

	/** @breif Method to equip the armour item to a character, enhancing their defense power. */
	virtual void equip(Character& character) override;

	/** @breif Method to unequip the armour item from a character, reverting the defense power. */
	virtual void unEquip(Character& character) override;

	/** @breif Getter method to retrieve the defense power of the armour item. */
	double getDefensePower() const;

	/** @breif Setter method to update the defense power of the armour item. */
	void setDefensePower(double defensePower);

private:
	double defensePower_;
};