// DrySoil.h
#ifndef DRYSOIL_H
#define DRYSOIL_H

#include "SoilState.h"
#include <iostream>

// Concrete State: DrySoil
class DrySoil : public SoilState {
public:
    int harvestCrops(int currentStored) override {
        std::cout << "Harvesting crops with Dry Soil... Yield is minimal.\n";
        return currentStored * 1; // x1 crop yield
    }

    void rain() override {
        std::cout << "Rain on Dry Soil turns it into Fruitful Soil.\n";
        // Potentially change the soil state here if needed
    }

    std::string getName() const override {
        return "Dry";
    }
};

#endif // DRYSOIL_H
