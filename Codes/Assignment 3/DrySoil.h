#ifndef DRYSOIL_H
#define DRYSOIL_H

#include "SoilState.h"
#include <iostream>

/**
 * @class DrySoil
 * @brief Represents the state of dry soil in the soil state pattern.
 * 
 * This class is a concrete implementation of the `SoilState` abstract class
 * and represents a state where the soil is dry. It provides methods for 
 * harvesting crops and handling rain, reflecting the minimal yield and 
 * potential transformation of the soil state.
 */
class DrySoil : public SoilState {
public:
    /**
     * @brief Harvests crops from the dry soil.
     * 
     * The yield from dry soil is minimal. This method simulates the crop 
     * harvest and returns the amount of crops harvested based on the dry 
     * soil state.
     * 
     * @param currentStored The current amount of stored crops.
     * @return The amount of crops harvested.
     */
    int harvestCrops(int currentStored) override {
        std::cout << "Harvesting crops with Dry Soil... Yield is minimal.\n";
        return currentStored * 1;
    }

    /**
     * @brief Simulates rain on dry soil.
     * 
     * When rain is simulated on dry soil, it changes the state to fruitful soil.
     * The actual state change logic can be implemented here if needed.
     */
    void rain() override {
        std::cout << "Rain on Dry Soil turns it into Fruitful Soil.\n";
        // Potentially change the soil state here if needed
    }

    /**
     * @brief Gets the name of the dry soil state.
     * 
     * @return The name of the soil state as a string.
     */
    std::string getName() const override {
        return "Dry";
    }
};

#endif // DRYSOIL_H
