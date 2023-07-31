#include "Warrior.h"
// Constructor
Warrior::Warrior(int attackPower, int defense, const std::string& name) :
	Character(attackPower, defense, name) {}

// Method to simulate Warrior attacking another Character Target.
void Warrior::attack(Character& target) {
	std::cout << getName() << " attacked " << target.getName() << "!!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower() - (target.getDefenseLevel() * .5)));

	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
		setExperience(getExperience() + 500);
		// Check if Warrior levels up
		levelUp();
	}
}


// Method to simulate Warrior attacking with is special Ability at a Character Target.
void Warrior::useAbility(Character& target) {
	std::cout << getName() << " used special ability, Unleashing the Fury of a Thousand Suns!!!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower() * 2));
	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
		setExperience(getExperience() + 250);
		// Check if Warrior levels up
		levelUp();
	}
}

// Method to heal the warrior. Takes int amount and adds to warrior overrall health.
void Warrior::heal(int amount) {
	std::cout << getName() << " heals by  " << amount << "!!\n\n";
	setHealth(getHealth() + amount);
}

// Method to increase the warrior levels. 
void Warrior::levelUp() {
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
bool Warrior::isDead() const {
	return getHealth() <= 0;
}

// Method to display warrior stats. 
void Warrior::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
	std::cout << getName() << " Combat Level: " << getCombatLevel() << std::endl;
	std::cout << getName() << " Total Experience: " << getExperience() << std::endl << std::endl;
}