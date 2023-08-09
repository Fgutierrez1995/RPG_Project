#include "ArmourItem.h"

// Constructor for ArmourItem class, initializing with the provided arguments.
ArmourItem::ArmourItem(const std::string& name, const std::string& description, double defensePower) : 
	Item(name, description, ItemType::Armour), defensePower_(defensePower) {}

// Static method to create and return a unique pointer to a ArmourItem object.
std::unique_ptr<ArmourItem> ArmourItem::makeArmour(const std::string& name, const std::string& description, double defensePower) {
	return std::make_unique<ArmourItem>(name, description, defensePower);
}

// Method to perform the action of using the armour item.
void ArmourItem::use(Character& character) {
	std::cout << getName() << " armour equipped.\n";
}

// Method to display the stats of the armour item.
void ArmourItem::displayStats() {
	std::cout << "Armour Name: " << getName() << std::endl;
	std::cout << "Armour Description: " << getDescription() << std::endl;
	std::cout << "Armour Type: " << static_cast<int>(getType()) << std::endl;
	std::cout << "Armour Defense Power: " << getDefensePower() << std::endl;
	std::cout << "Item equipped: " << std::boolalpha << isArmourEquipped() << std::endl << std::endl;
}

// Method to equip the armour item to a character, enhancing their defense power.
void ArmourItem::equip(Character& character) {
	character.setDefenseLevel(character.getDefenseLevel() + getDefensePower());
	setArmourEquippedStatus();
}

// Method to unequip the armour item from a character, reverting the defense power.
void ArmourItem::unEquip(Character& character) {
	character.setDefenseLevel(character.getDefenseLevel() - getDefensePower());
	setArmourEquippedStatus();
}

// Getter method to retrieve the defense power of the armour item.
double ArmourItem::getDefensePower() const { return defensePower_; }

// Setter method to update the defense power of the armour item.
void ArmourItem::setDefensePower(double defensePower) { defensePower_ = defensePower; }



