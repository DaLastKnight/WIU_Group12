#include "Position.h"

Position::Position()
{
}

void Position::setRow(int r)
{
	row = r;
}

void Position::setCol(int c)
{
	col = c;
}

int Position::getRow(void) const
{
	return row;
}

int Position::getCol(void) const
{
	return col;
}
