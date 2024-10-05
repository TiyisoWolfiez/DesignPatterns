CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
OBJECTS = main.o SmartHome.o Room.o Light.o DoorLock.o Thermostat.o LegacyThermostat.o SmartThermostatIntegrator.o Sensor.o MacroRoutine.o
TEST_OBJECTS = SmartHomeTests.o SmartHome.o Room.o Light.o DoorLock.o Thermostat.o LegacyThermostat.o SmartThermostatIntegrator.o Sensor.o MacroRoutine.o

# Target for building the SmartHomeAutomation executable
SmartHomeAutomation: $(OBJECTS)
	$(CXX) -o SmartHomeAutomation $(OBJECTS)

# Target for building the tests
test: $(TEST_OBJECTS)
	$(CXX) -o test $(TEST_OBJECTS) -lgtest -lgtest_main -pthread

# Compilation of source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files and the executable
clean:
	rm -f *.o SmartHomeAutomation test

# Clean test build
clean_test:
	rm -f test SmartHomeTests.o
