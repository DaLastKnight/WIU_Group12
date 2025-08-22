#include <iostream>
#include "Entity.h"

Entity::Entity() : pos(0, 0), type(' '), health(0), attack(0), defense(0), speed(0)
{
}

void Entity::setStats(int new_hp, int new_atk, int new_def, int new_spd)
{
	health = new_hp;
	attack = new_atk;
	defense = new_def;
	speed = new_spd;
}

void Entity::setType(char t)
{
	type = t;
}

int Entity::getHealth() const
{
	return health;
}

int Entity::getAttack() const
{
	return attack;
}

int Entity::getDefense() const
{
	return defense;
}

int Entity::getSpeed() const
{
	return speed;
}

char Entity::getType() const
{
	return type;
}
