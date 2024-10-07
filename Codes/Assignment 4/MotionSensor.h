#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include <vector>
#include <map>

#include "Sensor.h"
#include "SmartDevice.h"


class MotionSensor:public Sensor {//subject 
private:
    //std::vector<SmartDevice*> devices;
 private:
    std::vector<SmartDevice*> devices; 
    std::map<SmartDevice*, std::string> deviceStatuses;

public:
    void addDevice(SmartDevice* device) override;
    void removeDevice(SmartDevice* device) override;
    void notifyDevices() const override;
    void detectMovement() override; // Simulated method to detect movement
    std::string getDeviceStatus(SmartDevice* device) const override;
    ~MotionSensor() override = default;

};

#endif // SENSOR_H
