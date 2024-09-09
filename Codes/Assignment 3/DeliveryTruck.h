#ifndef DELIVERYTRUCK_H
#define DELIVERYTRUCK_H

#include "Truck.h"
#include <iostream>

/**
 * @class DeliveryTruck
 * @brief Represents a delivery truck for transporting harvested crops.
 * 
 * This class derives from the `Truck` base class and provides specific
 * implementations for starting the engine and operating the truck to
 * collect harvested crops.
 */
class DeliveryTruck : public Truck {
public:
    /**
     * @brief Starts the engine of the delivery truck.
     * 
     * This method overrides the base class method to provide a specific
     * message indicating that the delivery truck's engine has started.
     */
    void startEngine() override {
        std::cout << "Delivery truck engine started.\n";
    }

    /**
     * @brief Operates the delivery truck to collect harvested crops.
     * 
     * This method overrides the base class method to provide specific
     * functionality for the delivery truck, which involves collecting
     * harvested crops.
     */
    void operate() override {
        std::cout << "Collecting harvested crops...\n";
    }
};

#endif // DELIVERYTRUCK_H
