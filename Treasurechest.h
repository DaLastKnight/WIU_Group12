#pragma once
#include "Tile.h"

class Treasurechest : public Tile
{

protected:
	int Gold;
	int Reward;

public:
	Treasurechest();
	~Treasurechest();
	void spawnTreasureChest();
	void openTreasureChest();
	int getReward();

};