#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H

#include "Truck.h"
#include <iostream>

class FertilizerTruck : public Truck {
public:
    void startEngine() override {
        std::cout << "Fertilizer truck engine started.\n";
    }

    void operate() override {
        std::cout << "Delivering fertilizer to the crop field...\n";
    }
};

#endif // FERTILIZERTRUCK_H
