#include "Player.h"

#pragma once
class selectClass
{
private:
	bool confirmSelection();
	Player* player;
public:
	Player* getPlayer();

	selectClass() : player(nullptr) {}

	void chooseClass();
};

