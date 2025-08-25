#include "Treasurechest.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// put srand(static_cast<unsigned int>(time(nullptr))); at start of main.cpp to seed it only once.
Treasurechest::Treasurechest()
{
	Reward = rand() % 250;
}

void Treasurechest::spawnTreasureChest()
{
	setTileSymbol('T');
	setTilePosition(10, 10, 5, 5);
}

void Treasurechest::openTreasureChest()
{
	Gold = 0;
	Gold += Reward;
}

int Treasurechest::getReward()
{
	std::cout << "Treasure chest reward: " << Reward << std::endl;
	return Reward;
}

Treasurechest::~Treasurechest()
{

}