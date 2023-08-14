#include "Item.h"

// Constructor
Item::Item(const std::string& name, const std::string& description, ItemType type) : name_(name), description_(description), type_(type) {}

// Getter Methods
std::string Item::getName() const { return name_; }
std::string Item::getDescription() const { return description_; }
ItemType Item::getType() const { return type_; }

// Setter Methods
void Item::setName(const std::string& name) { name_ = name; }

void Item::setDescription() {
	std::string description = "";
	std::cout << "Enter the items description." << std::endl;
	std::getline(std::cin, description);
	description_ = description;
}

// Return the bool value of the weapon if its equipped or not.
bool Item::isWeaponEquipped() const { return weaponEquipped_; }

// Return the bool value of the armour if its equipped or not.
bool Item::isArmourEquipped() const { return armourEquipped_; }


// Method that sets the weaponEquipped_
void Item::setWeaponEquippedStatus() {
	if (isWeaponEquipped()) {
		weaponEquipped_ = false;
	}
	else {
		weaponEquipped_ = true;
	}
}

// Method that sets the armourEquipped_
void Item::setArmourEquippedStatus() {
	if (isArmourEquipped()) {
		armourEquipped_ = false;
	}
	else {
		armourEquipped_ = true;
	}
}



