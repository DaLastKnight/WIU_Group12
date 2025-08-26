#pragma once
#include "Weapons.h"

class Bow : public Weapons
{
protected:

public:
    Bow(int tier);
    void displayStats() const;
    std::string getName() const;
};