#ifndef WOODLANDCAVALRY_H
#define WOODLANDCAVALRY_H

#include "Cavalry.h"

class WoodlandCavalry : public Cavalry {
public:
    void move() override {
        // Implementation specific to Woodland Cavalry movement
    }
    
    void attack() override {
        // Implementation specific to Woodland Cavalry attack
    }
};

#endif // WOODLANDCAVALRY_H
