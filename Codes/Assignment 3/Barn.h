// Barn.h
#ifndef BARN_H
#define BARN_H

#include "FarmUnit.h"

/**
 * @class Barn
 * @brief Represents a barn in the farm.
 * 
 * This class is a concrete implementation of the `FarmUnit` class that 
 * represents a barn with a specific capacity. It does not have a crop type 
 * or soil state.
 */
class Barn : public FarmUnit {
private:
    int capacity; /**< Capacity of the barn */

public:
    /**
     * @brief Constructs a Barn with a given capacity.
     * @param capacity The capacity of the barn.
     */
    Barn(int capacity) : capacity(capacity) {}

    /**
     * @brief Gets the total capacity of the barn.
     * @return The capacity of the barn.
     */
    int getTotalCapacity() const override {
        return capacity;
    }

    /**
     * @brief Gets the crop type of the barn.
     * @return A string indicating that barns do not have a crop type.
     */
    std::string getCropType() const override {
        return "None";
    }

    /**
     * @brief Gets the soil state of the barn.
     * @return A string indicating that barns do not have a soil state.
     */
    std::string getSoilStateName() const override {
        return "N/A";
    }
};

#endif // BARN_H
