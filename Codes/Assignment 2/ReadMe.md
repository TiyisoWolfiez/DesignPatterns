# Design Patterns Implementation

This project demonstrates the implementation of various design patterns in C++. The patterns included are Abstract Factory, Strategy, Memento, and Composite. Below is a summary of each pattern, its usage in the code, and real-life examples.

## Abstract Factory Pattern

### Purpose
To create families of related or dependent objects without specifying their concrete classes.

### Usage in Code
We used the `LegionFactory` as an abstract factory to create different types of units (`Infantry`, `Cavalry`, `Artillery`) for different terrains (`RiverbankFactory`, `WoodlandFactory`, `OpenFieldFactory`).

### Example
```cpp
LegionFactory* factory = new RiverbankFactory();
UnitComponent* infantry = factory->createInfantry();
UnitComponent* cavalry = factory->createCavalry();
UnitComponent* artillery = factory->createArtillery();
```

### Real-Life Example
Furniture Factory: A furniture factory that can create different types of furniture (chairs, tables, sofas) for different styles (Victorian, Modern, Art Deco).

## Strategy Pattern

### Purpose
To define a family of algorithms, encapsulate each one, and make them interchangeable.

### Usage in Code
We used the `TacticalCommand` class to switch between different battle strategies ( `Flanking`, `Fortification`, `Ambush`).

### Example
```cpp
TacticalCommand command;
BattleStrategy* flanking = new Flanking();
command.setStrategy(flanking);
command.executeStrategy();
```

### Real-Life Example
Navigation App: A navigation app that can switch between different route calculation strategies (fastest route, shortest route, scenic route).

## Memento Pattern

### Purpose
To capture and externalize an object’s internal state so that the object can be restored to this state later.

### Usage in Code
We used the `TacticalCommand` class to save and restore strategies.

### Real-Life Example
Text Editor: A text editor that allows users to undo and redo changes by saving the state of the document at different points in time.

## Composite Pattern

### Purpose
To compose objects into tree structures to represent part-whole hierarchies.

### Usage in Code
We used the `Legion` class to manage groups of units, allowing individual units and groups of units to be treated uniformly.

### Example
```cpp
Legion* mainLegion = new Legion();
UnitComponent* infantry = new RiverbankInfantry();
mainLegion->add(infantry);
mainLegion->move();
```

### Real-Life Example
Company Structure: A company where the CEO is at the top, followed by managers, and then employees. Each level can be treated as a composite object, allowing operations to be performed uniformly across the hierarchy.

## Running the Code
To compile and run the code, use the following commands:
```
g++ -o main TestingMain.cpp
./main
```

This will execute the tests for the Riverbank Factory, Strategy Pattern, and Composite Pattern, demonstrating the functionality of each design pattern.

## Conclusion
These design patterns help in creating flexible, maintainable, and scalable software designs. They provide reusable solutions to common problems in software design, making the code more robust and easier to understand.
