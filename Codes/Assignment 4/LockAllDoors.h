#ifndef LOCKALLDOORS_H
#define LOCKALLDOORS_H

#include "Command.h"
#include "SmartHome.h"

class LockAllDoors : public Command {
public:
    LockAllDoors(SmartHome* home) : smartHome(home) {}

    void execute() override {
        // Logic to lock all doors in the smart home
        for (Room* room : smartHome->getRooms()) {
            for (SmartDevice* device : room->getDevices()) {
                if (device->getDeviceType() == "DoorLock") {
                    device->performAction(); // Assuming performAction toggles the lock
                }
            }
        }
    }

private:
    SmartHome* smartHome; // Reference to the SmartHome to access rooms and devices
};

#endif // LOCKALLDOORS_H
