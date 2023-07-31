#include "Warrior.h"

Warrior::Warrior(int attackPower, int defense, const std::string& name) :
	Character(attackPower, defense, name) {}


void Warrior::attack(Character& target) {
	std::cout << getName() << " attacked " << target.getName() << "!!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower() - (target.getDefenseLevel() * .30)));

	if (target.isDead()) {
		setExperience(getExperience() + 500);
		// Check if Warrior levels up
		levelUp();
	}
}

void Warrior::useAbility(Character& target) {
	std::cout << getName() << " used his special ability!!\n\n";
	target.setHealth(target.getHealth() - (getAttackPower() * 1.5));
	if (target.isDead()) {
		setExperience(getExperience() + 250);
		// Check if Warrior levels up
		levelUp();
	}
}
void Warrior::heal(int amount) {
	std::cout << getName() << " choose to heal himself by " << amount << "!!\n\n";
	setHealth(getHealth() + amount);
}

void Warrior::levelUp() {
	if (getExperience() >= 1000) {
		std::cout << getName() << " leveled up!!\n\n";
		setAttackPower(getAttackPower() + 1);
		setDefenseLevel(getDefenseLevel() + 1);
		setHealth((getAttackPower() + getDefenseLevel()) * 2);
		setCombatLevel((getAttackPower() + getDefenseLevel()) / 2);
		setExperience(0);
	}
}

bool Warrior::isDead() const {
	return getHealth() <= 0;
}

void Warrior::displayInfo() const {
	std::cout << getName() << " Health: " << getHealth() << std::endl;
	std::cout << getName() << " Attack Power: " << getAttackPower() << std::endl;
	std::cout << getName() << " Defense Level: " << getDefenseLevel() << std::endl;
	std::cout << getName() << " Combat Level: " << getCombatLevel() << std::endl;
	std::cout << getName() << " Total Experience: " << getExperience() << std::endl << std::endl;
}