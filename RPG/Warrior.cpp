#include "Warrior.h"

Warrior::Warrior(int health, int attackPower, int defense, int combatLevel) :
	Character(health, attackPower, defense, combatLevel), warriorExperience_(0), experienceRecieved_(combatLevel * 50) {}


void Warrior::attack(Character& target) {

}
void Warrior::defend(int incomingDage) {
}
void Warrior::useAbility(Character& target) {

}
void Warrior::heal(int amount) {
}

void Warrior::levelUp() {
}

void Warrior::displayInfo() const {
	std::cout << "Warrior Health: " << Character::getHealth() << std::endl;
	std::cout << "Warrior Attack Power: " << Character::getAttackPower() << std::endl;
	std::cout << "Warrior Defense Level: " << Character::getDefenseLevel() << std::endl;
	std::cout << "Warrior Combat Level: " << Character::getCombatLevel() << std::endl;
	std::cout << "Warrior Total Experience: " << warriorExperience_ << std::endl;
	std::cout << "Experience Given If Slain: " << experienceRecieved_ << std::endl;
}