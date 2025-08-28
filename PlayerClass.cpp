#include "PlayerClass.h"
#include <string>

PlayerClass::PlayerClass()
{
}

PlayerClass::PlayerClass(std::string name)
{
	className = name;
}

std::string PlayerClass::getName()
{
	return className;
}
