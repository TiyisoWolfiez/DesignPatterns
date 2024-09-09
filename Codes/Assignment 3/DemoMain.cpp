#include <iostream>
#include "Farm.h"
#include "CropField.h"
#include "Barn.h"
#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include "FertilizerTruck.h"
#include "DeliveryTruck.h"
#include "BFSTraversal.h"
#include "DFSTraversal.h"

// Function to test the Composite Pattern
void testCompositePattern(Farm* myFarm, CropField* wheatField, CropField* cornField, Barn* mainBarn) {
    std::cout << "Composite Pattern Testing:\n";
    std::cout<< "\n";

    // Create a farm and add crop fields and barn to it
    myFarm->add(wheatField);
    myFarm->add(cornField);
    myFarm->add(mainBarn);

    // Test the getTotalCapacity() function for the farm
    std::cout << "Total Farm Capacity: " << myFarm->getTotalCapacity() << std::endl;

    // Clean up (delete farm components)
    // delete myFarm;
    // delete wheatField;
    // delete cornField;
    // delete mainBarn;
}

// Function to test the State Pattern
void testStatePattern(CropField* wheatField, CropField* cornField, DrySoil* drySoil, FruitfulSoil* fruitfulSoil) {
    std::cout << "State Pattern Testing:\n";
    std::cout<< "\n";

    // Set initial soil states for the crop fields
    wheatField->setSoilState(fruitfulSoil);  // Initially fruitful soil for wheat
    cornField->setSoilState(drySoil);        // Initially dry soil for corn

    // Simulate rain on wheat field and corn field
    std::cout << "Simulating rain on wheat field...\n";
    wheatField->rain();
    std::cout << "After rain, Wheat Field Soil State: " << wheatField->getSoilStateName() << std::endl;

    std::cout << "Simulating rain on corn field...\n";
    cornField->rain();
    std::cout << "After rain, Corn Field Soil State: " << cornField->getSoilStateName() << std::endl;
}

// Function to test the Strategy Pattern
void testStrategyPattern(Farm* myFarm) {
    std::cout << "Strategy Pattern Testing:\n";
    std::cout<< "\n";

    // Breadth-First Traversal
    std::cout << "Breadth-First Traversal:\n";
    BFSTraversal bfs(myFarm);
    bfs.firstFarm();
    while (!bfs.isDone()) {
        FarmUnit* current = bfs.currentFarm();
        std::cout << "BFS - Current Farm: " 
                  << "Crop Type: " << current->getCropType() << " | " 
                  << "Soil State: " << current->getSoilStateName() << " | " 
                  << "Total Capacity: " << current->getTotalCapacity() 
                  << std::endl;
        bfs.next();
    }

    // Depth-First Traversal
    std::cout << "Depth-First Traversal:\n";
    DFSTraversal dfs(myFarm);
    dfs.firstFarm();
    while (!dfs.isDone()) {
        FarmUnit* current = dfs.currentFarm();
        std::cout << "DFS - Current Farm: " 
                  << "Crop Type: " << current->getCropType() << " | " 
                  << "Soil State: " << current->getSoilStateName() << " | " 
                  << "Total Capacity: " << current->getTotalCapacity() 
                  << std::endl;
        dfs.next();
    }
}

int main() {
    // Create concrete soil states
    DrySoil* drySoil = new DrySoil();
    FruitfulSoil* fruitfulSoil = new FruitfulSoil();
    FloodedSoil* floodedSoil = new FloodedSoil();

    // Create crop fields with specific crops and capacities
    CropField* wheatField = new CropField("Wheat", 1000);
    CropField* cornField = new CropField("Corn", 800);

    // Create trucks
    FertilizerTruck* fertTruck1 = new FertilizerTruck();
    FertilizerTruck* fertTruck2 = new FertilizerTruck(); // Additional truck
    DeliveryTruck* delTruck1 = new DeliveryTruck();
    DeliveryTruck* delTruck2 = new DeliveryTruck(); // Additional truck

    // Set trucks to crop fields
    wheatField->addFertilizerTruck(fertTruck1);
    wheatField->addDeliveryTruck(delTruck1);
    cornField->addFertilizerTruck(fertTruck2);
    cornField->addDeliveryTruck(delTruck2);

    // Create a barn with a specific capacity
    Barn* mainBarn = new Barn(2000);

    // Create a farm
    Farm* myFarm = new Farm();

    // Test Composite Pattern
    testCompositePattern(myFarm, wheatField, cornField, mainBarn);

    // Test State Pattern
    testStatePattern(wheatField, cornField, drySoil, fruitfulSoil);

    // Test Strategy Pattern
    testStrategyPattern(myFarm);

    // Test buying and selling trucks
    std::cout << "Buying additional trucks...\n";
    myFarm->buyTruck(fertTruck1);
    myFarm->buyTruck(delTruck1);
    std::cout << "Trucks bought and added to the farm.\n";

    std::cout << "Selling one Fertilizer Truck...\n";
    myFarm->sellTruck(fertTruck1);
    std::cout << "One Fertilizer Truck sold.\n";

    std::cout << "Calling remaining trucks...\n";
    myFarm->callTruck();
    std::cout << "Trucks dispatched for their operations.\n";

    // Clean up
    // delete drySoil;
    // delete fruitfulSoil;
    // delete floodedSoil;
    // delete wheatField;
    // delete cornField;
    // delete mainBarn;
    // delete myFarm;
    // delete fertTruck1;  // This will be deleted after being sold
    // delete fertTruck2;
    // delete delTruck1;  // This will be deleted after being sold
    // delete delTruck2;

    return 0;
}
