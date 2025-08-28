#pragma once
#include "Position.h"

class Entity
{
private:
	int num;
protected:
	Position pos;
	char type;

	int health;
	int attack;
	int defense;
	int speed;

public:
	Entity();
	Entity(int row, int col, char t, int hp, int atk, int def, int spd) 
		: pos { row, col }, type(t), health(hp), attack(atk), defense(def), speed(spd) {}

	void setStats(int new_hp, int new_atk, int new_def, int new_spd);
	void setType(char t);

	int getHealth() const;
	int getAttack() const;
	int getDefense() const;
	int getSpeed() const;

	char getType() const;

	virtual void attacking(Entity* target) {};
	virtual void defending(Entity* target) {};
};

