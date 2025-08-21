#pragma once
class Position
{
private:
	int row;
	int column;
public:
	Position();
	Position(int inputRow, int inputColumn);
	~Position();

	int getRow() const;
	int getColumn() const;
	void setRow(int newRow);
	void setColumn(int newColumn);
};

