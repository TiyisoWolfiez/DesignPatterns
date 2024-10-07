#include "MotionSensor.h"

#include "Sensor.h"
#include "SmartDevice.h"
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>

void MotionSensor::addDevice(SmartDevice* device) {
    devices.push_back(device);
    deviceStatuses[device] = "Inactive"; // Set initial status
}

void MotionSensor::removeDevice(SmartDevice* device) {
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
    deviceStatuses.erase(device); // Remove status entry
}

void MotionSensor::notifyDevices() const {
    for (SmartDevice* device : devices) {
        device->performAction(); // Notify devices to perform their action
    }
}

void MotionSensor::detectMovement(){
        std::cout << "Motion detected by sensor!" << std::endl;
        notifyDevices(); // Notify all devices

        // Update the status for each device after action
        for (SmartDevice* device : devices) {
            deviceStatuses.at(device) = device->getStatus(); // Update status based on device action
        }
    }

    // Optional: Get status of a specific device
    std::string MotionSensor::getDeviceStatus(SmartDevice* device) const {
        return deviceStatuses.at(device);
    }
