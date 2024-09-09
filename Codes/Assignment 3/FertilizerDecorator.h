#ifndef FERTILIZERDECORATOR_H
#define FERTILIZERDECORATOR_H

#include "CropField.h"
#include "FruitfulSoil.h"

// Decorator for applying fertilizer
class FertilizerDecorator : public CropField {
private:
    CropField* cropField;  // Original CropField

public:
    FertilizerDecorator(CropField* cropField) 
        : CropField(cropField->getCropType(), cropField->getTotalCapacity()), cropField(cropField) {
        // Set the soil state to FruitfulSoil when fertilizer is applied
        this->setSoilState(new FruitfulSoil());
    }

    ~FertilizerDecorator() {
        delete cropField; // Clean up original crop field
    }

    int getTotalCapacity() const override {
        return cropField->getTotalCapacity();
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
};

#endif // FERTILIZERDECORATOR_H
