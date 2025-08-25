#pragma once
#include <iostream>
#include "Tile.h"

class Campfire : public Tile
{
protected:

public:
	Campfire();
	~Campfire();
	void spawnCampFire();
	void useCampFire(int& maxPlayerHealth, int& playerHealth);

};