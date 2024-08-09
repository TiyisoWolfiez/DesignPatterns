#include <iostream>
#include <vector>
#include "InfantryFactory.h"
#include "ShieldBearerFactory.h"
#include "BoatmanFactory.h"
#include "CareTaker.h"

int main() {
    std::vector<SoldierFactory*> factories;
    factories.push_back(new InfantryFactory());
    factories.push_back(new ShieldBearerFactory());
    factories.push_back(new BoatmanFactory());

    CareTaker careTaker;

    for (auto factory : factories) {
        Soldiers* unit = factory->createUnit();
        std::cout << "Unit: " << unit->getUnitName() << std::endl;
        std::cout << "Total Health: " << factory->calculateTotalHealthPerUnit() << std::endl;
        std::cout << "Total Damage: " << factory->calculateTotalDamagePerUnit() << std::endl;
        std::cout << "Total Defence: " << factory->calculateTotalDefencePerUnit() << std::endl;

        // Engage the unit in battle
        std::cout << "\nEngaging the unit:\n";
        unit->engage();

        // Save the state after engagement
        std::cout << "\nSaving state after engagement...\n";
        careTaker.addMemento(unit->militusMemento());

        // Modify the state and save it again
        unit->setHealthPerSoldier(unit->getHealthPerSoldier() + 50); // Example modification
        unit->setAmountOfSoldiersPerUnit(unit->getAmountOfSoldiersPerUnit() - 2);
        std::cout << "\nSaving state after modification...\n";
        careTaker.addMemento(unit->militusMemento());

        // Further modify the state
        unit->setDamagePerSoldier(unit->getDamagePerSoldier() + 10);
        unit->setDefencePerSoldier(unit->getDefencePerSoldier() - 5);
        std::cout << "\nFurther modifying state...\n";
        careTaker.addMemento(unit->militusMemento());

        // Disengage the unit from battle
        std::cout << "\nDisengaging the unit:\n";
        unit->disengage();

        // Restore the initial state (first memento)
        std::cout << "\nRestoring to initial state...\n";
        unit->vivificaMemento(careTaker.getMemento(0));
        std::cout << "Restored Unit: " << unit->getUnitName() << std::endl;
        std::cout << "Restored Total Health: " << factory->calculateTotalHealthPerUnit() << std::endl;

        // Engage the unit again after restoration
        std::cout << "\nRe-engaging the restored unit:\n";
        unit->engage();

        // Restore to the second saved state
        std::cout << "\nRestoring to second saved state...\n";
        unit->vivificaMemento(careTaker.getMemento(1));
        std::cout << "Restored Unit (Second State): " << unit->getUnitName() << std::endl;
        std::cout << "Restored Total Health: " << factory->calculateTotalHealthPerUnit() << std::endl;

        // Engage the unit again after the second restoration
        std::cout << "\nRe-engaging the unit after second restoration:\n";
        unit->engage();

        // Restore to the most recent saved state (third memento)
        std::cout << "\nRestoring to most recent saved state...\n";
        unit->vivificaMemento(careTaker.getMemento(2));
        std::cout << "Restored Unit (Most Recent State): " << unit->getUnitName() << std::endl;
        std::cout << "Restored Total Health: " << factory->calculateTotalHealthPerUnit() << std::endl;

        // Engage the unit again after the third restoration
        std::cout << "\nRe-engaging the unit after most recent restoration:\n";
        unit->engage();

        // Demonstrating the Prototype pattern
        Soldiers* clonedUnit = unit->clonis(); // Cloning the unit
        std::cout << "\nCloned Unit: " << clonedUnit->getUnitName() << std::endl;
        std::cout << "Total Health: " << factory->calculateTotalHealthPerUnit() << std::endl;
        std::cout << "Total Damage: " << factory->calculateTotalDamagePerUnit() << std::endl;
        std::cout << "Total Defence: " << factory->calculateTotalDefencePerUnit() << std::endl;

        delete clonedUnit;
        delete unit;
    }
    return 0;
}
