#include "Character.h"

// Constructor
Character::Character(double attackPower, double defense, const std::string& name) : attackPower_(attackPower), defense_(defense), name_(name) {}

// Setter Methods
void Character::setAttackPower(double attackPower) { attackPower_ = attackPower; }
void Character::setDefenseLevel(double defense) { defense_ = defense; }
void Character::setHealth(double health) { health_ = health; }
void Character::setCombatLevel(int combatLevel) { combatLevel_ = combatLevel; }
void Character::setExperience(int experience) { totalExperience_ = experience; }
void Character::setName(const std::string& name) { name_ = name; }

// Getter Methods
double Character::getAttackPower() const { return attackPower_; }
double Character::getDefenseLevel() const { return defense_; }
double Character::getHealth() const { return health_; }
int Character::getCombatLevel() const { return combatLevel_; }
int Character::getExperience() const { return totalExperience_; }
std::string Character::getName() const { return name_; }

// Method to return a random number between min and max.
int Character::getRandomNumber(int min, int max) {
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(min, max);
	return distr(eng);
}
