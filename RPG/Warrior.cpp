#include "Warrior.h"
// Constructor
Warrior::Warrior(double attackPower, double defense, double health, const std::string& name) :
	Character(attackPower, defense, health, name) {}

// Method to simulate Warrior attacking another Character Target.
void Warrior::attack(Character& target) {
	std::cout << getName() << " attacked " << target.getName() << "!\n";
	std::cout << target.getName() << " was damaged by " << (getAttackPower() - (target.getDefenseLevel() * .5)) << "!!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower() - (target.getDefenseLevel() * .5)));

	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
	}
}


// Method to simulate Warrior attacking with is special Ability at a Character Target.
void Warrior::useAbility(Character& target) {
	std::cout << getName() << " used special ability, Unleashing the Fury of a Thousand Suns!!!\n";
	std::cout << "Brance yourself " << target.getName() << " your about to take the force of a Thousand Suns!\n";
	std::cout << target.getName() << " was damaged by " << (getAttackPower() * 2) << "!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower() * 2));
	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
	}
}

// Method to heal the warrior.
void Warrior::heal() {
	std::cout << getName() << " heals by  " << (getMaxHealth() * .20) << "!!\n\n";
	setHealth(getHealth() + (getMaxHealth() * .20));
}

// Method to increase the warrior levels. 
void Warrior::levelUp() {
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

// Method to check if health is less than or equal to 0.
bool Warrior::isDead() const {
	return getHealth() <= 0;
}

// Method to check if health is greater than 0.
bool Warrior::isAlive() const {
	return getHealth() > 0;
}

// Method to display warrior stats. 
void Warrior::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
	std::cout << getName() << " Combat Level: " << getCombatLevel() << std::endl;
	std::cout << getName() << " Total Experience: " << getExperience() << std::endl << std::endl;
}