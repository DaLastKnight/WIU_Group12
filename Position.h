#pragma once
class Position
{
private:
	int row;
	int col;

public:
	Position();
	Position(int r, int c) : row(r), col(c) {}

	void setRow(int r);
	void setCol(int c);

	int getRow(void) const;
	int getCol(void) const;
};

