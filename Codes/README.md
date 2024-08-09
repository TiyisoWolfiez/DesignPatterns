# Overview
This repository contains an assignment on various design patterns, including the Factory Method, Template Method, and Memento patterns. The project includes the implementation of these patterns and a comprehensive UML class diagram illustrating the interactions and roles of the classes involved.

# Design Patterns Covered:
  1. Factory Method
  2. Template Method
  3. Memento

# UML Class Diagram
  1. All relevent classes, their attributes, and methods.
  2. Identification of the design pattern each class is involved in.
  3. Roles of the classes within the patterns.
  4. Relationships between classes.
  5. Any additional classes necessary for a complete representation

## Random Memento Code:
```cpp
Memento(int health, int damage, int defence, int amount, std::string &name){
            this->healthPerSoldier = health;
            this->damagePerSoldier = damage;
            this->defencePerSoldier = defence;
            this->amountOfSoldiersPerUnit = amount;
            this->unitName = name;
        }
