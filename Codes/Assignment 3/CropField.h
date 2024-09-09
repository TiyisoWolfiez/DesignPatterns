#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "SoilState.h"
#include "Truck.h"
#include <iostream>

class CropField : public FarmUnit {
private:
    std::string cropType;
    int totalCapacity;
    int currentStored;
    SoilState* soilState;
    Truck* fertilizerTruck;  // Truck for delivering fertilizers
    Truck* deliveryTruck;    // Truck for collecting crops

public:
    CropField(const std::string& cropType, int capacity)
        : cropType(cropType), totalCapacity(capacity), currentStored(0), soilState(nullptr),
          fertilizerTruck(nullptr), deliveryTruck(nullptr) {}

    ~CropField() {
        delete soilState;
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
        delete soilState;
        soilState = state;
    }

    void harvest() {
        if (soilState) {
            int harvestedCrops = soilState->harvestCrops(currentStored);
            std::cout << "Harvested " << harvestedCrops << " units of " << cropType << ".\n";
            currentStored -= harvestedCrops;
            if (currentStored < 0) currentStored = 0;  // Ensure non-negative storage
        } else {
            std::cout << "Soil state is unknown. Cannot harvest crops.\n";
        }

        if (currentStored >= totalCapacity * 0.9) { // Check if storage is nearing its limit
            if (deliveryTruck) {
                std::cout << "Storage nearing limit, calling delivery truck...\n";
                callTruck(deliveryTruck);
            }
        }
    }

    void rain() {
        if (soilState) {
            soilState->rain();
            if (soilState->getName() == "Dry" && fertilizerTruck) {
                std::cout << "Soil state is Dry, calling fertilizer truck...\n";
                callTruck(fertilizerTruck);
            }
        } else {
            std::cout << "Soil state is unknown. No effect of rain.\n";
        }
    }

    void addFertilizerTruck(Truck* truck) {
        fertilizerTruck = truck;
    }

    void addDeliveryTruck(Truck* truck) {
        deliveryTruck = truck;
    }

    void callTruck(Truck* truck) {
        if (truck) {
            truck->startEngine();
            truck->operate();
        }
    }
};

#endif // CROPFIELD_H
