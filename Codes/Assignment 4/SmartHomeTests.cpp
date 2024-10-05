#include <gtest/gtest.h>
#include "SmartHome.h"
#include "Light.h"
#include "Room.h"

TEST(SmartHomeTest, AddRoom) {
    std::cout << "Creating SmartHome..." << std::endl;
    SmartHome smartHome;

    std::cout << "Creating Living Room..." << std::endl;
    Room* livingRoom = new Room("Living Room");

    std::cout << "Adding Living Room to SmartHome..." << std::endl;
    smartHome.addRoom(livingRoom);

    std::cout << "Checking room count..." << std::endl;
    ASSERT_EQ(smartHome.getRooms().size(), 1);

    std::cout << "Checking room name..." << std::endl;
    ASSERT_EQ(smartHome.getRooms()[0]->getName(), "Living Room");

    // Do not delete livingRoom, SmartHome will handle cleanup
}

TEST(LightTest, ToggleLight) {
    Light light;
    ASSERT_EQ(light.getStatus(), "off");

    light.performAction(); // Toggles the light
    ASSERT_EQ(light.getStatus(), "on");

    light.performAction(); // Toggles the light again
    ASSERT_EQ(light.getStatus(), "off");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
