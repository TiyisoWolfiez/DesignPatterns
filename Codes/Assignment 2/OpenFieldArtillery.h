#ifndef OPENFIELDARTILLERY_H
#define OPENFIELDARTILLERY_H

#include "Artillery.h"

class OpenFieldArtillery : public Artillery {
public:
    void move() override {
        // Implementation specific to Open Field Artillery movement
    }
    
    void attack() override {
        // Implementation specific to Open Field Artillery attack
    }
};

#endif // OPENFIELDARTILLERY_H
