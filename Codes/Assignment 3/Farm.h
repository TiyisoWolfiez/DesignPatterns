#ifndef FARM_H
#define FARM_H

#include <vector>
#include <string>
#include <algorithm>
#include "FarmUnit.h"

/**
 * @class Farm
 * @brief A composite class representing a farm that can contain multiple `FarmUnit` objects.
 * 
 * This class allows the addition and removal of `FarmUnit` objects, provides methods to access 
 * child units, and calculates the total capacity of all contained units. It serves as a composite 
 * in the Composite design pattern.
 */
class Farm : public FarmUnit {
private:
    std::vector<FarmUnit*> children; ///< Collection of child `FarmUnit` objects

public:
    /**
     * @brief Adds a `FarmUnit` to the farm.
     * 
     * This method appends a `FarmUnit` to the list of children, allowing the farm to contain 
     * multiple units.
     * 
     * @param unit The `FarmUnit` to be added.
     */
    void add(FarmUnit* unit) override {
        children.push_back(unit);
    }

    /**
     * @brief Removes a `FarmUnit` from the farm.
     * 
     * This method removes a specified `FarmUnit` from the list of children if it exists.
     * 
     * @param unit The `FarmUnit` to be removed.
     */
    void remove(FarmUnit* unit) override {
        auto it = std::remove(children.begin(), children.end(), unit);
        if (it != children.end()) {
            children.erase(it);
        }
    }

    /**
     * @brief Gets a child `FarmUnit` at a specified index.
     * 
     * This method retrieves the child `FarmUnit` at the given index if the index is valid.
     * 
     * @param index The index of the child `FarmUnit` to retrieve.
     * @return The child `FarmUnit` at the specified index, or `nullptr` if the index is invalid.
     */
    FarmUnit* getChild(int index) override {
        if (index >= 0 && index < children.size()) {
            return children[index];
        }
        return nullptr;
    }

    /**
     * @brief Gets the number of child `FarmUnit` objects.
     * 
     * @return The number of child `FarmUnit` objects.
     */
    int getChildCount() const override {
        return children.size();
    }

    /**
     * @brief Calculates the total capacity of all child `FarmUnit` objects.
     * 
     * This method sums the capacities of all child units to provide the total capacity of the farm.
     * 
     * @return The total capacity of all child `FarmUnit` objects.
     */
    int getTotalCapacity() const override {
        int totalCapacity = 0;
        for (auto& child : children) {
            totalCapacity += child->getTotalCapacity();
        }
        return totalCapacity;
    }

    /**
     * @brief Provides a description of the crop type for the farm.
     * 
     * Since a farm does not have a specific crop type, this method returns a descriptive string.
     * 
     * @return A string indicating that the farm does not have a crop type.
     */
    std::string getCropType() const override {
        return "Farm does not have a crop type.";
    }

    /**
     * @brief Provides a description of the soil state for the farm.
     * 
     * Since a farm does not have a specific soil state, this method returns a descriptive string.
     * 
     * @return A string indicating that the farm does not have a soil state.
     */
    std::string getSoilStateName() const override {
        return "Farm does not have a soil state.";
    }

    /**
     * @brief Destructor that cleans up all child `FarmUnit` objects.
     * 
     * This destructor iterates through the list of children and deletes each one to avoid memory leaks.
     */
    ~Farm() override {
        for (auto& child : children) {
            delete child;
        }
    }
};

#endif // FARM_H