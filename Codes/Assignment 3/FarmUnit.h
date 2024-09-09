#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <string>
#include <vector>
#include <algorithm>
#include "Truck.h"

/**
 * @class FarmUnit
 * @brief Abstract base class representing a unit on a farm.
 * 
 * This class provides a common interface for different types of farm units. It includes
 * methods for managing child units, calculating capacity, and interacting with trucks.
 */
class FarmUnit {
private:
    std::vector<Truck*> trucks; ///< List of trucks associated with this unit

public:
    /**
     * @brief Pure virtual function to get the total capacity of the farm unit.
     * 
     * @return The total capacity of the unit.
     */
    virtual int getTotalCapacity() const = 0;

    /**
     * @brief Pure virtual function to get the crop type of the farm unit.
     * 
     * @return The type of crop associated with the unit.
     */
    virtual std::string getCropType() const = 0;

    /**
     * @brief Pure virtual function to get the soil state name of the farm unit.
     * 
     * @return The name of the soil state.
     */
    virtual std::string getSoilStateName() const = 0;

    /**
     * @brief Adds a child unit to this farm unit.
     * 
     * This method is intended to be overridden by derived classes that support
     * hierarchical structures of farm units.
     * 
     * @param unit Pointer to the child farm unit to be added.
     */
    virtual void add(FarmUnit* unit) {}

    /**
     * @brief Removes a child unit from this farm unit.
     * 
     * This method is intended to be overridden by derived classes that support
     * hierarchical structures of farm units.
     * 
     * @param unit Pointer to the child farm unit to be removed.
     */
    virtual void remove(FarmUnit* unit) {}

    /**
     * @brief Gets a child unit at a specific index.
     * 
     * This method is intended to be overridden by derived classes that support
     * hierarchical structures of farm units.
     * 
     * @param index Index of the child unit to retrieve.
     * @return Pointer to the child farm unit at the specified index.
     */
    virtual FarmUnit* getChild(int index) { return nullptr; }

    /**
     * @brief Gets the count of child units.
     * 
     * This method is intended to be overridden by derived classes that support
     * hierarchical structures of farm units.
     * 
     * @return The number of child units.
     */
    virtual int getChildCount() const { return 0; }

    /**
     * @brief Virtual destructor for the FarmUnit class.
     * 
     * This destructor ensures that all associated trucks are properly deleted
     * to prevent memory leaks.
     */
    virtual ~FarmUnit() {
        for (auto truck : trucks) {
            delete truck;
        }
    }

    /**
     * @brief Buys and associates a truck with this farm unit.
     * 
     * This method adds a truck to the list of trucks for this unit.
     * 
     * @param truck Pointer to the truck to be added.
     */
    void buyTruck(Truck* truck) {
        trucks.push_back(truck);
    }

    /**
     * @brief Sells and disassociates a truck from this farm unit.
     * 
     * This method removes a truck from the list of trucks and deletes it.
     * 
     * @param truck Pointer to the truck to be removed.
     */
    void sellTruck(Truck* truck) {
        auto it = std::find(trucks.begin(), trucks.end(), truck);
        if (it != trucks.end()) {
            delete *it;  // Delete the truck
            trucks.erase(it);  // Remove the truck from the vector
        }
    }

    /**
     * @brief Calls all associated trucks to start their engines and operate.
     * 
     * This method starts each truck and performs its operation.
     */
    void callTruck() {
        for (auto truck : trucks) {
            truck->startEngine();
            truck->operate();
        }
    }
};

#endif // FARMUNIT_H