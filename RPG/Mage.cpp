#include "Mage.h"
// Constructor
Mage::Mage(double attackPower, double defense, double health, const std::string& name) :
	Character(attackPower, defense, health, name) {}


// Method to simulate mage attacking with is special Ability at a Character Target.
void Mage::useAbility(Enemy& target) {
	// useAbility is only able to be used every 3 turns.
	if (getCoolDown() == 0) {
		setCoolDown(3);
	}
	double damage = damageGiven(target);
	std::cout << "\n" << getName() << " used special ability, Channeling Arcane Brilliance: Unleash the Power of the Elements!!!!\n";
	std::cout << "Embrace your pain " << target.getName() << ", as I siphon life with each spell!\n\n";
	// Mages special ability also adds health
	setHealth(getHealth() + damage);
	std::cout << getName() << " heals by " << damage << ".\n";
	std::cout << target.getName() << " was damaged by " << damage << "!\n\n";
	target.setHealth(target.getHealth() - damage);
}

// Method to display mage stats. 
void Mage::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
	std::cout << getName() << " Combat Level: " << getCombatLevel() << std::endl;
	std::cout << getName() << " Total Experience: " << getExperience() << std::endl << std::endl;
}