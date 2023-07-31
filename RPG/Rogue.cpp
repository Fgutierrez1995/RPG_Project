#include "Rogue.h"
// Constructor
Rogue::Rogue(int attackPower, int defense, const std::string& name) :
	Character(attackPower, defense, name) {}

// Method to simulate rogue attacking another character target.
void Rogue::attack(Character& target) {
	std::cout << getName() << " attacked " << target.getName() << "!!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower() - (target.getDefenseLevel() * .30)));

	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
		setExperience(getExperience() + 500);
		// Check if rogue levels up
		levelUp();
	}
}

// Method to simulate rogue attacking with is special Ability at a Character Target.
void Rogue::useAbility(Character& target) {
	std::cout << getName() << " used his special ability, Vanishing Shadows: Dance with Deception and Strike from the Shadows!!!!\n\n";

	target.setHealth(target.getHealth() - (getAttackPower() * 2));
	if (target.isDead()) {
		std::cout << getName() << " defeated " << target.getName() << "...\n\n";
		setExperience(getExperience() + 250);
		// Check if rogue levels up
		levelUp();
	}
}

// Method to heal the rogue. Takes int amount and adds to rogue overrall health.
void Rogue::heal(int amount) {
	std::cout << getName() << " heals by " << amount << "!!\n\n";
	setHealth(getHealth() + amount);
}

// Method to increase the rogue levels. 
void Rogue::levelUp() {
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
bool Rogue::isDead() const {
	return getHealth() <= 0;
}

// Method to display rogue stats. 
void Rogue::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
	std::cout << getName() << " Combat Level: " << getCombatLevel() << std::endl;
	std::cout << getName() << " Total Experience: " << getExperience() << std::endl << std::endl;
}