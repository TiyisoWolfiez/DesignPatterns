#include "Sensor.h"
#include <algorithm>
#include <iostream>

void Sensor::addDevice(SmartDevice* device) {
    devices.push_back(device);
}

void Sensor::removeDevice(SmartDevice* device) {
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}

void Sensor::notifyDevices() const {
    for (SmartDevice* device : devices) {
        device->performAction(); // Notify devices to perform their action
    }
}

void Sensor::detectMovement() {
    // Simulating movement detection
    std::cout << "Movement detected!" << std::endl;
    notifyDevices(); // Notify all registered devices
}
