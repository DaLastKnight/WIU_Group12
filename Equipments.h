#pragma once
#include <string>

class Equipments
{
protected:
	std::string name;
	std::string type;
	int tier;

public:
	Equipments();

	virtual std::string getName() const;
	virtual std::string getType() const;
	virtual int getTier() const;
	virtual void displayStats() const = 0;
};

