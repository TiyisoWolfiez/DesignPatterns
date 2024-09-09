#ifndef DELIVERYTRUCK_H
#define DELIVERYTRUCK_H

#include "Truck.h"
#include <iostream>

class DeliveryTruck : public Truck {
public:
    void startEngine() override {
        std::cout << "Delivery truck engine started.\n";
    }

    void operate() override {
        std::cout << "Collecting harvested crops...\n";
    }
};

#endif // DELIVERYTRUCK_H
