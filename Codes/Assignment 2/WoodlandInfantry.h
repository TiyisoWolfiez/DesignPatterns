#ifndef WOODLANDINFANTRY_H
#define WOODLANDINFANTRY_H

#include "Infantry.h"

class WoodlandInfantry : public Infantry {
public:
    void move() override {
        // Implementation specific to Woodland Infantry movement
    }
    
    void attack() override {
        // Implementation specific to Woodland Infantry attack
    }
};

#endif // WOODLANDINFANTRY_H
