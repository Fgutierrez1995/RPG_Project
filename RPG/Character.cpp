#include "Character.h"

// Constructor
Character::Character(int attackPower, int defense, const std::string& name) : attackPower_(attackPower), defense_(defense), name_(name) {}

// Setter Methods
void Character::setAttackPower(int attackPower) { attackPower_ = attackPower; }
void Character::setDefenseLevel(int defense) { defense_ = defense; }
void Character::setHealth(int health) { health_ = health; }
void Character::setCombatLevel(int combatLevel) { combatLevel_ = combatLevel; }
void Character::setExperience(int experience) { totalExperience_ = experience; }
void Character::setName(const std::string& name) { name_ = name; }

// Getter Methods
int Character::getAttackPower() const { return attackPower_; }
int Character::getDefenseLevel() const { return defense_; }
int Character::getHealth() const { return health_; }
int Character::getCombatLevel() const { return combatLevel_; }
int Character::getExperience() const { return totalExperience_; }
std::string Character::getName() const { return name_; }
