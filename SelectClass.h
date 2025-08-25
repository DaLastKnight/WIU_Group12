#include "Player.h"

#pragma once
class SelectClass
{
private:
	bool confirmSelection();
	Player* player;
	PlayerClass* pc;
public:
	Player* getPlayer();

	SelectClass() : player(nullptr), pc(nullptr) {}

	void chooseClass(Player& player);

};

