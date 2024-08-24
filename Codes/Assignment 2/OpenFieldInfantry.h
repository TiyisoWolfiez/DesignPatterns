#ifndef OPENFIELDINFANTRY_H
#define OPENFIELDINFANTRY_H

#include "Infantry.h"

class OpenFieldInfantry : public Infantry {
public:
    void move() override {
        // Implementation specific to Open Field Infantry movement
    }
    
    void attack() override {
        // Implementation specific to Open Field Infantry attack
    }
};

#endif // OPENFIELDINFANTRY_H
