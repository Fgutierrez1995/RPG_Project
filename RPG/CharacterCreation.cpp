#include "CharacterCreation.h"

// Methods ask user to choose what character class they would like to create.
std::unique_ptr<Character> CharacterCreation::createCharacter() {
	bool characterChoosen = false; // Flag to break the do-while loop.
	std::unique_ptr<Character> character; // unique_ptr object that will be returned.
	do {
		int choice;
		std::cout << "Choose a classs: \n";
		std::cout << "1. Warrior\n";
		std::cout << "2. Mage\n";
		std::cout << "3. Rogue\n";
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character
		if (choice == 1 || choice == 2 || choice == 3) {
			switch (choice) {
			case 1:
				character = createWarrior();	// Create Warrior object
				characterChoosen = true;		// Break loop
				break;
			case 2:
				character = createMage();		// Create Mage Object
				characterChoosen = true;		// Break loop
				break;
			case 3:
				character = createRogue();		// Create Rogue Object.
				characterChoosen = true;		// Break loop
				break;
			}
		}
		else {
			std::cout << "Invalid choice.. try again.\n";
		}
	} while (!characterChoosen);

	return character;
}

// Method that returns a Warrior object.
std::unique_ptr<Warrior> CharacterCreation::createWarrior() {
	std::string name;
	std::cout << "What name do you choose for your warrior?" << std::endl;
	std::getline(std::cin, name);
	return std::make_unique<Warrior>(15, 5, name);
}

// Method that returns a Mage object.
std::unique_ptr<Mage> CharacterCreation::createMage() {
	std::string name;
	std::cout << "What name do you choose for your mage?" << std::endl;
	std::getline(std::cin, name);
	return std::make_unique<Mage>(20, 1, name);
}

// Method that returns a Rogue object.
std::unique_ptr<Rogue> CharacterCreation::createRogue() {
	std::string name;
	std::cout << "What name do you choose for your rogue?" << std::endl;
	std::getline(std::cin, name);
	return std::make_unique<Rogue>(18, 2, name);
}