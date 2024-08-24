#ifndef OPENFIELDCAVALRY_H
#define OPENFIELDCAVALRY_H

#include "Cavalry.h"

class OpenFieldCavalry : public Cavalry {
public:
    void move() override {
        // Implementation specific to Open Field Cavalry movement
    }
    
    void attack() override {
        // Implementation specific to Open Field Cavalry attack
    }
};

#endif // OPENFIELDCAVALRY_H
