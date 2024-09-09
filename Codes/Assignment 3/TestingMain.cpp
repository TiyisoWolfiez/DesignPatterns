#include <iostream>
#include "Farm.h"
#include "CropField.h"
#include "Barn.h"
#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include "FertilizerDecorator.h"
#include "ExtraBarnDecorator.h"

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

    // Apply fertilizer to the corn field
    CropField* fertilizedCornField = new FertilizerDecorator(cornField);
    
    // Add an extra barn to the wheat field
    CropField* enhancedWheatField = new ExtraBarnDecorator(wheatField, 500);

    // Test the getTotalCapacity() function for the enhanced wheat field
    std::cout << "Enhanced Wheat Field Capacity: " << enhancedWheatField->getTotalCapacity() << std::endl;

    // Test the leftover capacity after adding the extra barn
    std::cout << "Leftover Capacity in Extra Barn: " << dynamic_cast<ExtraBarnDecorator*>(enhancedWheatField)->getLeftoverCapacity() << std::endl;

    // Simulate rain on fertilized corn field and harvest
    std::cout << "Simulating rain on fertilized corn field...\n";
    fertilizedCornField->rain();
    std::cout << "After rain, Fertilized Corn Field Soil State: " << fertilizedCornField->getSoilStateName() << std::endl;
    std::cout << "Harvesting crops from fertilized corn field...\n";
    fertilizedCornField->harvest();

    // Test harvesting crops from enhanced wheat field
    std::cout << "Harvesting crops from enhanced wheat field...\n";
    enhancedWheatField->harvest();

    // Clean up
    // delete drySoil;
    // delete fruitfulSoil;
    // delete floodedSoil;
    // delete fertilizedCornField;
    // delete enhancedWheatField;
    // delete myFarm;

    return 0;
}
