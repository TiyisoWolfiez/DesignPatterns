// FloodedSoil.h
#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H

#include "SoilState.h"
#include <iostream>

// Concrete State: FloodedSoil
class FloodedSoil : public SoilState {
public:
    int harvestCrops(int currentStored) override {
        std::cout << "Flooded Soil prevents crop growth. No crops to harvest.\n";
        return 0; // Prevents harvesting
    }

    void rain() override {
        std::cout << "More rain on Flooded Soil does nothing.\n";
        // No state change
    }

    std::string getName() const override {
        return "Flooded";
    }
};

#endif // FLOODEDSOIL_H
