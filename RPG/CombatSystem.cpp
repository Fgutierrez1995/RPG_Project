#include "CombatSystem.h"

// Constructor
CombatSystem::CombatSystem(std::shared_ptr<Character> player, std::shared_ptr<Enemy> enemy) : player_(player), enemy_(enemy) {}

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

// Method for the enemy's turn during battle.
void CombatSystem::enemyTurn() {
    std::cout << "\n" << enemy_->getName() << " Health is: " << enemy_->getHealth() << std::endl;
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
        randomNum = Character::getRandomNumber(1, 100);

        // If the enemy's attack power is greater than the player's health, use the special ability.
        if (enemyAttackPower > playerHealth) {
            enemy_->useAbility(*player_);
        }
        // 70% chance the enemy will choose to attack instead of using its special ability.
        if (randomNum < 70) {
            enemy_->attack(*player_);
        }
        else {
            enemy_->useAbility(*player_);
        }
    }
    // If the enemy is on cooldown, decide whether to attack or heal.
    else {
        enemy_->attack(*player_);
    }

    // Decrease the enemy's cooldown if it is greater than 0.
    if (enemy_->getCoolDown() > 0) {
        enemy_->setCoolDown(enemy_->getCoolDown() - 1);
    }
}

// Method to prompt the player to pick a combat choice (e.g. Attack, UseAbility, Heal).
void CombatSystem::playerTurn() {
    std::cout << "\n" << player_->getName() << " Health is: " << player_->getHealth() << std::endl;
    std::cout << player_->getCoolDown() << " cooldown.\n";

    int choice;                     // Used for user input
    bool validChoice = false;       // Flag to break the while loop.

    while (!validChoice) {
        // If player cooldown is 0, the player has a special ability available.
        if (player_->getCoolDown() == 0) {
            std::cout << "\nYour turn:\n";
            std::cout << "1. Attack\n" << "2. Use Special Ability\n" << "3. Access Inventory\n";
            choice = safeInputInt();    // Use safeInputInt() to get user input

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
                accessInventory();
                // If player chooses to heal then validChoice is true.
                if (playerHealed_) {
                    validChoice = true;
                }
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
            }
        }
        else {
            // If player is on cooldown.
            std::cout << "\nYour turn:\n";
            std::cout << "1. Attack\n" << "2. Access Inventory\n";
            choice = safeInputInt();    // Use safeInputInt() to get user input

            switch (choice) {
            case 1:
                player_->attack(*enemy_);
                validChoice = true;
                break;
            case 2:
                accessInventory();
                // If player chooses to heal then validChoice is true.
                if (playerHealed_) {
                    validChoice = true;
                }
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
    // Reset playerHealed_ to false after player turn.
    playerHealed_ = false;
}

// Method to access to access the Inventory and ask the player what they would like to do inside the inventory.
void CombatSystem::accessInventory() {
    bool hasConsumableItems = player_->hasConsumableItems();
    int choice = 0;
    bool validChoice = false;

    while (!validChoice) {
        std::cout << "\nSelect 1 of the following options.\n";
        // If player has consumable items
        if (hasConsumableItems) {
            std::cout << "1. Heal.\n";
        }
        std::cout << "2. Equip Item.\n";
        std::cout << "3. Unequip Item.\n";
        
        choice = safeInputInt(); // Use safeInputInt() to get user input

        switch (choice) {
        case 1:
            // If player has consumable items
            if (hasConsumableItems) {
                // Player heal option.
                player_->heal();
                // Player choose to heal and this function says the playerHealed_ to true.
                playerHealed();
                validChoice = true;
            }
            // If player does not have any consumable items.
            else {
                std::cout << "Invalid choice. Try again.\n";
            }

            break;
        case 2:
            // Player equip item option.
            player_->equipItem();
            validChoice = true;
            break;
        case 3:
            // Player unequip item option.
            player_->unequippedItem();
            validChoice = true;
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }
}

// Method sets the playerHealed_ to true if the player chooses to heal.
void CombatSystem::playerHealed() {
    playerHealed_ = true;
}

int CombatSystem::safeInputInt() {
    int input;
    std::cin >> input;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return input;
}

