#include <iostream>
#include "Player.h"

#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <cstdlib>
#include <random>

#include "Equipments.h"
#include "Weapons.h"
#include "Armor.h"
#include "Sword.h"
#include "Bow.h"
#include "Dagger.h"
#include "LightArmor.h"
#include "HeavyArmor.h"


Player::Player()
{
	specialty = nullptr;
	equippedWeaponPtr = nullptr;
	equippedArmorPtr = nullptr;

	input = '-';
}

void Player::viewCurrentStats()
{
	std::cout << "Health: " << getHealth() << "\n";
	std::cout << "Attack: " << getAttack() << "\n";
	std::cout << "Defense: " << getDefense() << "\n";
	std::cout << "Speed: " << getSpeed() << "\n";
}

void Player::setClassStats(PlayerClass* playerclass)
{
	specialty = playerclass;
	playerclass->setClassStats(*this);
}

void Player::useSkill(Entity* target)
{
	int dmg = this->getAttack() + specialty->bonusMultiplier();
	if (specialty->bonusMultiplier() == 15) {
		this->setStats(getHealth() + specialty->bonusMultiplier(), target->getAttack(), target->getDefense(), target->getSpeed());
	}
	else {
		target->setStats(target->getHealth() - dmg, target->getAttack(), target->getDefense(), target->getSpeed());
	}

}

void Player::equipEquipment(Equipments* equipmentPtr)
{
	if (equipmentPtr != nullptr)
	{
		if (equipmentPtr->getType() == "WEAPON")
		{
			if (equipmentPtr->getName() == "Sword")
			{
				equippedWeaponPtr = new Sword(equipmentPtr->getTier());
			}
			else if (equipmentPtr->getName() == "Dagger")
			{
				equippedWeaponPtr = new Dagger(equipmentPtr->getTier());
			}
			else if (equipmentPtr->getName() == "Bow")
			{
				equippedWeaponPtr = new Bow(equipmentPtr->getTier());
			}
		}
		else if (equipmentPtr->getType() == "ARMOR")
		{
			if (equipmentPtr->getName() == "LightArmor")
			{
				equippedArmorPtr = new LightArmor(equipmentPtr->getTier());
			}
			else if (equipmentPtr->getName() == "HeavyArmor")
			{
				equippedArmorPtr = new HeavyArmor(equipmentPtr->getTier());
			}
		}
	}
}

void Player::unequipEquipment(Equipments* equipmentPtr)
{
	if (equipmentPtr != nullptr)
	{
		if (equipmentPtr->getType() == "WEAPON")
		{
			if (equippedWeaponPtr != nullptr)
			{
				delete equippedWeaponPtr;
				equippedArmorPtr = nullptr;
			}
		}
		else if (equipmentPtr->getType() == "ARMOR")
		{
			if (equippedArmorPtr != nullptr)
			{
				delete equippedArmorPtr;
				equippedArmorPtr = nullptr;
			}
		}
	}
}

void Player::attacking(Entity* target)
{
	target->setStats(target->getHealth() - this->getFinalAttack(), target->getAttack(), target->getDefense(), target->getSpeed());
}

void Player::defending(Entity* target)
{
	int randomNumber = 0;
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distr(1, 100);

	randomNumber = distr(generator);

	if (randomNumber <= 50) {
		std::cout << "You dodged\n";
	}
	else {
		this->setStats(this->getFinalHealth() - target->getAttack(), this->getFinalAttack(), this->getFinalDefense(), this->getFinalSpeed());
	}
}

int Player::getFinalHealth() const
{
	return (getHealth() + (equippedArmorPtr ? equippedArmorPtr->getHealth() : 0));
}

int Player::getFinalAttack() const
{
	return (getAttack() + (equippedWeaponPtr ? equippedWeaponPtr->getBaseAttack() : 0));
}

int Player::getFinalDefense() const
{
	return (getDefense() + (equippedArmorPtr ? equippedArmorPtr->getDefense() : 0));
}

int Player::getFinalSpeed() const
{
	return (getSpeed() + (equippedArmorPtr ? equippedArmorPtr->getSpeed() : 0));
}

void Player::bonusVal(int amount)
{
	bonusValue += amount;
}

void Player::resetVal()
{
	bonusValue = 0;
}