#include "Mage.h"
// Constructor
Mage::Mage(double attackPower, double defense, double health, const std::string& name) :
	Character(attackPower, defense, health, name) {}

// Method to simulate mage attacking another character target.
void Mage::attack(Character& target) {
	std::cout << getName() << " attacked " << target.getName() << "!\n";
	std::cout << target.getName() << " was damaged by " << (getAttackPower() - (target.getDefenseLevel() * .5)) << "!!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower() - (target.getDefenseLevel() * .5)));

	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
		// Check if mage levels up
		levelUp();
	}
}

// Method to simulate mage attacking with is special Ability at a Character Target.
void Mage::useAbility(Character& target) {
	std::cout << getName() << " used special ability, Channeling Arcane Brilliance: Unleash the Power of the Elements!!!!\n";
	std::cout << "Embrace your pain " << target.getName() << ", as I siphon life with each spell!\n";
	// Mages special ability also adds health
	setHealth(getHealth() + getAttackPower());
	std::cout << getName() << " heals by " << getAttackPower() << ".\n";
	std::cout << target.getName() << " was damaged by " << getAttackPower() << "!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower()));
	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
		// Check if mage levels up
		levelUp();
	}
}

// Method to heal the mage.
void Mage::heal() {
	std::cout << getName() << " heals by  " << (getMaxHealth() * .20) << "!!\n\n";
	setHealth(getHealth() + (getMaxHealth() * .20));
}

// Method to increase the warrior levels. 
void Mage::levelUp() {
	if (getExperience() >= 1000) {
		std::cout << getName() << " leveled up!!\n\n";
		// Increases attack power by 1.
		setAttackPower(getAttackPower() + 1);
		// Increased defense power by 1.
		setDefenseLevel(getDefenseLevel() + 1);
		// Increases new max health by (attack + defense * 2).
		setMaxHealth((getAttackPower() + getDefenseLevel()) * 2);
		// Update the health with the current max health.
		setHealth(getMaxHealth());
		// Increases combat level by (attack + defense / 2).
		setCombatLevel((getAttackPower() + getDefenseLevel()) / 2);
		// Reset experience to 0.
		setExperience(0);
	}
}

// Method to check if health is less than or equal to 0.
bool Mage::isDead() const {
	return getHealth() <= 0;
}

// Method to check if health is greater than 0;
bool Mage::isAlive() const {
	return getHealth() > 0;
}

// Method to display mage stats. 
void Mage::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
	std::cout << getName() << " Combat Level: " << getCombatLevel() << std::endl;
	std::cout << getName() << " Total Experience: " << getExperience() << std::endl << std::endl;
}