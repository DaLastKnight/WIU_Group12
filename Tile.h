#pragma once
#include "Position.h"
class Tile
{
protected:
	char tileSymbol;
	Position tilePosition;

public:
	Tile();
	Tile(char symbol);
	~Tile();

	char getTileSymbol() const;
	int getTileRow() const;
	int getTileColumn() const;
	void setTileSymbol(char newSymbol);
	void setTilePosition(int maxGridWidth, int maxGridHeight, int tileRow, int tileColumn);
	void tileInteraction();
};

