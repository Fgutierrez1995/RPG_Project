#pragma once
#include "Item.h"

class ConsumableItem : public Item {
public:
	/*
	* @breif Constructor for ConsumableItem class, initializing with the provided arguments.
	* @param name The name of the consumable item.
	* @param description The description of the consumable item.
	* @param healAmount The heal amount of the consumable item.
	*/
	ConsumableItem(const std::string& name, const std::string& description, double healAmount);

	/** @breif The destructor for the ConsumableItem class to clean up necessary resources. */
	~ConsumableItem() = default;

	/*
	* @breif Static method to create and return a unique pointer to a ConsumableItem object.
	* @param name The name of the consumable item.
	* @param description The description of the consumable item.
	* @param healAmount The heal amount of the consumable item.
	*/
	static std::unique_ptr<ConsumableItem> makeConsumable(const std::string& name, const std::string& description, double healAmount);

	/** @breif Method to use a consumable item on the character. */
	virtual void use(Character& character);

	/** @breif Method display the consumable item stats. */
	virtual void displayStats();

	/** @breif Abstract method that is required for this class to implement but will not be used. */
	virtual void equip(Character& character) override;

	/** @breif Abstract method that is required for this class to implement but will not be used. */
	virtual void unEquip(Character& character) override;

	/** @breif Getter method to retrieve the heal amount of the consumable item. */
	double getHealAmount() const;

	/** @breif Setter method to update the heal amount of the consumable item. */
	void setHealAmount(double healAmount);

private:
	double healAmount_;
};