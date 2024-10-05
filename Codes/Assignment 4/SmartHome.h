#ifndef SMARTHOME_H
#define SMARTHOME_H

#include <vector>
#include "Room.h"

class SmartHome {
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
