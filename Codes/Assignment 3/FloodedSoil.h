#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H

#include "SoilState.h"
#include <iostream>

/**
 * @class FloodedSoil
 * @brief Concrete class representing a flooded soil state.
 * 
 * This class extends the SoilState class and represents a state where the soil is flooded,
 * preventing crop growth and making it unsuitable for harvesting.
 */
class FloodedSoil : public SoilState {
public:
    /**
     * @brief Attempts to harvest crops from flooded soil.
     * 
     * Overrides the harvestCrops method from the SoilState class to return 0,
     * indicating that no crops can be harvested from flooded soil.
     * 
     * @param currentStored The amount of crops currently stored.
     * @return int The amount of crops harvested, which is always 0 for flooded soil.
     */
    int harvestCrops(int currentStored) override {
        std::cout << "Flooded Soil prevents crop growth. No crops to harvest.\n";
        return 0; // Prevents harvesting
    }

    /**
     * @brief Processes rain on flooded soil.
     * 
     * Overrides the rain method from the SoilState class. On flooded soil,
     * additional rain has no effect.
     */
    void rain() override {
        std::cout << "More rain on Flooded Soil does nothing.\n";
        // No state change
    }

    /**
     * @brief Gets the name of the soil state.
     * 
     * Overrides the getName method from the SoilState class to return the name of the state,
     * which is "Flooded".
     * 
     * @return std::string The name of the soil state.
     */
    std::string getName() const override {
        return "Flooded";
    }
};

#endif // FLOODEDSOIL_H