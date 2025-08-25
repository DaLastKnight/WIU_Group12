#include <iostream>
#include "Campfire.h"

Campfire::Campfire()
{

}

Campfire::~Campfire()
{

}

void Campfire::spawnCampFire()
{
	setTileSymbol('C');
	setTilePosition(10, 10, 5, 5);
}

void Campfire::useCampFire(int& maxPlayerHealth, int& playerHealth)
{
	playerHealth += (maxPlayerHealth / 2);
}