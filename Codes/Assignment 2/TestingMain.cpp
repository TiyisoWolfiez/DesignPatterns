#include <iostream>
#include "RiverbankFactory.h"
#include "TacticalCommand.h"
#include "Flanking.h"
#include "Fortification.h"
#include "Ambush.h"
#include "Legion.h"
#include "RiverbankUnits.h"
#include "WoodlandUnits.h"
#include "OpenFieldUnits.h"
#include "Infantry.h" 
#include "Cavalry.h"   
#include "Artillery.h" 

void testRiverbankFactory() {
    LegionFactory* factory = new RiverbankFactory();

    UnitComponent* infantry = factory->createInfantry();
    UnitComponent* cavalry = factory->createCavalry();
    UnitComponent* artillery = factory->createArtillery();

    std::cout << "Testing Riverbank Infantry:" << std::endl;
    infantry->move();
    infantry->attack();

    std::cout << "Testing Riverbank Cavalry:" << std::endl;
    cavalry->move();
    cavalry->attack();

    std::cout << "Testing Riverbank Artillery:" << std::endl;
    artillery->move();
    artillery->attack();

    delete infantry;
    delete cavalry;
    delete artillery;
    delete factory;
}

void testStrategyPattern() {
    TacticalCommand command;

    BattleStrategy* flanking = new Flanking();
    BattleStrategy* fortification = new Fortification();
    BattleStrategy* ambush = new Ambush();

    std::cout << "Testing Flanking Strategy:" << std::endl;
    command.setStrategy(flanking);
    command.executeStrategy();
    command.saveCurrentStrategy("Flanking");

    std::cout << "Testing Fortification Strategy:" << std::endl;
    command.setStrategy(fortification);
    command.executeStrategy();
    command.saveCurrentStrategy("Fortification");

    std::cout << "Testing Ambush Strategy:" << std::endl;
    command.setStrategy(ambush);
    command.executeStrategy();
    command.saveCurrentStrategy("Ambush");

    std::cout << "Restoring Flanking Strategy:" << std::endl;
    command.restoreStrategy("Flanking");
    command.executeStrategy();

    delete flanking;
    delete fortification;
    delete ambush;
}

void testCompositePattern() {
    Legion* mainLegion = new Legion();

    UnitComponent* infantry1 = new RiverbankInfantry();
    UnitComponent* cavalry1 = new RiverbankCavalry();
    UnitComponent* artillery1 = new RiverbankArtillery();

    mainLegion->add(infantry1);
    mainLegion->add(cavalry1);
    mainLegion->add(artillery1);

    Legion* subLegion = new Legion();
    UnitComponent* infantry2 = new RiverbankInfantry();
    UnitComponent* cavalry2 = new RiverbankCavalry();

    subLegion->add(infantry2);
    subLegion->add(cavalry2);

    mainLegion->add(subLegion);

    std::cout << "Testing Composite Pattern:" << std::endl;
    mainLegion->move();
    mainLegion->attack();

    delete mainLegion;
}

int main() {
    std::cout << "Testing Riverbank Factory:" << std::endl;
    testRiverbankFactory();

    std::cout << "\nTesting Strategy Pattern:" << std::endl;
    testStrategyPattern();

    std::cout << "\nTesting Composite Pattern:" << std::endl;
    testCompositePattern();

    return 0;
}
