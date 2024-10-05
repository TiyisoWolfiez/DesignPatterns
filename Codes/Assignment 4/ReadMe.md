# Smart Home Automation Project

## Overview

This project is a `Smart Home Automation System` built in C++, showcasing various object-oriented design patterns, including `Command Pattern`, `Adapter Pattern`, and `Macro Commands`. It enables the simulation of smart home devices, such as lights, thermostats, and door locks, and allows for automation routines.

We also ensure the correctness and stability of the system through `unit tests` using `Google Test`, and perform `memory leak analysis` using `Valgrind`.

### Table of Contents
- [Project Structure](#project-structure)
- [Design Patterns Used](#design-patterns-used)
- [Build and Run](#build-and-run)
- [Running Unit Tests](#running-unit-tests)
- [Valgrind Memory Leak Checks](#valgrind-memory-leak-checks)

### Project Structure

### Design Patterns Used

The project leverages the following design patterns to ensure scalability, flexibility, and clean separation of concerns:

### Command Pattern:
Encapsulates requests for device actions (like turning off all lights or locking all doors) into command objects that can be executed later, such as in a macro routine.

**Classes:**
- `TurnOffAllLights`
- `LockAllDoors`
- `MacroRoutine`

### Adapter Pattern:
Integrates the legacy thermostat (`LegacyThermostat`) into the new smart home system by adapting its interface through the `SmartThermostatIntegrator` class.

### Observer Pattern (used with sensors):
Allows the motion sensor (`Sensor`) to notify devices like lights whenever movement is detected, triggering their corresponding actions.

### Build and Run

### Running Unit Tests

### Valgrind Memory Leak Checks

