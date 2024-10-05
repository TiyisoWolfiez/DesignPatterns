#include "Thermostat.h"

Thermostat::Thermostat(int initialTemperature) : temperature(initialTemperature) {}

std::string Thermostat::getStatus() const {
    return "Temperature is set to " + std::to_string(temperature) + "°C";
}

void Thermostat::performAction() {
    temperature++; // Increase temperature by 1
}

std::string Thermostat::getDeviceType() const {
    return "Thermostat";
}
