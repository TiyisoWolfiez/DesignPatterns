// CropField.h
#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "SoilState.h"  // Use SoilState interface
#include <iostream>

// Leaf Class
class CropField : public FarmUnit {
private:
    std::string cropType;
    int totalCapacity;
    int currentStored;
    SoilState* soilState;  // Current state of the soil

public:
    CropField(const std::string& cropType, int capacity)
        : cropType(cropType), totalCapacity(capacity), currentStored(0), soilState(nullptr) {}

    ~CropField() {
        delete soilState; // Clean up dynamically allocated state
    }

    int getTotalCapacity() const override {
        return totalCapacity;
    }

    std::string getCropType() const override {
        return cropType;
    }

    std::string getSoilStateName() const override {
        return soilState ? soilState->getName() : "Unknown";
    }

    void setSoilState(SoilState* state) {
        delete soilState;  // Clean up old state
        soilState = state;
    }

    void harvest() {
        if (soilState) {
            int harvestedCrops = soilState->harvestCrops(currentStored);
            std::cout << "Harvested " << harvestedCrops << " units of " << cropType << ".\n";
        } else {
            std::cout << "Soil state is unknown. Cannot harvest crops.\n";
        }
    }

    void rain() {
        if (soilState) {
            soilState->rain();
        } else {
            std::cout << "Soil state is unknown. No effect of rain.\n";
        }
    }
};

#endif // CROPFIELD_H
