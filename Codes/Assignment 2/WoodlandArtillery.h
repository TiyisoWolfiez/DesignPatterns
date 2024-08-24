#ifndef WOODLANDARTILLERY_H
#define WOODLANDARTILLERY_H

#include "Artillery.h"

class WoodlandArtillery : public Artillery {
public:
    void move() override {
        // Implementation specific to Woodland Artillery movement
    }
    
    void attack() override {
        // Implementation specific to Woodland Artillery attack
    }
};

#endif // WOODLANDARTILLERY_H
