#include "Position.h"

Position::Position()
{
	row = 0;
	column = 0;
}

Position::Position(int inputRow, int inputColumn)
{
	row = inputRow;
	column = inputColumn;
}

Position::~Position()
{

}

int Position::getRow() const
{
	return row;
}

int Position::getColumn() const
{
	return column;
}

void Position::setRow(int newRow)
{
	row = newRow;
}

void Position::setColumn(int newColumn)
{
	column = newColumn;
}
