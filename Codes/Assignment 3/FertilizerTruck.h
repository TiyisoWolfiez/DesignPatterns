#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H

#include "Truck.h"
#include <iostream>

/**
 * @class FertilizerTruck
 * @brief Concrete class representing a fertilizer truck.
 * 
 * This class extends the Truck class and represents a truck specifically for delivering fertilizers.
 */
class FertilizerTruck : public Truck {
public:
    /**
     * @brief Starts the engine of the fertilizer truck.
     * 
     * Overrides the startEngine method from the Truck class to provide
     * specific behavior for the fertilizer truck.
     */
    void startEngine() override {
        std::cout << "Fertilizer truck engine started.\n";
    }

    /**
     * @brief Operates the fertilizer truck.
     * 
     * Overrides the operate method from the Truck class to provide
     * specific behavior for delivering fertilizer to crop fields.
     */
    void operate() override {
        std::cout << "Delivering fertilizer to the crop field...\n";
    }
};

#endif // FERTILIZERTRUCK_H