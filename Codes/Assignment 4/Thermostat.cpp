#include "Thermostat.h"
#include <iostream>

Thermostat::Thermostat(int initialTemperature) : temperature(initialTemperature) {}

std::string Thermostat::getStatus() const {
    return "Temperature is set to " + std::to_string(temperature) + "°C";
}

void Thermostat::performAction() {
    temperature++; // Increase temperature by 1
    std::cout << getStatus() << std::endl;
}

std::string Thermostat::getDeviceType() const {
    return "Thermostat";
}
