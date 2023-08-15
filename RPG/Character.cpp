#include "Character.h"

// Constructor
Character::Character(double attackPower, double defense, double health, const std::string& name) : attackPower_(attackPower), defense_(defense), health_(health), name_(name) {}

// Setter Methods
void Character::setAttackPower(double attackPower) { attackPower_ = attackPower; }
void Character::setDefenseLevel(double defense) { defense_ = defense; }
void Character::setHealth(double health) { health_ = health; }
void Character::setCombatLevel(int combatLevel) { combatLevel_ = combatLevel; }
void Character::setExperience(int experience) { totalExperience_ = experience; }
void Character::setName(const std::string& name) { name_ = name; }
void Character::setMaxHealth(double maxHealth) { maxHealth_ = maxHealth; }
void Character::setCoolDown(int coolDown) { coolDown_ = coolDown; }

// Getter Methods
double Character::getAttackPower() const { return attackPower_; }
double Character::getDefenseLevel() const { return defense_; }
double Character::getHealth() const { return health_; }
int Character::getCombatLevel() const { return combatLevel_; }
int Character::getExperience() const { return totalExperience_; }
std::string Character::getName() const { return name_; }
double Character::getMaxHealth() const { return maxHealth_; }
int Character::getCoolDown() const { return coolDown_; }

// Method to return a random number between min and max.
int Character::getRandomNumber(int min, int max) {
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(min, max);
	return distr(eng);
}

// Method to determine the attack damage given
double Character::damageGiven(Enemy& target) {
	// Get a random number between 0 and 100.
	int randomNumber = getRandomNumber(0, 100);
	// Turn the random number into a fraction.
	double potentialDamage = randomNumber / 100.00;
	// Determine the damage.
	double damage = getAttackPower() - ((getAttackPower() - (target.getDefenseLevel() * .5)) * potentialDamage);
	// Return damage.
	return damage;
}

// Method to simulate character attacking another character Target.
void Character::attack(Enemy& target) {
	double damage = damageGiven(target);
	std::cout << "\n" << getName() << " attacked " << target.getName() << "!\n";
	std::cout << target.getName() << " was damaged by " << damage << "!!\n\n";
	target.setHealth(target.getHealth() - damage);
}

// Method to increase the characters levels. 
void Character::levelUp() {
	if (getExperience() >= 1000) {
		std::cout << getName() << " leveled up!!\n\n";
		// Increases attack power by 1.
		setAttackPower(getAttackPower() + 1);
		// Increased defense power by 1.
		setDefenseLevel(getDefenseLevel() + 1);
		// Increases new max health by (attack + defense * 3).
		setMaxHealth((getAttackPower() + getDefenseLevel()) * 3);
		// Update the health with the current max health.
		setHealth(getMaxHealth());
		// Increases combat level by (attack + defense / 2).
		setCombatLevel((getAttackPower() + getDefenseLevel()) / 2);
		// Reset experience to 0.
		setExperience(0);
	}
}

// Method to check if health is greater than 0.
bool Character::isAlive() const {
	return getHealth() > 0;
}

// Method to check if health is less than or equal to 0.
bool Character::isDead() const {
	return getHealth() <= 0;
}


void Character::heal() {
	// If the inventory is empty return.
	if (isInventoryEmpty()) {
		std::cout << "\nInventory is empty. No consumable items.\n";
		return;
	}

	// If the inventory has no consumable items return.
	if (!hasConsumableItems()) {
		std::cout << "\nNo consumable items available..\n";
		return;
	}

	displayConsumableInInventory();
	int itemIndex = 0;
	// Flag variable to break the do-while loop
	bool validChoice = false;

	do {
		std::cout << "\nEnter the item number you would like to consume.\n";
		itemIndex = safeInputInt();		// Use get safeInputInt() to get user input.

		if (itemIndex >= 1 && itemIndex <= inventory_.size()) {
			// Subract 1 to convert from user input index to vector index
			auto selectedItemIter = inventory_.begin() + (itemIndex - 1);

			// A unique_ptr reference of the selectItemIter. Will be used to call use() to heal the character.
			std::unique_ptr<Item>& selectedItem = *selectedItemIter;

			// Check if selectedItem is a consumable item.
			if (selectedItem->getType() == ItemType::Consumable) {
				// If the selectedItem is a consumable item, call use(*this) to heal the character.
				selectedItem->use(*this);
				// Set validChoice to true to break the loop.
				validChoice = true;
			}
			else {
				std::cout << selectedItem->getName() << " is not a consumable item.\n";
			}

			// Erase the selected item from the inventory.
			inventory_.erase(selectedItemIter);
		}
		else {
			std::cout << "There is no such item in your inventory with the number " << itemIndex << ".\n";
		}
	} while (!validChoice);
}

void Character::displayConsumableInInventory() {
	if (isInventoryEmpty()) {
		return;
	}
	// If inventory is not empty
	std::sort(begin(inventory_), end(inventory_), compareType);
	// Used to represent the item index.
	int itemIndex = 1;

	std::cout << "\n***Consumable items in your inventory***\n";
	for (auto& consumable : inventory_) {
		if (consumable->getType() == ItemType::Consumable) {
			std::cout << "\nItem " << itemIndex << ": \n";
			consumable->displayStats();
		}
		++itemIndex;
	}
}

// Method to check if inventory is empty or not.
bool Character::isInventoryEmpty() const {
	if (inventory_.empty()) {
		std::cout << "\nNo item in inventory.\n";
		return true;
	}
	return false;
}

// Method to add a item to the characters inventory.
void Character::addItem(std::unique_ptr<Item> item) {
	inventory_.push_back(std::move(item));
}

// Method to sort the inventory
bool Character::compareType(const std::unique_ptr<Item>& item1, const std::unique_ptr<Item>& item2) {
	// First sort by the item type.
	if (item1->getType() != item2->getType()) {
		return item1->getType() < item2->getType();
	}
	// Then sort by name.
	return item1->getName() < item2->getName();
}

// Method to display the characters inventory
void Character::displayInventory() {

	if (isInventoryEmpty()) {
		return;
	}
	std::sort(begin(inventory_), end(inventory_), compareType);
	int itemNumber = 1;
	
	for (const auto& item : inventory_) {
		std::cout << "\nItem " << itemNumber << ": \n";
		item->displayStats();
		++itemNumber;
	}
}

void Character::displayEquippedItems() {
	// If Inventory is empty return
	if (isInventoryEmpty()) {
		return;
	}
	// If Inventory is not empty.
	std::sort(begin(inventory_), end(inventory_), compareType);

	// Used to represent the item index.
	int itemIndex = 1;

	std::cout << "All items equipped: " << std::endl;
	// Run through the inventory
	for (auto& item : inventory_) {
		// Display only equipped Items.
		if (item->isWeaponEquipped() || item->isArmourEquipped()) {
			std::cout << "\nItem " << itemIndex << ": ";
			item->displayStats();
		}
		++itemIndex;
	}
}

void Character::displayWeaponsandArmourItems() {
	// If Inventory is empty return
	if (isInventoryEmpty()) {
		return;
	}
	// If Inventory is not empty.
	std::sort(begin(inventory_), end(inventory_), compareType);

	// Used to represent the item index.
	int itemIndex = 1;
	for (auto& item : inventory_) {
		if (item->getType() == ItemType::Weapon || item->getType() == ItemType::Armour) {
			std::cout << "\nItem " << itemIndex << ": \n";
			item->displayStats();
		}
		++itemIndex;
	}
}

// Method to check if any weapons are equipped to the character.
bool Character::hasWeaponEquipped() {
	bool hasWeaponEquipped = false;
	for (auto& item : inventory_) {
		if (item->isWeaponEquipped()) {
			hasWeaponEquipped = true;
		}
	}
	return hasWeaponEquipped;
}

// Method to check if any armour is equipped to the character.
bool Character::hasArmourEquipped() {
	bool hasArmourEquipped = false;
	for (auto& item : inventory_) {
		if (item->isArmourEquipped()) {
			hasArmourEquipped = true;
		}
	}
	return hasArmourEquipped;
}

// Method to check if the character has consumable items available.
bool Character::hasConsumableItems() {
	bool hasConsumable = false;
	for (auto& item : inventory_) {
		if (item->getType() == ItemType::Consumable) {
			hasConsumable = true;
		}
	}

	return hasConsumable;
}

// Method to equip a item.
void Character::equipItem() {
	// If Inventory is empty return
	if (isInventoryEmpty()) {
		return;
	}

	// Check if the user already has weapon or armour equipped.
	if (hasWeaponEquipped() && hasArmourEquipped()) {
		std::cout << "\nYou already have a weapon and a armour equipped.\n";
		return;
	}

	// If the Inventory is not empty, Display the Inventory that shows only the weapon and armour.
	displayWeaponsandArmourItems();

	// The item the user wants to equip.
	int itemNumber = 0;
	// Flag variable to break the do-while loop
	bool validChoice = false;

	do {
		std::cout << "\nEnter the Item number you would like to equip.\n";
		itemNumber = safeInputInt(); // use safeInputInt() to get user input.

		// Handle the error if the user enters anything other than an integer.
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         // Ignore newline character
		}

		// Check if the input item number is within a valid range.
		if (itemNumber >= 1 && itemNumber <= inventory_.size()) {
			// Retrieve the selected item based on the item number.
			std::unique_ptr<Item>& selectedItem = inventory_[itemNumber - 1];
			// Weapon Item selected
			if (selectedItem->getType() == ItemType::Weapon) {
				// If the user selects a weapon but they are already have a weapon equipped then return.
				if (hasWeaponEquipped()) {
					std::cout << "\nYou already have a weapon equipped.\n";
					return;
				}
				// If no weapon is currently equipped.
				selectedItem->equip(*this);		// Pass the current character instance.

				std::cout << "\nEquipped item: " << selectedItem->getName() << std::endl;

				// Set the validChoice to true and break the loop
				validChoice = true;
			}
			else if (selectedItem->getType() == ItemType::Armour) {
				// If the user selects a armour but they are already have a armour equipped then return.
				if (hasArmourEquipped()) {
					std::cout << "\nYou already have armour equipped.\n";
					return;
				}
				// If no armour is currently equipped.
				selectedItem->equip(*this);		// Pass the current character instance.

				std::cout << "\nEquipped item: " << selectedItem->getName() << std::endl;

				// Set the validChoice to true and break the loop
				validChoice = true;
			}
			else {
				std::cout << "\nYou cannot equip a consumable item.. Try again.\n";
			}
		}
		else {
			std::cout << "\nInvalid item number. Please try again." << std::endl;
		}
	} while (!(validChoice));
}


void Character::unequippedItem() {
	// If Inventory is empty return or if player does not have any weapon or armour equipped.
	if (isInventoryEmpty() || !(hasArmourEquipped() || hasWeaponEquipped())) {
		if (!(hasArmourEquipped() || hasWeaponEquipped())) {
			std::cout << "\nNo armour or weapon equipped.\n";
		}
		return;
	}
	// Show all the equipped items.
	displayEquippedItems();
	// flag to represent if the item choice is valid and to break the do-while loop.
	bool validChoice = false;
	// Used to read the user selection
	int itemNumber = 0;

	do {
		std::cout << "\nEnter the Item number you would like to unequip.\n";
		itemNumber = safeInputInt();	 // Use safeInputInt() to get user input

		// If the itemNumber is in range of the inventory_
		if (itemNumber >= 1 && itemNumber <= inventory_.size()) {
			// Retreive the item the user selected.
			std::unique_ptr<Item>& selectedItem = inventory_[itemNumber - 1];
			// If selectedItem is a weapon.
			if (selectedItem->getType() == ItemType::Weapon) {
				// Check if the weapon is equipped
				if (selectedItem->isWeaponEquipped()) {
					// Unequip the weapon.
					selectedItem->unEquip(*this);
					std::cout << "\nWeapon unequipped: " << selectedItem->getName() << std::endl;
					// Valid choice is made, set to true and break loop.
					validChoice = true;
				}
				else {
					std::cout << "\nWeapon is not currently equipped." << std::endl;
				}
			}
			// If the selectedItem is a armour.
			else if (selectedItem->getType() == ItemType::Armour) {
				// Check if the armour is currenty selected.
				if (selectedItem->isArmourEquipped()) {
					// Unequip the armour.
					selectedItem->unEquip(*this);
					std::cout << "\nArmour unequipped: " << selectedItem->getName() << std::endl;
					// Valid choice is made, set to true and break loop.
					validChoice = true;
				}
				else {
					std::cout << "\nArmour is not currently equipped." << std::endl;
				}
			}

		}
		else {
			std::cout << "\nThere is no such item in your inventory with the number " << itemNumber << ".\n";
		}
	} while (!validChoice);
}

void Character::removeItem() {
	// If Inventory is empty return
	if (isInventoryEmpty()) {
		return;
	}
	// If inventory is not empty, go ahead and display the inventory to the user.
	displayInventory();
	// The index number of the item in the inventory.
	int itemIndex = 1;
	std::cout << "\nWhat item would you like to remove?\n";
	itemIndex = safeInputInt();		// Use safeInputInt() to get user input

	if (itemIndex >= 1 && itemIndex <= inventory_.size()) {
		// Subract 1 to convert from user input index to vector index
		auto selectedItemIter = inventory_.begin() + (itemIndex - 1);

		// A unique_ptr reference of the selectItemIter. Will be used to unequip the weapon or armour from the character.
		std::unique_ptr<Item>& selectedItem = *selectedItemIter;

		// If the selected item is a weapon and the weapon is equipped.
		if (selectedItem->getType() == ItemType::Weapon && selectedItem->isWeaponEquipped()) {
			selectedItem->unEquip(*this);
		}
		// If the selected item is a armour and the armour is equipped.
		if (selectedItem->getType() == ItemType::Armour && selectedItem->isArmourEquipped()) {
			selectedItem->unEquip(*this);
		}

		// Erase the selected item from the inventory.
		inventory_.erase(selectedItemIter);
		std::cout << "\nItem removed succesfully.\n";
	}
	else {
		std::cout << "\nInvalid item index. \n";
	}
}

int Character::safeInputInt() {
	int input;
	std::cin >> input;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return input;
}
