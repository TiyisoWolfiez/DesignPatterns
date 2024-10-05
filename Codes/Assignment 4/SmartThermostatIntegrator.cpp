#include "SmartThermostatIntegrator.h"
#include <iostream>

SmartThermostatIntegrator::SmartThermostatIntegrator(LegacyThermostat* oldThermostat)
    : legacyThermostat(oldThermostat) {}

void SmartThermostatIntegrator::performAction() {
    // Toggle behavior: increase the temperature by 1 degree
    setTemperature(getTemperature() + 1);
}

std::string SmartThermostatIntegrator::getStatus() const {
    return "Temperature is set to " + std::to_string(getTemperature()) + "°C";
}

std::string SmartThermostatIntegrator::getDeviceType() const {
    return "Legacy Thermostat";
}

void SmartThermostatIntegrator::setTemperature(int temp) {
    legacyThermostat->setLegacyTemp(temp);
}

int SmartThermostatIntegrator::getTemperature() const {
    return legacyThermostat->getLegacyTemp();
}
