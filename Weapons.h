#pragma once
#include "Equipments.h"
#include <string>

class Weapons : public Equipments
{
protected:
    std::string name;
    int price;
    int baseAttack;
    int tier;
public:
    Weapons();

    // For Inventory
    std::string getName() const override { return name; }
    std::string getType() const override { return "WEAPON"; }
    void displayStats() const;
};  