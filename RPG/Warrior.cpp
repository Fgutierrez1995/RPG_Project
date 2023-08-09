#include "Warrior.h"
// Constructor
Warrior::Warrior(double attackPower, double defense, double health, const std::string& name) :
	Character(attackPower, defense, health, name) {}

// Method to simulate Warrior attacking with is special Ability at a Character Target.
void Warrior::useAbility(Character& target) {
	// useAbility is only able to be used every 3 turns.
	if (getCoolDown() == 0) {
		setCoolDown(3);
	}
	double damage = damageGiven(target);
	std::cout << getName() << " used special ability, Unleashing the Fury of a Thousand Suns!!!\n";
	std::cout << "Brance yourself " << target.getName() << " your about to take the force of a Thousand Suns!\n";
	std::cout << target.getName() << " was damaged by " << (damage * 2) << "!\n\n";
	target.setHealth(target.getHealth() - (damage * 2));
}

// Method to display warrior stats. 
void Warrior::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
	std::cout << getName() << " Combat Level: " << getCombatLevel() << std::endl;
	std::cout << getName() << " Total Experience: " << getExperience() << std::endl << std::endl;
}