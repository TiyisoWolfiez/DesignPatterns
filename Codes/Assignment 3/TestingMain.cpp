// TestingMain.cpp
#include <iostream>
#include "Farm.h"
#include "CropField.h"
#include "Barn.h"
#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"

int main() {
    // Create concrete soil states
    DrySoil* drySoil = new DrySoil();
    FruitfulSoil* fruitfulSoil = new FruitfulSoil();
    FloodedSoil* floodedSoil = new FloodedSoil();

    // Create crop fields with specific crops and capacities
    CropField* wheatField = new CropField("Wheat", 1000);
    CropField* cornField = new CropField("Corn", 800);

    // Set initial soil states for the crop fields
    wheatField->setSoilState(fruitfulSoil);  // Initially fruitful soil for wheat
    cornField->setSoilState(drySoil);        // Initially dry soil for corn

    // Create a barn with a specific capacity
    Barn* mainBarn = new Barn(2000);

    // Create a farm and add crop fields and barn to it (Composite Pattern)
    Farm* myFarm = new Farm();
    myFarm->add(wheatField);
    myFarm->add(cornField);
    myFarm->add(mainBarn);

    // Test the getTotalCapacity() function for the farm
    std::cout << "Total Farm Capacity: " << myFarm->getTotalCapacity() << std::endl;

    // Test getting crop types and soil states
    std::cout << "Wheat Field - Crop: " << wheatField->getCropType() << ", Soil: " << wheatField->getSoilStateName() << std::endl;
    std::cout << "Corn Field - Crop: " << cornField->getCropType() << ", Soil: " << cornField->getSoilStateName() << std::endl;

    // Simulate rain on wheat field and corn field
    std::cout << "Simulating rain on wheat field...\n";
    wheatField->rain();
    std::cout << "After rain, Wheat Field Soil State: " << wheatField->getSoilStateName() << std::endl;

    std::cout << "Simulating rain on corn field...\n";
    cornField->rain();
    std::cout << "After rain, Corn Field Soil State: " << cornField->getSoilStateName() << std::endl;

    // Test harvesting crops
    std::cout << "Harvesting crops from wheat field...\n";
    wheatField->harvest();
    std::cout << "Harvesting crops from corn field...\n";
    cornField->harvest();

    // Test getting barn capacity
    std::cout << "Main Barn Capacity: " << mainBarn->getTotalCapacity() << std::endl;

    // Clean up
    delete drySoil;
    delete fruitfulSoil;
    delete floodedSoil;
    delete wheatField;
    delete cornField;
    delete mainBarn;
    delete myFarm;

    return 0;
}
