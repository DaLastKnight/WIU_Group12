#include "Player.h"

#pragma once
class SelectClass
{
private:
	bool confirmSelection();
	Player* player;
public:
	Player* getPlayer();

	SelectClass() : player(nullptr) {}

	void chooseClass();
};

