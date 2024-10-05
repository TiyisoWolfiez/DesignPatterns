#ifndef LEGACY_THERMOSTAT_H
#define LEGACY_THERMOSTAT_H

#include <iostream>

class LegacyThermostat {
public:
    LegacyThermostat(int temp);

    void setLegacyTemp(int temp);

    int getLegacyTemp() const;

private:
    int legacyTemp;
};

#endif // LEGACY_THERMOSTAT_H
