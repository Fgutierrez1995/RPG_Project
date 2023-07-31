#include "Mage.h"
// Constructor
Mage::Mage(int attackPower, int defense, const std::string& name) :
	Character(attackPower, defense, name) {}

// Method to simulate mage attacking another character target.
void Mage::attack(Character& target) {
	std::cout << getName() << " attacked " << target.getName() << "!!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower() - (target.getDefenseLevel() * .30)));

	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
		setExperience(getExperience() + 500);
		// Check if mage levels up
		levelUp();
	}
}

// Method to simulate mage attacking with is special Ability at a Character Target.
void Mage::useAbility(Character& target) {
	std::cout << getName() << " used his special ability, Channeling Arcane Brilliance: Unleash the Power of the Elements!!!!\n\n";
	// Mages special ability also adds health
	heal(getHealth() / 5);
	target.setHealth(target.getHealth() - (getAttackPower() * 1.5));
	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
		setExperience(getExperience() + 250);
		// Check if mage levels up
		levelUp();
	}
}

// Method to heal the mage. Takes int amount and adds to mage overrall health.
void Mage::heal(int amount) {
	std::cout << getName() << " heals by " << amount << "!!\n\n";
	setHealth(getHealth() + amount);
}

// Method to increase the warrior levels. 
void Mage::levelUp() {
	if (getExperience() >= 1000) {
		std::cout << getName() << " leveled up!!\n\n";
		// Increases attack power by 1.
		setAttackPower(getAttackPower() + 1);
		// Increased defense power by 1.
		setDefenseLevel(getDefenseLevel() + 1);
		// Increases health by (attack + defense * 2).
		setHealth((getAttackPower() + getDefenseLevel()) * 2);
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

// Method to display mage stats. 
void Mage::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
	std::cout << getName() << " Combat Level: " << getCombatLevel() << std::endl;
	std::cout << getName() << " Total Experience: " << getExperience() << std::endl << std::endl;
}