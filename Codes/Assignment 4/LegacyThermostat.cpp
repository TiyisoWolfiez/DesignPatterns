#include "LegacyThermostat.h"

LegacyThermostat::LegacyThermostat(int temp) : legacyTemp(temp) {}

void LegacyThermostat::setLegacyTemp(int temp) {
    legacyTemp = temp;
    std::cout << "Legacy Thermostat: Temperature set to " << legacyTemp << "°C" << std::endl;
}

int LegacyThermostat::getLegacyTemp() const {
    return legacyTemp;
}
