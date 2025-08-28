#include "Entity.h"
#include <string>

#pragma once
class PlayerClass
{
protected:
	std::string className;
public:
	PlayerClass();
	PlayerClass(std::string name);
	virtual int bonusMultiplier() const = 0;
	virtual void setClassStats(Entity& entity) = 0;
	//char getClass();
	virtual ~PlayerClass() = default;
	std::string getName();
};

