#pragma once
#include <string>
#include "Weapons.h"
#include "Armor.h"
#include "Potions.h"
#include "Items.h"

class Inventory;
class Gold;

class Shop
{
private:
	Inventory* inventoryPtr;
	Gold* goldPtr;
	Weapons* weaponList[3];
	Armor* armorList[3];
	Potions* potionList[2];
	Items* itemList[2];
	// Armor* armorPtr[3];
	// Potion* potionPtr[3];
	// Charm* charmPtr[3];

	bool isWeaponBought[3];
	bool isArmorBought[3];
	bool isPotionBought[2];
	bool isMiscellaneousItemBought[2];

	void showChoices(const std::string& itemType);
	void handlePurchase(Weapons* weaponPtr, bool& weaponIsBought);
	void handlePurchase(Armor* armorPtr, bool& armorIsBought);
	void handlePurchase(Potions* potionPtr, bool& potionIsBought);
	void handlePurchase(Items* itemPtr, bool& itemIsBought);

public:
	Shop(Inventory* playerInventory, Gold* goldPtr);
	~Shop();

	void interactShop();

};

