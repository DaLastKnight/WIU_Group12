#pragma once
#include "Entity.h"
#include "PlayerClass.h"
#include "Weapons.h"
#include "Armor.h"

class Player : public Entity
{
private:
	PlayerClass* specialty;
	Weapons* equippedWeaponPtr;
	Armor* equippedArmorPtr;

	char input;

	bool confirmSelection();
public:
	Player();
	// Player(int row, int col) : Entity(row, col, 'P', health, attack, defense, speed) {}

	void viewCurrentStats();
	void setClassStats(PlayerClass* playerclass);
	void useSkill(PlayerClass* playerskill);
	void equipEquipment(Equipments* equipmentPtr);
	void unequipEquipment(Equipments* equipmentPtr);

	void attacking() override;
	//void defending();
};

