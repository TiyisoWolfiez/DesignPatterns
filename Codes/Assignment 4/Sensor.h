#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "SmartDevice.h"

class Sensor {//subject 
private:
    std::vector<SmartDevice*> devices;

public:
    virtual  void addDevice(SmartDevice* device) =0;
    virtual void removeDevice(SmartDevice* device)=0;
    virtual void notifyDevices() const =0;
    virtual void detectMovement() = 0; // Simulated method to detect movement
    virtual std::string getDeviceStatus(SmartDevice* device) const =0;
    virtual ~Sensor() = default;

};

#endif // SENSOR_H
