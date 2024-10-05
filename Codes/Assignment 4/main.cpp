#include "SmartHome.h"
#include "Light.h"
#include "Thermostat.h"
#include "DoorLock.h"
#include "LegacyThermostat.h"
#include "SmartThermostatIntegrator.h"
#include "TurnOffAllLights.h"
#include "LockAllDoors.h"
#include "MacroRoutine.h"
#include "Sensor.h"

int main() {
    SmartHome smartHome;

    // Creating the Living Room with devices
    Room* livingRoom = new Room("Living Room");
    Light* light = new Light();
    livingRoom->addDevice(light);
    livingRoom->addDevice(new DoorLock());

    // Creating the Bedroom with devices
    Room* bedroom = new Room("Bedroom");
    bedroom->addDevice(new Thermostat(22));

    // Create a legacy thermostat and adapt it to the smart system using the SmartThermostatIntegrator
    LegacyThermostat* oldThermostat = new LegacyThermostat(20);
    SmartThermostatIntegrator* smartLegacyThermostat = new SmartThermostatIntegrator(oldThermostat);

    // Adding the adapted legacy thermostat to the bedroom
    bedroom->addDevice(smartLegacyThermostat);

    // Adding rooms to the smart home
    smartHome.addRoom(livingRoom);
    smartHome.addRoom(bedroom);

    // Show initial status of all devices
    smartHome.showStatus();

    // Perform action (toggle devices)
    smartHome.performActionOnAllDevices();

    // Show status after performing actions
    smartHome.showStatus();

    // Create commands
    TurnOffAllLights turnOffLights(&smartHome);
    LockAllDoors lockDoors(&smartHome);

    // Create a MacroRoutine for "Goodnight"
    MacroRoutine goodnightRoutine;
    goodnightRoutine.addProcedure(&turnOffLights);
    goodnightRoutine.addProcedure(&lockDoors);

    // Execute the macro routine
    goodnightRoutine.execute();

    // Create a sensor and add the light to it
    Sensor* motionSensor = new Sensor();
    motionSensor->addDevice(light); // Adding light to the sensor

    // Simulate movement detection
    motionSensor->detectMovement(); // This will notify the light to perform its action

    // Add cleanup for dynamically allocated devices
    delete smartLegacyThermostat; // Clean up smartLegacyThermostat
    delete oldThermostat; // Clean up legacy thermostat

    return 0;
}
