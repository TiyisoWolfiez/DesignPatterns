#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <string>
#include <vector>
#include <algorithm>
#include "Truck.h"

class FarmUnit {
private:
    std::vector<Truck*> trucks;  // List of trucks associated with this unit

public:
    virtual int getTotalCapacity() const = 0;
    virtual std::string getCropType() const = 0;
    virtual std::string getSoilStateName() const = 0;

    virtual void add(FarmUnit* unit) {}
    virtual void remove(FarmUnit* unit) {}
    virtual FarmUnit* getChild(int index) { return nullptr; }
    virtual int getChildCount() const { return 0; }

    virtual ~FarmUnit() {
        for (auto truck : trucks) {
            delete truck;
        }
    }

    void buyTruck(Truck* truck) {
        trucks.push_back(truck);
    }

    void sellTruck(Truck* truck) {
        auto it = std::find(trucks.begin(), trucks.end(), truck);
        if (it != trucks.end()) {
            delete *it;  // Delete the truck
            trucks.erase(it);  // Remove the truck from the vector
        }
    }

    void callTruck() {
        for (auto truck : trucks) {
            truck->startEngine();
            truck->operate();
        }
    }
};

#endif // FARMUNIT_H
