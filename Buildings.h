#pragma once
#include <iostream>
#include "Position.h"

class Game;
class Wood;
class Stone;

class Buildings
{
protected:
	Position position;
	Wood* woodPtr;
	Stone* stonePtr;
	std::string buildingName;
	std::string buffDescription;
	char tileSymbol;
	int buildingTier;
	int woodPrice;
	int stonePrice;
	bool isBuildingUpgraded;

	int hp;
	int atk;
	int def;
	int spd;

	void repairMenu();
	void showBuildingInfo();
public:
	Buildings(Game* gamePtr);
	~Buildings();

	int getHealth() const;
	int getAttack() const;
	int getDefense() const;
	int getSpeed() const;

	virtual void printBuilding() = 0;
	void interactBuilding();
	Position getPosition() const;
	char getTileSymbol() const;
};

