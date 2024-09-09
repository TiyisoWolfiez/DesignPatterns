#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "SoilState.h"
#include "Truck.h"
#include <iostream>

/**
 * @class CropField
 * @brief Represents a crop field with its crop type, storage capacity, and soil state.
 * 
 * This class manages crop storage and interacts with soil states. It supports operations like 
 * harvesting crops and responding to rain. It also integrates with trucks for fertilizer and 
 * crop delivery.
 */
class CropField : public FarmUnit {
private:
    std::string cropType; ///< Type of crop in the field
    int totalCapacity; ///< Total storage capacity of the field
    int currentStored; ///< Current amount of stored crops
    SoilState* soilState; ///< Pointer to the soil state of the field
    Truck* fertilizerTruck; ///< Truck for delivering fertilizers
    Truck* deliveryTruck; ///< Truck for collecting crops

public:
    /**
     * @brief Constructor for the CropField class.
     * 
     * Initializes the crop field with a crop type and capacity.
     * 
     * @param cropType The type of crop in the field.
     * @param capacity The total storage capacity of the field.
     */
    CropField(const std::string& cropType, int capacity)
        : cropType(cropType), totalCapacity(capacity), currentStored(0), soilState(nullptr),
          fertilizerTruck(nullptr), deliveryTruck(nullptr) {}

    /**
     * @brief Destructor for the CropField class.
     * 
     * Deletes the soil state to prevent memory leaks.
     */
    ~CropField() {
        delete soilState;
    }

    /**
     * @brief Gets the total capacity of the crop field.
     * 
     * @return The total capacity of the crop field.
     */
    int getTotalCapacity() const override {
        return totalCapacity;
    }

    /**
     * @brief Gets the type of crop in the field.
     * 
     * @return The type of crop in the field.
     */
    std::string getCropType() const override {
        return cropType;
    }

    /**
     * @brief Gets the name of the current soil state.
     * 
     * @return The name of the current soil state, or "Unknown" if the soil state is not set.
     */
    std::string getSoilStateName() const override {
        return soilState ? soilState->getName() : "Unknown";
    }

    /**
     * @brief Sets the soil state of the crop field.
     * 
     * This method updates the soil state, deleting any previous state.
     * 
     * @param state Pointer to the new soil state.
     */
    void setSoilState(SoilState* state) {
        delete soilState;
        soilState = state;
    }

    /**
     * @brief Harvests crops from the field.
     * 
     * This method harvests crops based on the current soil state and updates the stored crop amount.
     * If storage is nearing its limit, it calls the delivery truck to collect crops.
     */
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

    /**
     * @brief Simulates rain on the crop field.
     * 
     * This method updates the soil state if necessary and calls the fertilizer truck if the soil state is Dry.
     */
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

    /**
     * @brief Adds a fertilizer truck for the crop field.
     * 
     * This method assigns a truck for delivering fertilizers to the field.
     * 
     * @param truck Pointer to the fertilizer truck.
     */
    void addFertilizerTruck(Truck* truck) {
        fertilizerTruck = truck;
    }

    /**
     * @brief Adds a delivery truck for the crop field.
     * 
     * This method assigns a truck for collecting crops from the field.
     * 
     * @param truck Pointer to the delivery truck.
     */
    void addDeliveryTruck(Truck* truck) {
        deliveryTruck = truck;
    }

    /**
     * @brief Calls a truck to start its engine and operate.
     * 
     * This method starts the engine and performs operations for the provided truck.
     * 
     * @param truck Pointer to the truck to be called.
     */
    void callTruck(Truck* truck) {
        if (truck) {
            truck->startEngine();
            truck->operate();
        }
    }
};

#endif // CROPFIELD_H