// Barn.h
#ifndef BARN_H
#define BARN_H

#include "FarmUnit.h"

// Leaf Class
class Barn : public FarmUnit {
private:
    int capacity;

public:
    Barn(int capacity) : capacity(capacity) {}

    int getTotalCapacity() const override {
        return capacity;
    }

    std::string getCropType() const override {
        return "None";  // Barns don't have a crop type.
    }

    std::string getSoilStateName() const override {
        return "N/A";  // Barns don't have a soil state.
    }
};

#endif // BARN_H
