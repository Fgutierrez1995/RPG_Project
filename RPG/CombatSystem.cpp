#include "CombatSystem.h"

// Constructor
CombatSystem::CombatSystem(std::shared_ptr<Character> player, std::shared_ptr<Character> enemy) : player_(player), enemy_(enemy) {}

// Method to determine if the battle is over.
bool CombatSystem::battleOver() {
    return (player_->getHealth() <= 0 || enemy_->getHealth() <= 0);
}

// Method to start the battle
void CombatSystem::startBattle() {
    // Display information about the player and enemy before the battle starts.
    player_->displayInfo();
    enemy_->displayInfo();

    std::cout << "Battle started!\n";

    // Loop runs while both player and enemy are alive.
    while (!battleOver()) {
        playerTurn();
        if (enemy_->isAlive()) {
            enemyTurn();
        }
    }

    // Determine the winner and perform the appropriate actions.
    if (player_->isAlive()) {
        // Reset player's health to full after the battle.
        player_->setHealth(player_->getMaxHealth());

        // Reset player's cool down to zero after the battle.
        player_->setCoolDown(0);

        // Add experience points to the player for defeating the enemy.
        player_->setExperience(player_->getExperience() + 250);

        // Check if the player should level up based on their experience points.
        player_->levelUp();

        std::cout << "Congratulations! You won the battle!\n";
    }
    else {
        std::cout << "You were defeated by " << enemy_->getName() << "...\n";
    }
}



// Method to prompt the player to pick a combat choice (e.g. Attack, UseAbility, Heal).
void CombatSystem::playerTurn() {
    std::cout << player_->getName() << " Health is: " << player_->getHealth() << std::endl;
    std::cout << player_->getCoolDown() << " cooldown.\n";

    int choice;                     // Used for user input
    bool validChoice = false;       // Flag to break the while loop.

    while (!validChoice) {
        // If player cooldown is 0, the player has a special ability available.
        if (player_->getCoolDown() == 0) {
            std::cout << "Your turn:\n";
            std::cout << "1. Attack\n" << "2. Use Special Ability\n" << "3. Heal\n";
            std::cin >> choice;

            // Handle the error if the user enters anything other than an integer.
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         // Ignore newline character
            }

            switch (choice) {
            case 1:
                player_->attack(*enemy_);
                validChoice = true;
                break;
            case 2:
                player_->useAbility(*enemy_);
                validChoice = true;
                break;
            case 3:
                player_->heal();
                validChoice = true;
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
            }
        }
        else {
            // If player is on cooldown.
            std::cout << "Your turn:\n";
            std::cout << "1. Attack\n" << "2. Heal\n";
            std::cin >> choice;

            // Handle the error if the user enters anything other than an integer.
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         // Ignore newline character
            }

            switch (choice) {
            case 1:
                player_->attack(*enemy_);
                validChoice = true;
                break;
            case 2:
                player_->heal();
                validChoice = true;
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
            }
        }
    }

    // Decrement the player's cooldown if it's greater than 0.
    if (player_->getCoolDown() > 0) {
        player_->setCoolDown(player_->getCoolDown() - 1);
    }
}


// Method for the enemy's turn during battle.
void CombatSystem::enemyTurn() {
    std::cout << enemy_->getName() << " Health is: " << enemy_->getHealth() << std::endl;
    std::cout << enemy_->getCoolDown() << " cooldown.\n";

    // Variable to be used for generating random numbers.
    int randomNum = 0;

    // Gather relevant information about the enemy and player.
    double enemyHealth = enemy_->getHealth();
    double enemyAttackPower = enemy_->getAttackPower();
    int enemyCoolDown = enemy_->getCoolDown();
    double playerHealth = player_->getHealth();
    double playerAttackPower = player_->getAttackPower();

    // Implement decision-making logic for the enemy's action.
    if (enemyCoolDown == 0) {
        // Heal the enemy if its health is lower than the player's attack power and its attack power is less than the player's health.
        if (enemyHealth < playerAttackPower && enemyAttackPower < playerHealth) {
            enemy_->heal();
        }
        else {
            // Decide whether to attack or use the special ability.
            randomNum = Character::getRandomNumber(1, 100);
            // If the enemy's attack power is greater than the player's health, use the special ability.
            if (enemyAttackPower > playerHealth) {
                enemy_->useAbility(*player_);
            }
            // 70% chance the enemy will choose to attack instead of using its special ability.
            else if (randomNum < 70) {
                enemy_->attack(*player_);
            }
            else {
                enemy_->useAbility(*player_);
            }
        }
    }
    // If the enemy is on cooldown, decide whether to attack or heal.
    else {
        // If the player's health is less than the enemy's attack power.
        if (playerHealth < enemyAttackPower) {
            randomNum = Character::getRandomNumber(1, 100); // Get a random number between 1 - 100.
            // 60% chance the enemy will attack.
            if (randomNum < 60) {
                enemy_->attack(*player_);
            }
            else {
                enemy_->heal();
            }
        }
        // If the enemy's health is less than half of the player's attack power, then heal.
        else if (enemyHealth < (playerAttackPower / 2)) {
            enemy_->heal();
        }
        // If the enemy is not in immediate danger of dying, choose to either attack or heal.
        else {
            randomNum = Character::getRandomNumber(1, 100);
            // 60% chance the enemy will attack.
            if (randomNum < 60) {
                enemy_->attack(*player_);
            }
            else {
                enemy_->heal();
            }
        }
    }

    // Decrease the enemy's cooldown if it is greater than 0.
    if (enemy_->getCoolDown() > 0) {
        enemy_->setCoolDown(enemy_->getCoolDown() - 1);
    }
}

