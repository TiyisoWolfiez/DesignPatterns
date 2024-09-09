#ifndef EXTRABARNDECORATOR_H
#define EXTRABARNDECORATOR_H

#include "CropField.h"
#include "Barn.h"

// Decorator for adding an extra barn to enhance storage capacity
class ExtraBarnDecorator : public CropField {
private:
    CropField* cropField;
    Barn* extraBarn;

public:
    ExtraBarnDecorator(CropField* cropField, int additionalCapacity) 
        : CropField(cropField->getCropType(), cropField->getTotalCapacity() + additionalCapacity),
          cropField(cropField) {
        // Create an extra barn and add its capacity
        extraBarn = new Barn(additionalCapacity);
    }

    ~ExtraBarnDecorator() {
        delete cropField; // Clean up original crop field
        delete extraBarn; // Clean up extra barn
    }

    int getTotalCapacity() const override {
        return CropField::getTotalCapacity(); // Return enhanced capacity
    }

    std::string getCropType() const override {
        return cropField->getCropType();
    }

    std::string getSoilStateName() const override {
        return cropField->getSoilStateName();
    }

    void harvest() {
        cropField->harvest(); // Delegate to the original crop field
    }

    void rain() {
        cropField->rain(); // Delegate to the original crop field
    }

    int getLeftoverCapacity() const {
        return extraBarn->getTotalCapacity();
    }
};

#endif // EXTRABARNDECORATOR_H
