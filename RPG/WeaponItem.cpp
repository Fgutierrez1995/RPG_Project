#include "WeaponItem.h"

// Constructor for WeaponItem class, initializing with the provided arguments.
WeaponItem::WeaponItem(const std::string& name, const std::string& description, double attackPower) : Item(name, description, ItemType::Weapon), attackPower_(attackPower) {}

// Method to perform the action of using the weapon item.
void WeaponItem::use(Character& character) {
	std::cout << "Weapon equipped.\n";
}

// Method to display the stats of the weapon item.
void WeaponItem::displayStats() {
	std::cout << "Weapon Name: " << getName() << std::endl;
	std::cout << "Weapon Description: " << getDescription() << std::endl;
	std::cout << "Weapon Type: " << static_cast<int>(getType()) << std::endl;
	std::cout << "Weapon Power: " << getAttackPower() << std::endl;
	std::cout << "Item equipped: " << std::boolalpha << isWeaponEquipped() << std::endl << std::endl;
}

// Method to equip the weapon item to a character, enhancing their attack power.
void WeaponItem::equip(Character& character) {
	character.setAttackPower(character.getAttackPower() + getAttackPower());
	setWeaponEquippedStatus();
}

// Method to unequip the weapon item from a character, reverting the attack power.
void WeaponItem::unEquip(Character& character) {
	character.setAttackPower(character.getAttackPower() - getAttackPower());
	setWeaponEquippedStatus();
}

// Getter method to retrieve the attack power of the weapon item.
double WeaponItem::getAttackPower() const { return attackPower_; }

// Setter method to update the attack power of the weapon item.
void WeaponItem::setAttackPower(double attackPower) { attackPower_ = attackPower; }

// Static method to create and return a unique pointer to a WeaponItem object.
std::unique_ptr<WeaponItem> WeaponItem::makeWeapon(const std::string& weaponName, const std::string& descr, double power) {

	return std::make_unique<WeaponItem>(weaponName, descr, power);
}
