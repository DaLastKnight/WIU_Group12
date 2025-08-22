#pragma once
#include <string>

class Gold;

class Shop
{

private:
	Gold* goldPtr;
	// Weapon* weaponPtr[3];
	// Armor* armorPtr[3];
	// Potion* potionPtr[3];
	// Charm* charmPtr[3];
	
	void showChoices(const std::string& itemType);
	void handlePurchase(const std::string& itemType);

public:
	Shop(Gold* goldPtr);
	~Shop();

	void interactShop();

};

