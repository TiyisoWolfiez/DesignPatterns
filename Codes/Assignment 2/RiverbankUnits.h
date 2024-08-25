#ifndef RIVERBANKUNITS_H
#define RIVERBANKUNITS_H

#include "UnitComponent.h"
#include <iostream>

class RiverbankInfantry : public UnitComponent {
public:
    void move() override {
        std::cout << "Riverbank Infantry moving through the riverbank terrain." << std::endl;
    }
    void attack() override {
        std::cout << "Riverbank Infantry attacking from the riverbank terrain." << std::endl;
    }
};

class RiverbankCavalry : public UnitComponent {
public:
    void move() override {
        std::cout << "Riverbank Cavalry moving swiftly along the riverbank." << std::endl;
    }
    void attack() override {
        std::cout << "Riverbank Cavalry charging from the riverbank." << std::endl;
    }
};

class RiverbankArtillery : public UnitComponent {
public:
    void move() override {
        std::cout << "Riverbank Artillery positioning on the riverbank." << std::endl;
    }
    void attack() override {
        std::cout << "Riverbank Artillery firing from the riverbank." << std::endl;
    }
};

#endif // RIVERBANKUNITS_H
