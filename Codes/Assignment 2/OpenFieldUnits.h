#ifndef OPENFIELDUNITS_H
#define OPENFIELDUNITS_H

#include "UnitComponent.h"
#include <iostream>

class OpenFieldInfantry : public UnitComponent {
public:
    void move() override {
        std::cout << "OpenField Infantry moving through the open field." << std::endl;
    }
    void attack() override {
        std::cout << "OpenField Infantry attacking from the open field." << std::endl;
    }
};

class OpenFieldCavalry : public UnitComponent {
public:
    void move() override {
        std::cout << "OpenField Cavalry moving swiftly through the open field." << std::endl;
    }
    void attack() override {
        std::cout << "OpenField Cavalry charging through the open field." << std::endl;
    }
};

class OpenFieldArtillery : public UnitComponent {
public:
    void move() override {
        std::cout << "OpenField Artillery positioning in the open field." << std::endl;
    }
    void attack() override {
        std::cout << "OpenField Artillery firing from the open field." << std::endl;
    }
};

#endif // OPENFIELDUNITS_H
