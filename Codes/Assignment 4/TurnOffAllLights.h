#ifndef TURNOFFALLLIGHTS_H
#define TURNOFFALLLIGHTS_H

#include "Command.h"
#include "SmartHome.h"

class TurnOffAllLights : public Command {
public:
    TurnOffAllLights(SmartHome* home) : smartHome(home) {}

    void execute() override {
        // Logic to turn off all lights in the smart home
        for (Room* room : smartHome->getRooms()) {
            for (SmartDevice* device : room->getDevices()) {
                if (device->getDeviceType() == "Light") {
                    device->performAction(); // Assuming performAction toggles the light
                }
            }
        }
    }

private:
    SmartHome* smartHome; // Reference to the SmartHome to access rooms and devices
};

#endif // TURNOFFALLLIGHTS_H
