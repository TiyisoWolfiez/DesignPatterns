#ifndef INFANTRY_H
#define INFANTRY_H

#include "UnitComponent.h"
#include <iostream>

class Infantry : public UnitComponent {
public:
    void move() override {
        std::cout << "Infantry moving." << std::endl;
    }
    void attack() override {
        std::cout << "Infantry fighting." << std::endl;
    }
};

#endif // INFANTRY_H
