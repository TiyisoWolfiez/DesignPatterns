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

    // Traversal Testing
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
