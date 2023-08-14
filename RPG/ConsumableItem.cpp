#include "ConsumableItem.h"

ConsumableItem::ConsumableItem(const std::string& name, const std::string& description, double healAmount) :
	Item(name, description, ItemType::Consumable), healAmount_(healAmount) {}

std::unique_ptr<ConsumableItem> ConsumableItem::makeConsumable(const std::string& name, const std::string& description, double healAmount) {
	return std::make_unique<ConsumableItem>(name, description, healAmount);
}

void ConsumableItem::use(Character& character) {
	std::cout << "\n" << character.getName() << " healed by " << getHealAmount() << std::endl;
	character.setHealth(character.getHealth() + getHealAmount());
}

void ConsumableItem::displayStats() {
	std::cout << "Consumable Name: " << getName() << std::endl;
	std::cout << "Consumable Description: " << getDescription() << std::endl;
	std::cout << "Consumable Type: " << static_cast<int>(getType()) << std::endl;
	std::cout << "Consumable Heal Amount: " << getHealAmount() << std::endl << std::endl;
}

void ConsumableItem::equip(Character& character) {}

void ConsumableItem::unEquip(Character& character) {}

double ConsumableItem::getHealAmount() const { return healAmount_; }

void ConsumableItem::setHealAmount(double healAmount) { healAmount_ = healAmount; }
