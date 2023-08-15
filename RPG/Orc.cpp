#include "Orc.h"

// Constructor
Orc::Orc(double attackPower, double defense, double health, const std::string& name) : Enemy(attackPower, defense, health, name) {}

// Method to simulate orc attacking with is special Ability at a character Target.
void Orc::useAbility(Character& target) {
	// useAbility is only able to be used every 3 turns.
	if (getCoolDown() == 0) {
		setCoolDown(3);
	}
	double damage = damageGiven(target);
	std::cout << "\n" << getName() << " used special ability, By the strength of the Warchief's fury, I bring da storm!!!!\n";
	std::cout << "\n" << target.getName() << " was damaged by " << (damage * 2) << "!\n\n";
	target.setHealth(target.getHealth() - (damage * 2));
}

// Method to display orc stats. 
void Orc::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
}

// Static method to create and return a shared pointer to a Orc object.
std::shared_ptr<Orc> Orc::makeOrc(double attackPower, double defense, double health, const std::string& name) {
	return std::make_shared<Orc>(attackPower, defense, health, name);
}