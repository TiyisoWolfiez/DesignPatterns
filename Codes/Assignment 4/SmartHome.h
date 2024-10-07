#ifndef SMARTHOME_H
#define SMARTHOME_H

#include <vector>
#include "Room.h"


/* doesnt need to directly inherit from componenet SMartDevice as it not a SmartDevice
Manages instances of Rooms do have --->*/

class SmartHome {       //Composite that hosts Rooms
private:
    std::vector<Room*> rooms;

public:
    SmartHome();
    ~SmartHome();

    void addRoom(Room* room);
    void performActionOnAllDevices();
    void showStatus() const;
    const std::vector<Room*>& getRooms() const;

};

#endif // SMARTHOME_H
