#ifndef SOILSTATE_H
#define SOILSTATE_H

#include <string>

/**
 * @class SoilState
 * @brief Abstract base class for different soil states.
 * 
 * This class defines the interface for various soil states in the system. Each derived class
 * represents a specific type of soil state with its own behavior for harvesting crops and handling rain.
 */
class SoilState {
public:
    /**
     * @brief Virtual destructor for SoilState.
     * 
     * Ensures proper cleanup of derived classes.
     */
    virtual ~SoilState() = default;

    /**
     * @brief Harvests crops based on the soil state.
     * 
     * Pure virtual function that must be implemented by derived classes to handle crop harvesting
     * based on the specific characteristics of the soil state.
     * 
     * @param currentStored The amount of crops currently stored.
     * @return int The amount of crops harvested.
     */
    virtual int harvestCrops(int currentStored) = 0;

    /**
     * @brief Simulates rainfall and changes the state of the soil.
     * 
     * Pure virtual function that must be implemented by derived classes to handle the effects of
     * rain on the soil state, potentially changing it to another state.
     */
    virtual void rain() = 0;

    /**
     * @brief Gets the name of the current soil state.
     * 
     * Pure virtual function that must be implemented by derived classes to return a string
     * representing the name of the soil state.
     * 
     * @return std::string The name of the soil state.
     */
    virtual std::string getName() const = 0;
};

#endif // SOILSTATE_H