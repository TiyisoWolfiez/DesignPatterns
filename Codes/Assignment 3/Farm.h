// Farm.h
#ifndef FARM_H
#define FARM_H

#include "FarmUnit.h"
#include <vector>
#include <algorithm>

// Composite Class
class Farm : public FarmUnit {
private:
    std::vector<FarmUnit*> units;  // Vector to store child FarmUnit objects

public:
    void add(FarmUnit* unit) override {
        units.push_back(unit);
    }
    
    void remove(FarmUnit* unit) override {
        units.erase(std::remove(units.begin(), units.end(), unit), units.end());
    }
    
    FarmUnit* getChild(int index) override {
        if (index < units.size()) {
            return units[index];
        }
        return nullptr;
    }
    
    int getTotalCapacity() const override {
        int totalCapacity = 0;
        for (const auto& unit : units) {
            totalCapacity += unit->getTotalCapacity();
        }
        return totalCapacity;
    }
    
    std::string getCropType() const override {
        return "Mixed";  // As it is a composite of multiple crop fields.
    }

    std::string getSoilStateName() const override {
        return "Mixed";  // Composite farms may have different soil states.
    }
};

#endif // FARM_H
