#include "Character.h"

// Constructor
Character::Character(int health, int attackPower, int defense) : health_(health), attackPower_(attackPower), defense_(defense) {}

// Setter Methods
void Character::setAttackPower(int attackPower) { attackPower_ = attackPower; }
void Character::setDefenseLevel(int defense) { defense_ = defense; }
void Character::setHealth(int health) { health_ = health; }

// Getter Methods
int Character::getAttackPower() const { return attackPower_; }
int Character::getDefenseLevel() const { return defense_; }
int Character::getHealth() const { return health_; }
