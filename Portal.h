#pragma once
#include <string>

class Portal
{
private:
	bool hasTeleported;
public:
	Portal();
	
	char mainMenu(std::string& currentLocation);

	char teleport(std::string& currentLocation);
};

