#include "Rogue.h"
// Constructor
Rogue::Rogue(double attackPower, double defense, double health, const std::string& name) :
	Character(attackPower, defense, health, name) {}

// Method to simulate rogue attacking with is special Ability at a Character Target.
void Rogue::useAbility(Enemy& target) {
	// useAbility is only able to be used every 3 turns.
	if (getCoolDown() == 0) {
		setCoolDown(3);
	}
	double damage = damageGiven(target);
	std::cout << "\n" << getName() << " used special ability, Vanishing Shadows: Dance with Deception and Strike from the Shadows!!!!\n";
	std::cout << "Now you see me... Now you don't...\n";
	std::cout << "\n" << target.getName() << " was damaged by " << (damage * 2.5) << "!\n\n";

	target.setHealth(target.getHealth() - (damage * 2.5));
}

// Method to display rogue stats. 
void Rogue::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
	std::cout << getName() << " Combat Level: " << getCombatLevel() << std::endl;
	std::cout << getName() << " Total Experience: " << getExperience() << std::endl << std::endl;
}