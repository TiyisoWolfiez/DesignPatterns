#ifndef LOCKALLDOORS_H
#define LOCKALLDOORS_H

#include "Command.h"
#include "SmartHome.h"

class LockAllDoors : public Command {
public:
    LockAllDoors(SmartHome* home) : smartHome(home) {}

    void execute() override {
        for (Room* room : smartHome->getRooms()) {
            for (SmartDevice* device : room->getDevices()) {
                if (device->getDeviceType() == "DoorLock") {
                    device->performAction();
                }
            }
        }
    }

private:
    SmartHome* smartHome; 
};

#endif // LOCKALLDOORS_H
