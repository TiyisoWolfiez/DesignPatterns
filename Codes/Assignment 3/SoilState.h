// SoilState.h
#ifndef SOILSTATE_H
#define SOILSTATE_H

#include <string>

// Interface for Soil States
class SoilState {
public:
    virtual ~SoilState() = default;

    // Harvest crops based on the soil state; returns the amount harvested
    virtual int harvestCrops(int currentStored) = 0;

    // Simulate rainfall; changes the state of the soil
    virtual void rain() = 0;

    // Get the name of the current soil state
    virtual std::string getName() const = 0;
};

#endif // SOILSTATE_H
