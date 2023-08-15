#include "DarkMage.h"

// Constructor
DarkMage::DarkMage(double attackPower, double defense, double health, const std::string& name) : Enemy(attackPower, defense, health, name) {}

// Method to simulate dark mage attacking with is special Ability at a character Target.
void DarkMage::useAbility(Character& target) {
	// useAbility is only able to be used every 3 turns.
	if (getCoolDown() == 0) {
		setCoolDown(3);
	}
	double damage = damageGiven(target);
	std::cout << "\n" << getName() << " used special ability, Embrace the shadows, for they are but extensions of my will! Behold, the darkness unleashed!!!\n";
	// Mages special ability also adds health
	setHealth(getHealth() + damage);
	std::cout << getName() << " heals by " << damage << ".\n";
	std::cout << target.getName() << " was damaged by " << damage << "!\n\n";
	target.setHealth(target.getHealth() - damage);
}

// Method to display dark mage stats. 
void DarkMage::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
}

// Static method to create and return a shared pointer to a dark mage object.
std::shared_ptr<DarkMage> DarkMage::makeDarkMage(double attackPower, double defense, double health, const std::string& name) {
	return std::make_shared<DarkMage>(attackPower, defense, health, name);
}
