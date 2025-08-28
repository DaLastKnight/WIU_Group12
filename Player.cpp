#include <iostream>
#include "Player.h"

#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <cstdlib>
#include <random>

Player::Player()
{
	specialty = nullptr;
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

void Player::attacking(Entity* target)
{
	target->setStats(target->getHealth() - this->getAttack(), target->getAttack(), target->getDefense(), target->getSpeed());
}

void Player::defending(Entity* target)
{
	int randomNumber = 0;
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distr(1, 100);

	randomNumber = distr(generator);

	if (randomNumber <= 50) {
		std::cout << "You dodge mf\n";
	}
	else {
		this->setStats(this->getHealth() - target->getAttack(), this->getAttack(), this->getDefense(), this->getSpeed());
	}
}

void Player::bonusVal(int amount)
{
	bonusValue += amount;
}

void Player::resetVal()
{
	bonusValue = 0;
}