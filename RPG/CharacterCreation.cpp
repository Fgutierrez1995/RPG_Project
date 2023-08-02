#include "CharacterCreation.h"

// Method to display character choices.
void CharacterCreation::displayCharactersChoices() {
	std::cout << "Choose a class:\n";
	std::cout << "1. Warrior\n";
	std::cout << "2. Mage\n";
	std::cout << "3. Rogue\n";
}

// Methods ask user to choose what character class they would like to create.
std::shared_ptr<Character> CharacterCreation::createCharacter() {
	std::map<int, std::function<std::shared_ptr<Character>()>> characterCreators = {
		{1, createWarrior},
		{2, createMage},
		{3, createRogue}
	};

	std::shared_ptr<Character> character; // character object returned
	bool characterChosen = false;	// Bool value to break the loop

	do {
		displayCharactersChoices();
		int choice;
		std::cin >> choice;

		// If the user enters anything but a integer. 
		if (std::cin.fail() || characterCreators.find(choice) == characterCreators.end()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	 // Ignore newline character
			std::cout << "Invalid choice.. try again.\n";
		}
		else {
			character = characterCreators[choice]();	// Call the appropriate create function
			characterChosen = true;
		}
	} while (!characterChosen);

	return character;

}

// Method that returns a Warrior object.
std::shared_ptr<Warrior> CharacterCreation::createWarrior() {
	std::string name;
	std::cout << "What name do you choose for your warrior?" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	 // Ignore newline character
	std::getline(std::cin, name);
	double health = (15 + 5) * 2.5;
	return std::make_shared<Warrior>(15, 5, health, name);
}

// Method that returns a Mage object.
std::shared_ptr<Mage> CharacterCreation::createMage() {
	std::string name;
	std::cout << "What name do you choose for your mage?" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	 // Ignore newline character
	std::getline(std::cin, name);
	double health = (20 + 1) * 2;
	return std::make_shared<Mage>(20, 1, health, name);
}

// Method that returns a Rogue object.
std::shared_ptr<Rogue> CharacterCreation::createRogue() {
	std::string name;
	std::cout << "What name do you choose for your rogue?" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	 // Ignore newline character
	std::getline(std::cin, name);
	double health = (18 + 2) * 2;
	return std::make_shared<Rogue>(18, 2, health, name);
}