#pragma once
class Gold
{
private:
	int totalGold;
	
public:
	Gold(int startingGold);

	int getTotalGold() const;
	void setTotalGold(int total);
	void displayAllGold();
};