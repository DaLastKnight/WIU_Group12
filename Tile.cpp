#include <iostream>
#include "Position.h"
#include "Tile.h"

Tile::Tile()
{
	tileSymbol = 'U'; // Default: U for unknown value
}

Tile::Tile(char symbol)
{
	tileSymbol = symbol;
}

Tile::~Tile()
{

}

void Tile::tileInteraction()
{
	// General gist of this function
	// if (this->tilePos == playerTilePos)
	// {
	//		switch (tileSymbol)
	//		{
	//		case ?:
	//			triggerInteraction();
	//		}
	// }
}

char Tile::getTileSymbol() const
{
	return tileSymbol;
}

int Tile::getTileRow() const
{
	return tilePosition.getRow();
}

int Tile::getTileColumn() const
{
	return tilePosition.getColumn();
}

void Tile::setTileSymbol(char newSymbol)
{
	tileSymbol = newSymbol;
}

void Tile::setTilePosition(int maxGridWidth, int maxGridHeight, int tileRow = 0, int tileColumn = 0)
{
	bool validPosition = ((tileRow < maxGridWidth && tileRow >= 0) && (tileColumn < maxGridHeight && tileColumn >= 0));
	
	if (validPosition)
	{
		tilePosition.setRow(tileRow);
		tilePosition.setColumn(tileColumn);
	}
}