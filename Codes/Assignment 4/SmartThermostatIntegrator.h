#ifndef SMART_THERMOSTAT_INTEGRATOR_H
#define SMART_THERMOSTAT_INTEGRATOR_H

#include "SmartDevice.h"
#include "LegacyThermostat.h"
#include <string>

class SmartThermostatIntegrator : public SmartDevice {
public:
    SmartThermostatIntegrator(LegacyThermostat* oldThermostat);

    void performAction() override;

    std::string getStatus() const override;

    std::string getDeviceType() const override;

    void setTemperature(int temp);

    int getTemperature() const;

private:
    LegacyThermostat* legacyThermostat;  // Pointer to the old thermostat
};

#endif // SMART_THERMOSTAT_INTEGRATOR_H
