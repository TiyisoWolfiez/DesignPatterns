#ifndef RIVERBANKARTILLERY_H
#define RIVERBANKARTILLERY_H

#include "Artillery.h"

class RiverbankArtillery : public Artillery {
public:
    void move() override {
        // Implementation specific to Riverbank Artillery movement
    }
    
    void attack() override {
        // Implementation specific to Riverbank Artillery attack
    }
};

#endif // RIVERBANKARTILLERY_H
