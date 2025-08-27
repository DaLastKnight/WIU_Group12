#include "Charms.h"
#include <iostream>

// Constructor for Charms
Charms::Charms(const std::string& name): Items() // Call base class constructor
{
}

// Getter for the max charm count
int Charms::getMaxCharms() const
{
    return maxCharms;
}

void Charms::displayMaxCharms() const
{
    std::cout << "\nMax Charms: " << maxCharms << std::endl;
}
