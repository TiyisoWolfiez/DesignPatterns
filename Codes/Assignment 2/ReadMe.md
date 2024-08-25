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
