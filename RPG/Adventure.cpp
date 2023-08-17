#include "Adventure.h"

// Constructor
Adventure::Adventure(const std::shared_ptr<Character>& player) : player_(player) {}

void Adventure::startAdventure() {
	introduction();

	if (player_->isDead()) {
		std::cout << "\nGame Over: You have been defeated.\n";
		return;
	}

	firstPlayerSelection();

	if (player_->isDead()) {
		std::cout << "\nGame Over: You have been defeated.\n";
		return;
	}

	secondPlayerSelection();

	if (player_->isDead()) {
		std::cout << "\nGame Over: You have been defeated.\n";
		return;
	}

	thirdPlayerSelection();

	if (player_->isDead()) {
		std::cout << "\nGame Over: You have been defeated.\n";
		return;
	}

	conclusion();
}

void Adventure::introduction() {
	std::cout << "The adventure begins in a small village called Everwood.\n";
	std::cout << "The villagers have been living peacefully for generations, but lately, a series of mysterious events have been occurring.\n";
	std::cout << "Crops have withered, livestock has gone missing, and a sense of unease fills the air.\n";
	std::cout << "A village elder, a wise and respected figure, approaches you.\n";
	std::cout << "Silas: \n";
	std::cout << "Hello travler, my name is Silas and our village is needing help.\n";
	std::cout << "The village has had possesion of a poweful relic, known as the 'Heart of Elaria'.\n";
	std::cout << "The relic was stolen from the village shrine.\n";
	std::cout << "The relic has been safeguarding the village from harm for centuries, and its theft has brought the current troubles.\n";
	std::cout << "I believe the relic was stolen by a group of goblins who have been spotted in the nearby Whispering Woods.\n";
	std::cout << "Go " << player_->getName() << " speak with the nearby villagers and explore the woods to uncover the goblins' hideout.\n\n";
}

void Adventure::firstPlayerSelection() {
	bool validChoice = false;
	int choice = 0;
	while (!validChoice) {
		std::cout << "Enter 1. Speak with nearby villagers.\n";
		std::cout << "Enter 2. Explore the woods\n";
		choice = safeInputInt();

		switch (choice) {
		case 1:
			speakWithVillagers();
			validChoice = true;
			break;
		case 2:
			std::cout << "You heard towards the woods.\n";
			validChoice = true;
			break;
		default:
			std::cout << "Invalid choice. Try again..\n";
			break;
		}
	}
}

void Adventure::secondPlayerSelection() {
	exploreWoods();
}

void Adventure::thirdPlayerSelection() {
	goblinsCamp();
}

void Adventure::speakWithVillagers() {
	int choice = 0;
	bool validChoice = false;
	std::cout << "\nYou see a black smith and a farmer near by.\n";
	while (!validChoice) {
		std::cout << "\nEnter 1. To speak with the black smith.\n";
		std::cout << "Enter 2. To speak with the farmer.\n";
		choice = safeInputInt();

		switch (choice) {
		case 1:
			std::cout << "\nYou ask the black smith if he has seen where the group of goblins ran off to.\n";
			std::cout << "Black Smith: \n";
			std::cout << "When the goblins came and raided our village they went 'North' into the forest.\n";
			std::cout << "God bless you " << player_->getName() << " for helping our small village.\n";
			std::cout << "Please take this gear to help you on your adventure.\n";
			grantPlayerEquipmentBasedOnClass("Warrior", "bronze sword", "bronze armour", 5.0);
			grantPlayerEquipmentBasedOnClass("Mage", "beginner wand", "magic robes", 5.0);
			grantPlayerEquipmentBasedOnClass("Rogue", "bronze dagger", "bronze chain mail", 5.0);
			validChoice = true;
			break;
		case 2:
			std::cout << "You ask the farmer if he has seen where the group of goblins ran off to.\n";
			std::cout << "Farmer: \n";
			std::cout << "When the goblins came and raided our village they went 'North' into the forest.\n";
			std::cout << "God bless you " << player_->getName() << " for helping our small village.\n";
			std::cout << "Please take food to help you in your adventure.\n";
			grantPlayerConsumableItems("bread", "Excellent baked bread.", 3);

			validChoice = true;
			break;
		}
	}
}


void Adventure::exploreWoods() {
	int choice = 0;
	bool validChoice = false;
	std::cout << "\nYou have entered the woods and see a sign pointing North, East, and West.\n";
	while (!validChoice) {
		std::cout << "\nEnter the number for the following options.\n";
		std::cout << "Option 1. North.\n";
		std::cout << "Option 2. East.\n";
		std::cout << "Option 3. West.\n";
		choice = safeInputInt();

		switch(choice) {
		case 1:
			std::cout << "You adventure north.\n";
			validChoice = true;
			break;
		case 2: {
			std::cout << "\nOh no! You incountered a goblin!!\n\n";
			auto goblin = Goblin::makeGoblin(15, 0, 20, "Goblin");
			CombatSystem combat(player_, goblin);
			combat.startBattle();
			if (player_->isAlive()) {
				std::cout << "\nAfter defeating the goblin. You spare the goblins life if he told you where their camp is located.\n";
				std::cout << "\nGoblin: \n";
				std::cout << "Our camp is north, please let me go!\n\n";
				std::cout << "You let the goblin go and head north.\n";
			}
			else {
				std::cout << "Oh dear... you are dead.\n";
			}
			validChoice = true;
			break;
		}
		case 3: 
			std::cout << "\nOh no! You fell down a trap!\n";
			std::cout << player_->getName() << " was damaged 15!\n";
			player_->setHealth(player_->getHealth() - 15);
			std::cout << "You manage to climb out and head north.\n";
			validChoice = true;
			break;

		}
	}

}

void Adventure::goblinsCamp() {
	int choice = 0;
	bool validChoice = false;
	auto success = Character::getRandomNumber(0, 100);
	std::cout << "\nYou found the goblins camp!\n";
	std::cout << "You see there is 3 golbins and 1 orc. It looks like the orc is the leader.\n";
	std::cout << "You see the realic!\n\n";
	while (!validChoice) {
		std::cout << "Enter the number for the following options.\n";
		std::cout << "Option 1: I'm not afraid of them! I'll fight them head on!\n";
		std::cout << "Option 2: I'll try to a stealth attack and take one them out.\n";
		std::cout << "Option 3: I'm going to try and grab the Realic without the camp noticing.\n\n";
		choice = safeInputInt();

		switch (choice) {
		case 1: 
			battleGoblinsAndOrc(
				{ 
					Goblin::makeGoblin(5, 0, 20, "Goblin"),
					Goblin::makeGoblin(5, 0, 20, "Goblin"),
					Goblin::makeGoblin(5, 0, 20, "Goblin") 
				}, 
				Orc::makeOrc(25, 5, 30, "Orc"));
			validChoice = true;
			break;

		case 2: 
			std::cout << "You managed to take one out but now you have alerted the rest of the camp!\n";
			battleGoblinsAndOrc(
				{
					Goblin::makeGoblin(5, 0, 20, "Goblin"),
					Goblin::makeGoblin(5, 0, 20, "Goblin")
				},
				Orc::makeOrc(25, 5, 30, "Orc"));
			validChoice = true;
			break;

		case 3:
			if (success <= 25) {
				std::cout << "\nYou quickly grab the realic and head back to the village without the camp noticing.\n";
			}
			else {
				std::cout << "\nYou trip and alerted the camp!!\n";
				battleGoblinsAndOrc(
					{
						Goblin::makeGoblin(5, 0, 20, "Goblin"),
						Goblin::makeGoblin(5, 0, 20, "Goblin"),
						Goblin::makeGoblin(5, 0, 20, "Goblin")
					},
					Orc::makeOrc(25, 5, 30, "Orc"));
			}
			validChoice = true;
			break;
		default:
			std::cout << "Invalid option.. Try again.\n";
		}
	}
	
}

void Adventure::battleGoblinsAndOrc(const std::vector<std::shared_ptr<Goblin>>& goblins, std::shared_ptr<Orc> orc) {
	for (const auto& goblin : goblins) {
		if (player_->isDead()) {
			std::cout << "Oh dear... you are dead.\n";
			return;
		}
		CombatSystem combat(player_, goblin);
		combat.startBattle();
	}

	if (player_->isDead()) {
		std::cout << "Oh dear... you are dead.\n";
		return;
	}

	std::cout << "\nOrc:\n";
	std::cout << "You might have defeated my goblins but you will not defeat me!\n\n";

	CombatSystem combat(player_, orc);
	combat.startBattle();

	if (player_->isDead()) {
		std::cout << "Oh dear... you are dead.\n";
		return;
	}

	std::cout << "You have defeated the Orc leader!\n";
	std::cout << "\nYou quickly grab the relic and head back to the village.\n";
}

void Adventure::grantPlayerEquipmentBasedOnClass(const std::string& playerClass, const std::string& weaponName, const std::string& armourName, double power) {
	if (player_->getClassType() == playerClass) {
		std::cout << "\nYou received a " << weaponName << " and " << armourName << "!\n";
		player_->addItem(std::move(WeaponItem::makeWeapon(weaponName, "An excellent " + weaponName + ".", power)));
		player_->addItem(std::move(ArmourItem::makeArmour(armourName, "An excellent " + armourName + ".", power)));
	}
}

void Adventure::grantPlayerConsumableItems(const std::string& itemName, const std::string& description, int count) {
	std::cout << "\nYou received " << count << " " << itemName << "!\n";
	for (int i = 0; i < count; ++i) {
		player_->addItem(std::move(ConsumableItem::makeConsumable(itemName, description, 5.0)));
	}
}

void Adventure::conclusion() {
	std::cout << "\nYou have returned to the village and go to speak with Silas.\n";
	std::cout << "Silas:\n";
	std::cout << "You have returned with the relic " << player_->getName() << "!\n";
	std::cout << "You you have this villages up most graditude!\n";
	std::cout << "Please take this as a reward.\n";
	grantPlayerEquipmentBasedOnClass("Warrior", "Iron long sword", "Iron armour", 10.00);
	grantPlayerEquipmentBasedOnClass("Mage", "Battle staff", "Mystic robes", 10.00);
	grantPlayerEquipmentBasedOnClass("Rogue", "Iron dagger", "Iron chain mail", 10.00);
	player_->setExperience(player_->getExperience() + 1000);
	player_->levelUp();
}

int Adventure::safeInputInt() {
	int input;
	std::cin >> input;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return input;
}