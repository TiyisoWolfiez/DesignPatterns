// FarmUnit.h
#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <string>

// Abstract Component
class FarmUnit {
public:
    virtual int getTotalCapacity() const = 0;  // Pure virtual function to get total capacity
    virtual std::string getCropType() const = 0;  // Pure virtual function to get crop type
    virtual std::string getSoilStateName() const = 0;  // Pure virtual function to get soil state name

    virtual void add(FarmUnit* unit) {}  // Virtual function to add a FarmUnit (Composite role)
    virtual void remove(FarmUnit* unit) {}  // Virtual function to remove a FarmUnit (Composite role)
    virtual FarmUnit* getChild(int index) { return nullptr; }  // Virtual function to get a child unit (Composite role)

    virtual ~FarmUnit() {}  // Virtual destructor
};

#endif // FARMUNIT_H
