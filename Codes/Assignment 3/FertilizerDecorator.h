#ifndef FERTILIZERDECORATOR_H
#define FERTILIZERDECORATOR_H

#include "CropField.h"
#include "FruitfulSoil.h"

/**
 * @class FertilizerDecorator
 * @brief Decorator class for applying fertilizer to a CropField.
 * 
 * This class is a decorator that enhances a CropField by applying fertilizer.
 * It sets the soil state to FruitfulSoil when the decorator is initialized.
 */
class FertilizerDecorator : public CropField {
private:
    CropField* cropField; ///< Original CropField being decorated

public:
    /**
     * @brief Constructor for FertilizerDecorator.
     * 
     * Initializes the FertilizerDecorator by wrapping an existing CropField.
     * Sets the soil state to FruitfulSoil.
     * 
     * @param cropField Pointer to the CropField to be decorated.
     */
    FertilizerDecorator(CropField* cropField) 
        : CropField(cropField->getCropType(), cropField->getTotalCapacity()), cropField(cropField) {
        // Set the soil state to FruitfulSoil when fertilizer is applied
        this->setSoilState(new FruitfulSoil());
    }

    /**
     * @brief Destructor for FertilizerDecorator.
     * 
     * Cleans up the original CropField.
     */
    ~FertilizerDecorator() {
        delete cropField; // Clean up original crop field
    }

    /**
     * @brief Gets the total capacity of the decorated CropField.
     * 
     * @return The total capacity of the original CropField.
     */
    int getTotalCapacity() const override {
        return cropField->getTotalCapacity();
    }

    /**
     * @brief Gets the crop type of the decorated CropField.
     * 
     * @return The crop type of the original CropField.
     */
    std::string getCropType() const override {
        return cropField->getCropType();
    }

    /**
     * @brief Gets the name of the soil state of the decorated CropField.
     * 
     * @return The name of the soil state after applying fertilizer (FruitfulSoil).
     */
    std::string getSoilStateName() const override {
        return cropField->getSoilStateName();
    }

    /**
     * @brief Delegates the harvest operation to the original CropField.
     * 
     * Calls the harvest method on the original CropField.
     */
    void harvest() {
        cropField->harvest(); // Delegate to the original crop field
    }

    /**
     * @brief Delegates the rain operation to the original CropField.
     * 
     * Calls the rain method on the original CropField.
     */
    void rain() {
        cropField->rain(); // Delegate to the original crop field
    }
};

#endif // FERTILIZERDECORATOR_H