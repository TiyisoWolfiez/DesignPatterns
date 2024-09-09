#ifndef FARM_H
#define FARM_H

#include <vector>
#include <string>
#include <algorithm>
#include "FarmUnit.h"

class Farm : public FarmUnit {
private:
    std::vector<FarmUnit*> children;

public:
    void add(FarmUnit* unit) override {
        children.push_back(unit);
    }

    void remove(FarmUnit* unit) override {
        auto it = std::remove(children.begin(), children.end(), unit);
        if (it != children.end()) {
            children.erase(it);
        }
    }

    FarmUnit* getChild(int index) override {
        if (index >= 0 && index < children.size()) {
            return children[index];
        }
        return nullptr;
    }

    int getChildCount() const override {
        return children.size();
    }

    int getTotalCapacity() const override {
        int totalCapacity = 0;
        for (auto& child : children) {
            totalCapacity += child->getTotalCapacity();
        }
        return totalCapacity;
    }

    std::string getCropType() const override {
        return "Farm does not have a crop type.";
    }

    std::string getSoilStateName() const override {
        return "Farm does not have a soil state.";
    }

    ~Farm() override {
        for (auto& child : children) {
            delete child;
        }
    }
};

#endif // FARM_H
