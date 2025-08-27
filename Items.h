#pragma once
#include <string>

class Items
{
protected:
	int price;

public:
	~Items() = default;
	virtual std::string getName() const = 0;
	virtual std::string getType() const = 0;
	virtual void displayStats() const = 0;
	virtual void itemSprite();
	int getPrice() const;
};

