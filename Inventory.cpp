#include "Inventory.h"
#include "Equipments.h"
#include "Weapons.h"
#include "Sword.h"
#include "Bow.h"
#include "Dagger.h"
#include "Items.h"
#include "Potions.h" // Corrected: "Potions.h" to "Potion.h"
#include <iostream>
#include <string>
#include <conio.h> // For _getch()
#include <cstdlib> // For system("cls")
#include <cctype> // For asciiToLower

// Helper function: Converts an ASCII character to lowercase.
char asciiToLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

// Helper function: Compares two strings for equality, ignoring ASCII case.
bool equalsIgnoreCaseASCII(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    for (size_t i = 0; i < str1.length(); ++i) {
        if (asciiToLower(str1[i]) != asciiToLower(str2[i])) {
            return false;
        }
    }
    return true;
}

// Constructor for the Inventory class.
// Initializes equipment and general item arrays with specified capacities.
Inventory::Inventory(size_t equipmentCapacity, size_t itemCapacity)
    : currentEquipmentSize(0), maxEquipmentCapacity(equipmentCapacity),
    currentItemSize(0), maxItemCapacity(itemCapacity),
    lastActionMessage("")
{
    // Allocate memory for equipment pointers and initialize to nullptr.
    equipments = new Equipments * [maxEquipmentCapacity];
    for (size_t i = 0; i < maxEquipmentCapacity; ++i) {
        equipments[i] = nullptr;
    }

    // Allocate memory for general item pointers and initialize to nullptr.
    generalItems = new Items * [maxItemCapacity];
    for (size_t i = 0; i < maxItemCapacity; ++i) {
        generalItems[i] = nullptr;
    }
}

// Destructor for the Inventory class.
// Deallocates all dynamically created equipment and item objects, then their arrays.
Inventory::~Inventory() {
    // Delete all equipment objects and then the equipment array.
    for (size_t i = 0; i < currentEquipmentSize; ++i) {
        if (equipments[i] != nullptr) {
            delete equipments[i];
        }
    }
    delete[] equipments;

    // Delete all general item objects and then the general items array.
    for (size_t i = 0; i < currentItemSize; ++i) {
        if (generalItems[i] != nullptr) {
            delete generalItems[i];
        }
    }
    delete[] generalItems;
}

// Adds an equipment item to the inventory.
// If inventory is full, the item is deleted.
void Inventory::addEquipment(Equipments* equipment) {
    if (currentEquipmentSize < maxEquipmentCapacity) {
        equipments[currentEquipmentSize++] = equipment;
        lastActionMessage = "Added " + equipment->getName() + " to equipment inventory.";
    }
    else {
        lastActionMessage = "Equipment inventory is full! Cannot add " + equipment->getName() + ".";
        delete equipment; // Delete item if it cannot be added.
    }
}

// Adds a general item to the inventory.
// If inventory is full, the item is deleted.
void Inventory::addItem(Items* item) {
    if (currentItemSize < maxItemCapacity) {
        generalItems[currentItemSize++] = item;
        lastActionMessage = "Added " + item->getName() + " to general items inventory.";
    }
    else {
        lastActionMessage = "General items inventory is full! Cannot add " + item->getName() + ".";
        delete item; // Delete item if it cannot be added.
    }
}

// Finds the index of a given equipment pointer in the `equipments` array.
// Returns (size_t)-1 if not found.
size_t Inventory::findEquipmentIndex(Equipments* eqPtr) const {
    for (size_t i = 0; i < currentEquipmentSize; ++i) {
        if (equipments[i] == eqPtr) {
            return i;
        }
    }
    return (size_t)-1;
}

// Finds the index of a given item pointer in the `generalItems` array.
// Returns (size_t)-1 if not found.
size_t Inventory::findItemIndex(Items* itemPtr) const {
    for (size_t i = 0; i < currentItemSize; ++i) {
        if (generalItems[i] == itemPtr) {
            return i;
        }
    }
    return (size_t)-1;
}

// Removes an equipment from the array at the specified index.
// Shifts subsequent elements to fill the gap. Returns the removed equipment pointer.
Equipments* Inventory::removeEquipment(size_t index) {
    if (index >= currentEquipmentSize) {
        return nullptr; // Invalid index.
    }
    Equipments* removedEq = equipments[index];
    // Shift elements to the left.
    for (size_t i = index; i < currentEquipmentSize - 1; ++i) {
        equipments[i] = equipments[i + 1];
    }
    equipments[currentEquipmentSize - 1] = nullptr; // Clear the last element.
    currentEquipmentSize--; // Decrease size.
    return removedEq;
}

// Removes a general item from the array at the specified index.
// Shifts subsequent elements to fill the gap. Returns the removed item pointer.
Items* Inventory::removeGeneralItem(size_t index) {
    if (index >= currentItemSize) {
        return nullptr; // Invalid index.
    }
    Items* removedItem = generalItems[index];
    // Shift elements to the left.
    for (size_t i = index; i < currentItemSize - 1; ++i) {
        generalItems[i] = generalItems[i + 1];
    }
    generalItems[currentItemSize - 1] = nullptr; // Clear the last element.
    currentItemSize--; // Decrease size.
    return removedItem;
}

// Retrieves all equipments of a specific `category` (type) into `outputArray`.
// Returns the count of items found.
int Inventory::getEquipmentsByType(const std::string& category, Equipments** outputArray, size_t maxOutputCount) const {
    int count = 0;
    for (size_t i = 0; i < currentEquipmentSize; ++i) {
        if (count >= maxOutputCount) break; // Prevent buffer overflow.
        if (equalsIgnoreCaseASCII(equipments[i]->getType(), category)) {
            outputArray[count++] = equipments[i];
        }
    }
    return count;
}

// Retrieves all general items of a specific `category` (type) into `outputArray`.
// Returns the count of items found.
int Inventory::getItemsByType(const std::string& category, Items** outputArray, size_t maxOutputCount) const {
    int count = 0;
    for (size_t i = 0; i < currentItemSize; ++i) {
        if (count >= maxOutputCount) break; // Prevent buffer overflow.
        if (equalsIgnoreCaseASCII(generalItems[i]->getType(), category)) {
            outputArray[count++] = generalItems[i];
        }
    }
    return count;
}

// Placeholder action for equipping an equipment.
std::string Inventory::equipEquipmentAction(Equipments* equipment) {
    // TODO: Implement actual equipping logic (e.g., updating player's equipped slot).
    return "You equipped " + equipment->getName() + "!\n";
}

// Placeholder action for unequipping an equipment.
std::string Inventory::unequipEquipmentAction(Equipments* equipment) {
    // TODO: Implement actual unequipping logic.
    return "You unequipped " + equipment->getName() + ".";
}

// Action to trash (delete) an equipment item.
// Returns true if successfully trashed, false otherwise.
bool Inventory::trashEquipmentAction(Equipments* equipment, size_t actualIndex) {
    Equipments* removed = removeEquipment(actualIndex);
    if (removed != nullptr) {
        delete removed; // Free memory of the trashed item.
        return true;
    }
    return false;
}

// Action to trash (delete) a general item.
// Returns true if successfully trashed, false otherwise.
bool Inventory::trashItemAction(Items* item, size_t actualIndex) {
    Items* removed = removeGeneralItem(actualIndex);
    if (removed != nullptr) {
        delete removed; // Free memory of the trashed item.
        return true;
    }
    return false;
}

// Action to use a general item.
// Handles specific logic for potions (consumption).
std::string Inventory::useItemAction(Items* item, size_t actualIndex) {
    std::string itemName = item->getName(); // Capture name before potential deletion.
    std::string message = "You used " + itemName + ".\n";
    if (equalsIgnoreCaseASCII(item->getType(), "POTION"));(equalsIgnoreCaseASCII(item->getType(), "MISCELLANEOUS")); {
        // If it's a potion, it's consumed (trashed).
        if (trashItemAction(item, actualIndex)) {
            message = itemName + " was consumed.\n"; // Use the captured name.
            return message;
        }
        else {
            message = "Error: Failed to consume " + itemName + ".\n";
            return message;
        }
    }
    // TODO: Add logic for other item types (e.g., buffs, quest items).
    return message;
}


// Handles the detailed view and actions for a selected equipment.
// Returns true if the inventory should be closed entirely, false to return to previous menu.
bool Inventory::handleEquipmentDetailsAndActions(const std::string& selectedCategory, Equipments* selectedEquipmentPtr, size_t actualIndex) {
    int actionSelection = 0;
    const int numActions = 3;
    const std::string actions[] = { "Equip", "Unequip", "Trash/Delete" };
    std::string actionMessage = "";
    bool itemWasRemovedLocal = false;
    // Capture the item's name before potential deletion to use in messages.
    std::string equipmentNameForMessage = selectedEquipmentPtr->getName();

    while (true) {
        // If the item was removed in the previous iteration (e.g., trashed),
        // we should exit this details view immediately.
        if (itemWasRemovedLocal) {
            return false; // Signal to calling function to refresh its list.
        }

        system("cls"); // Clear screen for item details display.

        std::cout << "--- " << equipmentNameForMessage << " Stats ---\n\n";
        selectedEquipmentPtr->displayStats();
        std::cout << "\n";

        std::cout << "Choose an action:\n";
        for (int i = 0; i < numActions; ++i) {
            std::cout << ((actionSelection == i) ? "> " : "  ") << actions[i] << "\n";
        }

        // Display any action messages.
        if (!actionMessage.empty()) {
            std::cout << "\n" << actionMessage << "\n";
            lastActionMessage = actionMessage; // Store for higher-level menu.
            actionMessage = ""; // Clear for next iteration.
        }

        std::cout << "\nUse W/S to navigate, Z to select, X to go back, I to close inventory.\n";

        char actionInput = (char)_getch(); // Get user input.
        actionInput = asciiToLower(actionInput); // Convert to lowercase.

        if (actionInput == 'i') { return true; } // Exit entire inventory.
        if (actionInput == 'x') { break; } // Go back to category list.

        switch (actionInput) {
        case 'w': // Move selection up.
            actionSelection = (actionSelection > 0) ? actionSelection - 1 : numActions - 1;
            break;
        case 's': // Move selection down.
            actionSelection = (actionSelection < numActions - 1) ? actionSelection + 1 : 0;
            break;
        case 'z': { // Select an action.
            switch (actionSelection) {
            case 0: // Use (Equip) action.
                actionMessage = equipEquipmentAction(selectedEquipmentPtr);
                break;
            case 1: // Unequip action.
                actionMessage = unequipEquipmentAction(selectedEquipmentPtr);
                break;
            case 2: { // Trash/Delete action.
                int confirmSelection = 0;
                const int numConfirmOptions = 2;
                const std::string confirmOptions[] = { "Yes", "No" };

                while (true) {
                    // Do not clear screen here; print confirmation below existing info.
                    std::cout << "\nAre you sure you want to trash " << equipmentNameForMessage << "?\n";
                    for (int i = 0; i < numConfirmOptions; ++i) {
                        std::cout << ((confirmSelection == i) ? "> " : "  ") << confirmOptions[i] << "\n";
                    }
                    std::cout << "\nUse W/S to navigate, Z to select, X to cancel, I to close inventory.\n";

                    char confirmInput = (char)_getch();
                    confirmInput = asciiToLower(confirmInput);

                    if (confirmInput == 'i') { return true; } // Exit entire inventory.
                    if (confirmInput == 'x') { actionMessage = "Trash cancelled.\n"; goto exit_confirm_loop; }

                    switch (confirmInput) {
                    case 'w': confirmSelection = (confirmSelection > 0) ? confirmSelection - 1 : numConfirmOptions - 1; break;
                    case 's': confirmSelection = (confirmSelection < numConfirmOptions - 1) ? confirmSelection + 1 : 0; break;
                    case 'z':
                        if (confirmSelection == 0) { // Confirmed "Yes" to trash.
                            if (trashEquipmentAction(selectedEquipmentPtr, actualIndex)) {
                                actionMessage = equipmentNameForMessage + " has been TRASHED.\n";
                                itemWasRemovedLocal = true; // Mark item as removed.
                            }
                            else {
                                actionMessage = "Error: Failed to trash " + equipmentNameForMessage + ".\n";
                            }
                        }
                        else { // Confirmed "No" to trash.
                            actionMessage = "Trash cancelled.\n";
                        }
                        goto exit_confirm_loop; // Exit confirmation loop.
                    default: break;
                    }
                }
            exit_confirm_loop:; // Label for exiting confirmation loop.
                break;
            }
            }
            // If item was removed, break from this outer switch to re-evaluate the while loop.
            if (itemWasRemovedLocal) break;
            break;
        }
        default: break;
        }
    }
    return false; // Normal exit from item details to category list.
}

// Handles the detailed view and actions for a selected general item.
// Returns true if the inventory should be closed entirely, false to return to previous menu.
bool Inventory::handleItemDetailsAndActions(const std::string& selectedCategory, Items* selectedItemPtr, size_t actualIndex) {
    int actionSelection = 0;
    const int numActions = 2;
    const std::string actions[] = { "Use", "Trash/Delete" };
    std::string actionMessage = "";
    bool itemWasRemovedLocal = false;
    // Capture the item's name before potential deletion to use in messages.
    std::string itemNameForMessage = selectedItemPtr->getName();

    while (true) {
        // If the item was removed in the previous iteration (e.g., trashed or consumed),
        // we should exit this details view immediately.
        if (itemWasRemovedLocal) {
            return false; // Signal to calling function to refresh its list.
        }

        system("cls"); // Clear screen for item details display.

        if (itemNameForMessage == "Wood") {
            std::cout << "--- " << itemNameForMessage << " Stats ---\n\n";
            selectedItemPtr->displayStats();
        }
        else if (itemNameForMessage == "Stone") {
            std::cout << "--- " << itemNameForMessage << " Stats ---\n\n";
            selectedItemPtr->displayStats();
        }
        else {
            std::cout << "--- " << itemNameForMessage << " Stats ---\n\n";
            selectedItemPtr->displayStats();
            std::cout << "\n";
            std::cout << "Choose an action:\n";
            for (int i = 0; i < numActions; ++i) {
                std::cout << ((actionSelection == i) ? "> " : "  ") << actions[i] << "\n";
            }
        }

        // Display any action messages.
        if (!actionMessage.empty()) {
            std::cout << "\n" << actionMessage << "\n";
            lastActionMessage = actionMessage; // Store for higher-level menu.
            actionMessage = ""; // Clear for next iteration.
        }

        std::cout << "\nUse W/S to navigate, Z to select, X to go back, I to close inventory.\n";


        char actionInput = (char)_getch(); // Get user input.
        actionInput = asciiToLower(actionInput); // Convert to lowercase.

        if (actionInput == 'i') { return true; } // Exit entire inventory.
        if (actionInput == 'x') { break; } // Go back to category list.

        switch (actionInput) {
        case 'w': // Move selection up.
            actionSelection = (actionSelection > 0) ? actionSelection - 1 : numActions - 1;
            break;
        case 's': // Move selection down.
            actionSelection = (actionSelection < numActions - 1) ? actionSelection + 1 : 0;
            break;
        case 'z': { // Select an action.
            switch (actionSelection) {
            case 0: { // Use action.
                actionMessage = useItemAction(selectedItemPtr, actualIndex);
                // Check if the item was consumed (trashed) by useItemAction.
                // We must do this by checking if the item is still valid, not by getType after potential deletion.
                // If it was a potion, useItemAction calls trashItemAction, which deletes the pointer.
                // So, if trashItemAction returned true, it means item was removed.
                // The useItemAction returns a message, we need to infer removal from that.
                // A better approach would be for useItemAction to return a bool indicating removal.
                // For now, we'll assume "consumed" in the message means it was removed.
                if (actionMessage.find("consumed") != std::string::npos || actionMessage.find("TRASHED") != std::string::npos) {
                    itemWasRemovedLocal = true;
                }
                if (itemWasRemovedLocal) { // If the item was removed, immediately return.
                    return false;
                }
                break;
            }
            case 1: { // Trash/Delete action.
                int confirmSelection = 0;
                const int numConfirmOptions = 2;
                const std::string confirmOptions[] = { "Yes", "No" };

                while (true) {
                    // Do not clear screen here; print confirmation below existing info.
                    std::cout << "\nAre you sure you want to trash " << itemNameForMessage << "?\n";
                    for (int i = 0; i < numConfirmOptions; ++i) {
                        std::cout << ((confirmSelection == i) ? "> " : "  ") << confirmOptions[i] << "\n";
                    }
                    std::cout << "\nUse W/S to navigate, Z to select, X to cancel, I to close inventory.\n";

                    char confirmInput = (char)_getch();
                    confirmInput = asciiToLower(confirmInput);

                    if (confirmInput == 'i') { return true; } // Exit entire inventory.
                    if (confirmInput == 'x') { actionMessage = "Trash cancelled.\n"; goto exit_confirm_loop; }

                    switch (confirmInput) {
                    case 'w': confirmSelection = (confirmSelection > 0) ? confirmSelection - 1 : numConfirmOptions - 1; break;
                    case 's': confirmSelection = (confirmSelection < numConfirmOptions - 1) ? confirmSelection + 1 : 0; break;
                    case 'z':
                        if (confirmSelection == 0) { // Confirmed "Yes" to trash.
                            if (trashItemAction(selectedItemPtr, actualIndex)) {
                                actionMessage = itemNameForMessage + " has been TRASHED.\n";
                                itemWasRemovedLocal = true; // Mark item as removed.
                            }
                            else {
                                actionMessage = "Error: Failed to trash " + itemNameForMessage + ".\n";
                            }
                        }
                        else { // Confirmed "No" to trash.
                            actionMessage = "Trash cancelled.\n";
                        }
                        goto exit_confirm_loop; // Exit confirmation loop.
                    default: break;
                    }
                }
            exit_confirm_loop:; // Label for exiting confirmation loop.
                break;
            }
            }
            // If item was removed, break from this outer switch to re-evaluate the while loop.
            if (itemWasRemovedLocal) break;
            break;
        }
        default: break;
        }
    }
    return false; // Normal exit from item details to category list.
}

// Handles the display and interaction for a specific equipment category.
// Returns true if the inventory should be closed entirely, false to return to previous menu.
bool Inventory::handleEquipmentCategoryItems(const std::string& selectedCategory) {
    int itemSelection = 0;
    char itemInput;

    const size_t MAX_CATEGORY_ITEMS = 100; // Max temporary array size for items in a category.
    Equipments* itemsInCategoryArray[MAX_CATEGORY_ITEMS];
    int itemsInCategoryCount = 0;

    while (true) {
        system("cls"); // Clear screen for category item list.
        std::cout << "--- " << selectedCategory << " Equipments ---\n\n";

        // Always re-fetch the list of items for the selected category.
        itemsInCategoryCount = getEquipmentsByType(selectedCategory, itemsInCategoryArray, MAX_CATEGORY_ITEMS);

        if (itemsInCategoryCount == 0) {
            // If the category is empty, set a message and return to the higher-level section menu.
            lastActionMessage = "No " + selectedCategory + " equipment in your inventory.";
            std::cout << lastActionMessage << "\n"; // Display the message before the pause.
            std::cout << "\nPress any key to go back.\n"; // Prompt user to press a key.
            _getch(); // Wait for user input.
            return false;
        }

        // Adjust itemSelection if it's out of bounds (e.g., due to item removal).
        if (itemSelection >= itemsInCategoryCount) {
            itemSelection = (itemsInCategoryCount > 0) ? itemsInCategoryCount - 1 : 0;
        }

        // Display items in the current category.
        for (int i = 0; i < itemsInCategoryCount; ++i) {
            std::cout << ((itemSelection == i) ? "> " : "  ") << itemsInCategoryArray[i]->getName() << "\n";
        }
        std::cout << "\nUse W/S to navigate, Z to select, X to go back, I to close inventory.\n";

        itemInput = (char)_getch(); // Get user input.
        itemInput = asciiToLower(itemInput); // Convert to lowercase.

        if (itemInput == 'i') { return true; } // Exit entire inventory.
        if (itemInput == 'x') { break; } // Go back to equipment section menu.

        switch (itemInput) {
        case 'w': // Move selection up.
            itemSelection = (itemSelection > 0) ? itemSelection - 1 : itemsInCategoryCount - 1;
            break;
        case 's': // Move selection down.
            itemSelection = (itemSelection < itemsInCategoryCount - 1) ? itemSelection + 1 : 0;
            break;
        case 'z': { // Select an item.
            Equipments* selectedItem = itemsInCategoryArray[itemSelection];
            size_t actualIndex = findEquipmentIndex(selectedItem);

            if (actualIndex != (size_t)-1) {
                // Call handler for item details and actions.
                if (handleEquipmentDetailsAndActions(selectedCategory, selectedItem, actualIndex)) {
                    return true; // Propagate full inventory exit if requested from details.
                }
                // After returning from details, the list might have changed,
                // so the loop will re-fetch items and adjust selection as needed.
            }
            else {
                // Error handling if item not found (shouldn't happen if logic is correct).
                system("cls");
                lastActionMessage = "Error: Selected equipment not found in main equipment inventory (possibly removed)!";
                std::cout << lastActionMessage << "\n"; // Display the error message.
                std::cout << "\nPress any key to continue.\n"; // Prompt for continuation.
                _getch(); // Wait for user input.
                break; // Break and let the loop re-evaluate the list.
            }
            break;
        }
        default: break;
        }
    }
    return false; // Normal exit from category list to equipment section.
}

// Handles the display and interaction for a specific general item category.
// Returns true if the inventory should be closed entirely, false to return to previous menu.
bool Inventory::handleItemCategoryItems(const std::string& selectedCategory) {
    int itemSelection = 0;
    char itemInput;

    const size_t MAX_CATEGORY_ITEMS = 100; // Max temporary array size for items in a category.
    Items* itemsInCategoryArray[MAX_CATEGORY_ITEMS];
    int itemsInCategoryCount = 0;

    while (true) {
        system("cls"); // Clear screen for category item list.
        std::cout << "--- " << selectedCategory << " Items ---\n\n";

        // Always re-fetch the list of items for the selected category.
        itemsInCategoryCount = getItemsByType(selectedCategory, itemsInCategoryArray, MAX_CATEGORY_ITEMS);

        if (itemsInCategoryCount == 0) {
            // If the category is empty, set a message and return to the higher-level section menu.
            lastActionMessage = "No " + selectedCategory + " items in your inventory.";
            std::cout << lastActionMessage << "\n"; // Display the message before the pause.
            std::cout << "\nPress any key to go back.\n"; // Prompt user to press a key.
            _getch(); // Wait for user input.
            return false;
        }

        // Adjust itemSelection if it's out of bounds (e.g., due to item removal).
        if (itemSelection >= itemsInCategoryCount) {
            itemSelection = (itemsInCategoryCount > 0) ? itemsInCategoryCount - 1 : 0;
        }

        // Display items in the current category.
        for (int i = 0; i < itemsInCategoryCount; ++i) {
            std::cout << ((itemSelection == i) ? "> " : "  ") << itemsInCategoryArray[i]->getName() << "\n";
        }
        std::cout << "\nUse W/S to navigate, Z to select, X to go back, I to close inventory.\n";

        itemInput = (char)_getch(); // Get user input.
        itemInput = asciiToLower(itemInput); // Convert to lowercase.

        if (itemInput == 'i') { return true; } // Exit entire inventory.
        if (itemInput == 'x') { break; } // Go back to general items section menu.

        switch (itemInput) {
        case 'w': // Move selection up.
            itemSelection = (itemSelection > 0) ? itemSelection - 1 : itemsInCategoryCount - 1;
            break;
        case 's': // Move selection down.
            itemSelection = (itemSelection < itemsInCategoryCount - 1) ? itemSelection + 1 : 0;
            break;
        case 'z': { // Select an item.
            Items* selectedItem = itemsInCategoryArray[itemSelection];
            size_t actualIndex = findItemIndex(selectedItem);

            if (actualIndex != (size_t)-1) {
                // Call handler for item details and actions.
                if (handleItemDetailsAndActions(selectedCategory, selectedItem, actualIndex)) {
                    return true; // Propagate full inventory exit if requested from details.
                }
                // After returning from details, the list might have changed,
                // so the loop will re-fetch items and adjust selection as needed.
            }
            else {
                // Error handling if item not found (shouldn't happen if logic is correct).
                system("cls");
                lastActionMessage = "Error: Selected item not found in main items inventory (possibly removed)!";
                std::cout << lastActionMessage << "\n"; // Display the error message.
                std::cout << "\nPress any key to continue.\n"; // Prompt for continuation.
                _getch(); // Wait for user input.
                break; // Break and let the loop re-evaluate the list.
            }
            break;
        }
        default: break;
        }
    }
    return false; // Normal exit from category list to general items section.
}


// Handles the equipment section of the inventory, allowing selection of equipment categories.
// Returns true if the inventory should be closed entirely, false to return to main menu.
bool Inventory::handleEquipmentSection() {
    int categorySelection = 0;
    char keyInput;
    const int numCategories = 2; // WEAPON, ARMOR (add more as needed).
    const std::string categories[] = { "WEAPON", "ARMOR" };

    while (true) {
        system("cls"); // Clear screen for equipment section menu.
        std::cout << "--- Equipment Inventory ---\n\n";
        std::cout << "Equipment Space: " << currentEquipmentSize << "/" << maxEquipmentCapacity << "\n\n";

        // Display message from previous action if any.
        if (!lastActionMessage.empty()) {
            std::cout << lastActionMessage << "\n\n";
            lastActionMessage = ""; // Clear message after displaying.
        }

        std::cout << "Available Categories:\n";
        for (int i = 0; i < numCategories; ++i) {
            std::cout << ((categorySelection == i) ? "> " : "  ") << categories[i] << "\n";
        }
        std::cout << "\nUse W/S to navigate, Z to select, X to go back, I to close inventory.\n";

        keyInput = (char)_getch(); // Get user input.
        keyInput = asciiToLower(keyInput); // Convert to lowercase.

        if (keyInput == 'i') { return true; } // Exit entire inventory.
        if (keyInput == 'x') { break; } // Go back to main inventory selection.

        switch (keyInput) {
        case 'w': // Move selection up.
            categorySelection = (categorySelection > 0) ? categorySelection - 1 : numCategories - 1;
            break;
        case 's': // Move selection down.
            categorySelection = (categorySelection < numCategories - 1) ? categorySelection + 1 : 0;
            break;
        case 'z': { // Select a category.
            // Call handler for selected category items.
            if (handleEquipmentCategoryItems(categories[categorySelection])) {
                return true; // Propagate full inventory exit if requested from deeper menu.
            }
            break;
        }
        default: break;
        }
    }
    return false; // Normal exit, go back to main inventory selection.
}

// Handles the general items section of the inventory, allowing selection of item categories.
// Returns true if the inventory should be closed entirely, false to return to main menu.
bool Inventory::handleItemSection() {
    int categorySelection = 0;
    char keyInput;
    const int numCategories = 3; // POTION, MATERIAL (add more as needed).
    const std::string categories[] = { "POTION", "MATERIAL", "MISCELLANEOUS"}; // Example categories.

    while (true) {
        system("cls"); // Clear screen for general items section menu.
        std::cout << "--- General Items Inventory ---\n\n";

        std::cout << "Available Categories:\n";
        for (int i = 0; i < numCategories; ++i) {
            std::cout << ((categorySelection == i) ? "> " : "  ") << categories[i] << "\n";
        }
        std::cout << "\nUse W/S to navigate, Z to select, X to go back, I to close inventory.\n";

        keyInput = (char)_getch(); // Get user input.
        keyInput = asciiToLower(keyInput); // Convert to lowercase.

        if (keyInput == 'i') { return true; } // Exit entire inventory.
        if (keyInput == 'x') { break; } // Go back to main inventory selection.

        switch (keyInput) {
        case 'w': // Move selection up.
            categorySelection = (categorySelection > 0) ? categorySelection - 1 : numCategories - 1;
            break;
        case 's': // Move selection down.
            categorySelection = (categorySelection < numCategories - 1) ? categorySelection + 1 : 0;
            break;
        case 'z': { // Select a category.
            // Call handler for selected category items.
            if (handleItemCategoryItems(categories[categorySelection])) {
                return true; // Propagate full inventory exit if requested from deeper menu.
            }
            break;
        }
        default: break;
        }
    }
    return false; // Normal exit, go back to main inventory selection.
}


// Opens the main inventory menu, allowing selection between equipment and general items sections.
void Inventory::openInventory()
{
    int currentSelection = 0;
    char keyInput;
    const int numMainOptions = 2; // View Equipments, View Items.
    const std::string mainOptions[] = { "View Equipments", "View Items" };

    while (true) {
        system("cls"); // Clear screen for main inventory menu.
        std::cout << "--- Main Inventory Menu ---\n\n";

        // Display current item and equipment space.
        std::cout << "Equipment Space: " << currentEquipmentSize << "/" << maxEquipmentCapacity << "\n";

        std::cout << "Select a Section:\n";
        for (int i = 0; i < numMainOptions; ++i) {
            std::cout << ((currentSelection == i) ? "> " : "  ") << mainOptions[i] << "\n";
        }
        std::cout << "\nUse W/S to navigate, Z to select, I to close inventory.\n";

        keyInput = (char)_getch(); // Get user input.
        keyInput = asciiToLower(keyInput); // Convert to lowercase.

        if (keyInput == 'i') { // 'I' to close inventory entirely from main menu.
            std::cout << "\nExiting Inventory. Goodbye!\n";
            return;
        }

        switch (keyInput) {
        case 'w': // Move selection up.
            currentSelection = (currentSelection > 0) ? currentSelection - 1 : numMainOptions - 1;
            break;
        case 's': // Move selection down.
            currentSelection = (currentSelection < numMainOptions - 1) ? currentSelection + 1 : 0;
            break;
        case 'z': { // Select a main option.
            switch (currentSelection) {
            case 0: // View Equipments section.
                if (handleEquipmentSection()) {
                    return; // Propagate full inventory exit if requested from deeper menu.
                }
                break;
            case 1: // View General Items section.
                if (handleItemSection()) {
                    return; // Propagate full inventory exit if requested from deeper menu.
                }
                break;
            }
            break;
        }
        default: break;
        }
    }
}