#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "SmartDevice.h"

class Sensor {
private:
    std::vector<SmartDevice*> devices;

public:
    void addDevice(SmartDevice* device);
    void removeDevice(SmartDevice* device);
    void notifyDevices() const;
    void detectMovement(); // Simulated method to detect movement
};

#endif // SENSOR_H
