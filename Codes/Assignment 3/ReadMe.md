# Farm Management System

## Table of Contents

- [Introduction](#introduction)
- [Component 1: Farmlands and Crop Fields](#component-1-farmlands-and-crop-fields)
- [Component 2: Soil States and Transitions](#component-2-soil-states-and-transitions)
- [Component 3: Fertilizer Application and Storage Enhancement](#component-3-fertilizer-application-and-storage-enhancement)
- [Component 4: Truck Logistics and Notifications](#component-4-truck-logistics-and-notifications)
- [Component 5: Farm Traversal Strategies](#component-5-farm-traversal-strategies)
- [How to Run the Project](#how-to-run-the-project)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project simulates the operations of a farm using a modular and extensible software architecture. The system manages various farm units like crop fields and barns, tracks soil states that affect crop yields, handles the application of fertilizers, and manages logistics operations such as delivering fertilizers and collecting crops. The system also provides a traversal strategy for navigating through the farm units to monitor and manage crop conditions effectively.

## Component 1: Farmlands and Crop Fields

The farm system is composed of various farmland units, each containing multiple crop fields.

## Tasks:
    1. ### Create a Hierarchical Structure:
     Represent farmlands composed of multiple `FarmUnit` objects. A `FarmUnit` could be a `CropField`, `Barn`, or another farm-related structure.

    2. ### CropField Details:
      - Store the type of crop (e.g., wheat, corn).
      - Maintain total storage capacity and the current amount of stored crops.
      - Track the current soil state, which affects crop yield.
     

    3.
      
