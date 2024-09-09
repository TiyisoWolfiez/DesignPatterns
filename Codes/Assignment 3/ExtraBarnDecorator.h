#ifndef EXTRABARNDECORATOR_H
#define EXTRABARNDECORATOR_H

#include "CropField.h"
#include "Barn.h"

/**
 * @class ExtraBarnDecorator
 * @brief A decorator for adding additional storage capacity to a crop field.
 * 
 * This class extends the functionality of a `CropField` by adding an extra 
 * barn to enhance its storage capacity. It delegates operations to the 
 * original crop field while providing additional methods to manage the 
 * extra storage.
 */
class ExtraBarnDecorator : public CropField {
private:
    CropField* cropField; ///< The original crop field being decorated
    Barn* extraBarn; ///< Additional barn to enhance storage capacity

public:
    /**
     * @brief Constructs an `ExtraBarnDecorator` with the specified crop field and additional capacity.
     * 
     * This constructor creates a new barn with additional storage capacity and
     * wraps the given crop field to provide enhanced functionality.
     * 
     * @param cropField The crop field to be decorated.
     * @param additionalCapacity The additional capacity provided by the extra barn.
     */
    ExtraBarnDecorator(CropField* cropField, int additionalCapacity) 
        : CropField(cropField->getCropType(), cropField->getTotalCapacity() + additionalCapacity),
          cropField(cropField) {
        // Create an extra barn and add its capacity
        extraBarn = new Barn(additionalCapacity);
    }

    /**
     * @brief Destructor for cleaning up the extra barn and the original crop field.
     */
    ~ExtraBarnDecorator() {
        delete cropField; // Clean up original crop field
        delete extraBarn; // Clean up extra barn
    }

    /**
     * @brief Gets the total capacity of the crop field including the extra barn.
     * 
     * @return The total enhanced capacity of the crop field.
     */
    int getTotalCapacity() const override {
        return CropField::getTotalCapacity(); // Return enhanced capacity
    }

    /**
     * @brief Gets the crop type of the original crop field.
     * 
     * @return The crop type as a string.
     */
    std::string getCropType() const override {
        return cropField->getCropType();
    }

    /**
     * @brief Gets the soil state name of the original crop field.
     * 
     * @return The soil state name as a string.
     */
    std::string getSoilStateName() const override {
        return cropField->getSoilStateName();
    }

    /**
     * @brief Delegates the harvest operation to the original crop field.
     */
    void harvest() {
        cropField->harvest(); // Delegate to the original crop field
    }

    /**
     * @brief Delegates the rain operation to the original crop field.
     */
    void rain() {
        cropField->rain(); // Delegate to the original crop field
    }

    /**
     * @brief Gets the leftover capacity provided by the extra barn.
     * 
     * @return The additional capacity of the extra barn.
     */
    int getLeftoverCapacity() const {
        return extraBarn->getTotalCapacity();
    }
};

#endif // EXTRABARNDECORATOR_H