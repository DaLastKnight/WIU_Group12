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
	int bonusValue;

public:
	Player();

	void viewCurrentStats();
	void setClassStats(PlayerClass* playerclass);
	void useSkill(Entity* target);
	void equipEquipment(Equipments* equipmentPtr);
	void unequipEquipment(Equipments* equipmentPtr);

	void attacking(Entity* target) override;
	void defending(Entity* target) override;

	int getFinalHealth() const;
	int getFinalAttack() const;
	int getFinalDefense() const;
	int getFinalSpeed() const;

	void bonusVal(int amount);
	void resetVal();
};

