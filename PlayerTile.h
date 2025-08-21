#pragma once
#include "Tile.h"
class PlayerTile : public Tile
{
private:
	bool isPlayerMoved;
public:
	PlayerTile();
	~PlayerTile();
	void move(int maxGridWidth, int maxGridHeight);
};

