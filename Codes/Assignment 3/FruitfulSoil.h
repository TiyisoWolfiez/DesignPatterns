// FruitfulSoil.h
#ifndef FRUITFULSOIL_H
#define FRUITFULSOIL_H

#include "SoilState.h"
#include <iostream>

// Concrete State: FruitfulSoil
class FruitfulSoil : public SoilState {
public:
    int harvestCrops(int currentStored) override {
        std::cout << "Harvesting crops with Fruitful Soil... Yield is high!\n";
        return currentStored * 3; // x3 crop yield
    }

    void rain() override {
        std::cout << "Rain on Fruitful Soil causes flooding and changes it to Flooded Soil.\n";
        // Potentially change the soil state here if needed
    }

    std::string getName() const override {
        return "Fruitful";
    }
};

#endif // FRUITFULSOIL_H
