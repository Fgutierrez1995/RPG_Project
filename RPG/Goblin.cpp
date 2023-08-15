#include "Goblin.h"

// Constructor
Goblin::Goblin(double attackPower, double defense, double health, const std::string& name) : Enemy(attackPower, defense, health, name) {}

// Method to simulate goblin attacking with is special Ability at a character Target.
void Goblin::useAbility(Character& target) {
	// useAbility is only able to be used every 3 turns.
	if (getCoolDown() == 0) {
		setCoolDown(3);
	}
	double damage = damageGiven(target);
	std::cout << "\n" << getName() << " used special ability, With cunning and chaos, I weave my goblin power! Watch as mischief turns to power!!!!\n";
	std::cout << target.getName() << " was damaged by " << (damage * 2.5) << "!\n\n";
	target.setHealth(target.getHealth() - (damage * 2.5));
	
	
}

// Method to display dark mage stats. 
void Goblin::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
}

// Static method to create and return a shared pointer to a dark mage object.
std::shared_ptr<Goblin> Goblin::makeGoblin(double attackPower, double defense, double health, const std::string& name) {
	return std::make_shared<Goblin>(attackPower, defense, health, name);
}