#include "PlayerClass.h"
#include <string>

PlayerClass::PlayerClass()
{
	className = "";
}

PlayerClass::PlayerClass(std::string name)
{
	className = name;
}

std::string PlayerClass::getName()
{
	return className;
}
