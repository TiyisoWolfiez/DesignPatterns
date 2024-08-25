#ifndef RIVERBANKINFANTRY_H
#define RIVERBANKINFANTRY_H

#include "Infantry.h"

class RiverbankInfantry : public Infantry {
public:
    void move() override {
        // Implementation specific to Riverbank Infantry movement
    }
    
    void attack() override {
        // Implementation specific to Riverbank Infantry attack
    }
};

#endif // RIVERBANKINFANTRY_H
