#include "Character.h"

// Constructor
Character::Character(double attackPower, double defense, double health, const std::string& name) : attackPower_(attackPower), defense_(defense), health_(health), name_(name) {}

// Setter Methods
void Character::setAttackPower(double attackPower) { attackPower_ = attackPower; }
void Character::setDefenseLevel(double defense) { defense_ = defense; }
void Character::setHealth(double health) { health_ = health; }
void Character::setCombatLevel(int combatLevel) { combatLevel_ = combatLevel; }
void Character::setExperience(int experience) { totalExperience_ = experience; }
void Character::setName(const std::string& name) { name_ = name; }
void Character::setMaxHealth(double maxHealth) { maxHealth_ = maxHealth; }

// Getter Methods
double Character::getAttackPower() const { return attackPower_; }
double Character::getDefenseLevel() const { return defense_; }
double Character::getHealth() const { return health_; }
int Character::getCombatLevel() const { return combatLevel_; }
int Character::getExperience() const { return totalExperience_; }
std::string Character::getName() const { return name_; }
double Character::getMaxHealth() const { return maxHealth_; }

// Method to return a random number between min and max.
int Character::getRandomNumber(int min, int max) {
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(min, max);
	return distr(eng);
}
