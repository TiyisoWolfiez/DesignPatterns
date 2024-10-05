#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice {
private:
    int temperature;

public:
    Thermostat(int initialTemperature);

    std::string getStatus() const override;
    void performAction() override;
    std::string getDeviceType() const override;
};

#endif // THERMOSTAT_H
