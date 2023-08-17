#include <iostream>
#include "Adventure.h"


int main() {

	auto character = CharacterCreation::createCharacter();

	Adventure adventure(character);

	adventure.startAdventure();

	return 0;
}