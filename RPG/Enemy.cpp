#include "Enemy.h"

// Constructor
Enemy::Enemy(double attackPower, double defense, double health, const std::string& name) :
	attackPower_(attackPower), defense_(defense), health_(health), name_(name) {}

// Setter Methods
void Enemy::setHealth(double health) { health_ = health; }
void Enemy::setAttackPower(double attackPower) { attackPower_ = attackPower; }
void Enemy::setDefenseLevel(double defense) { defense_ = defense; }
void Enemy::setName(const std::string& name) { name_ = name; }
void Enemy::setCoolDown(int coolDown) { coolDown_ = coolDown; }

// Getter Methods
double Enemy::getHealth() const { return health_; }
double Enemy::getAttackPower() const { return attackPower_; }
double Enemy::getDefenseLevel() const { return defense_; }
std::string Enemy::getName() const { return name_; }
int Enemy::getCoolDown() const { return coolDown_; }


// Method thats returns a random number between min and max.
int Enemy::getRandomNumber(int min, int max) {
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(min, max);
	return distr(eng);
}

// Method to determine how hard the enemy hits.
double Enemy::damageGiven(Character& target) {
	// Get a random number between 0 and 100.
	int randomNumber = getRandomNumber(0, 100);
	// Turn the random number into a fraction.
	double potentialDamage = randomNumber / 100.00;
	// Determine the damage.
	double damage = getAttackPower() - ((getAttackPower() - (target.getDefenseLevel() * .5)) * potentialDamage);
	// Return damage.
	return damage;
}

// Method to simulate a character object attacking a character target.
void Enemy::attack(Character& target) {
	double damage = damageGiven(target);
	std::cout << "\n" << getName() << " attacked " << target.getName() << "!\n";
	std::cout << target.getName() << " was damaged by " << damage << "!!\n\n";
	target.setHealth(target.getHealth() - damage);
}

// Method to check if the enemy is dead (health is zero or less).
bool Enemy::isDead() const {
	return health_ <= 0;
}

// Method to check if the enemy is alive (health is greater than zero).
bool Enemy::isAlive() const {
	return health_ > 0;
}

