#ifndef FRUITFULSOIL_H
#define FRUITFULSOIL_H

#include "SoilState.h"
#include <iostream>

/**
 * @class FruitfulSoil
 * @brief Concrete class representing a fruitful soil state.
 * 
 * This class extends the SoilState class and represents a state where the soil is highly productive,
 * resulting in a high crop yield. It also handles the effect of rain on the soil.
 */
class FruitfulSoil : public SoilState {
public:
    /**
     * @brief Harvests crops from fruitful soil.
     * 
     * Overrides the harvestCrops method from the SoilState class to return a high yield of crops.
     * The yield is multiplied by 3 for fruitful soil.
     * 
     * @param currentStored The amount of crops currently stored.
     * @return int The amount of crops harvested, which is three times the current stored amount.
     */
    int harvestCrops(int currentStored) override {
        std::cout << "Harvesting crops with Fruitful Soil... Yield is high!\n";
        return currentStored * 3; // x3 crop yield
    }

    /**
     * @brief Processes rain on fruitful soil.
     * 
     * Overrides the rain method from the SoilState class. On fruitful soil, rain causes flooding
     * and changes the soil state to FloodedSoil.
     */
    void rain() override {
        std::cout << "Rain on Fruitful Soil causes flooding and changes it to Flooded Soil.\n";
        // Potentially change the soil state here if needed
    }

    /**
     * @brief Gets the name of the soil state.
     * 
     * Overrides the getName method from the SoilState class to return the name of the state,
     * which is "Fruitful".
     * 
     * @return std::string The name of the soil state.
     */
    std::string getName() const override {
        return "Fruitful";
    }
};

#endif // FRUITFULSOIL_H