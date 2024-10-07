#include "SmartHome.h"
#include "Light.h"
#include "Thermostat.h"
#include "DoorLock.h"
#include "LegacyThermostat.h"
#include "SmartThermostatIntegrator.h"
#include "TurnOffAllLights.h"
#include "LockAllDoors.h"
#include "MacroRoutine.h"
#include "MotionSensor.h" // Updated to use MotionSensor

int main() {
    SmartHome smartHome;

    // Creating the Living Room with devices
    Room* livingRoom = new Room("Living Room");
    Light* livingRoomLight = new Light();
    DoorLock* livingRoomLock = new DoorLock();
    livingRoom->addDevice(livingRoomLight);
    livingRoom->addDevice(livingRoomLock);

    // Creating the Bedroom with devices
    Room* bedroom = new Room("Bedroom");
    Thermostat* bedroomThermostat = new Thermostat(22);
    bedroom->addDevice(bedroomThermostat);

    // Create a legacy thermostat and adapt it to the smart system using SmartThermostatIntegrator
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

    // Create commands for turning off lights and locking doors
    TurnOffAllLights turnOffLights(&smartHome);
    LockAllDoors lockDoors(&smartHome);

    // Create a MacroRoutine for "Goodnight"
    MacroRoutine goodnightRoutine;
    goodnightRoutine.addProcedure(&turnOffLights);
    goodnightRoutine.addProcedure(&lockDoors);

    // Execute the macro routine
    goodnightRoutine.execute();

    // ----- MotionSensor Integration -----

    // Create a MotionSensor and add the living room light and door lock to it
    MotionSensor* motionSensor = new MotionSensor();
    motionSensor->addDevice(livingRoomLight); // Add living room light to the sensor
    motionSensor->addDevice(livingRoomLock);  // Add living room door lock to the sensor

    // Simulate motion detection
    motionSensor->detectMovement(); // This will notify the light and door lock to perform their actions

    // Check the status of the devices after motion is detected
    std::cout << "Status after motion detection:" << std::endl;
    smartHome.showStatus();

    // Clean up dynamically allocated memory
    delete smartLegacyThermostat; // Clean up smartLegacyThermostat
    delete oldThermostat;         // Clean up legacy thermostat
    delete motionSensor;          // Clean up motion sensor

    return 0;
}
