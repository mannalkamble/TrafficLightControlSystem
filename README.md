# README for Traffic Light Control System Project

## Project Overview
This project involves developing a traffic light control system to improve traffic flow and reduce wait times at a congested traffic intersection. The system is designed with a focus on managing traffic light sequences at two intersections: North-South and East-West. The control system allows for automated cycling through traffic light sequences with the capability for manual intervention via pedestrian push buttons.

## System Operation
The traffic light control system operates as follows:  
- Both intersections start with red lights, including the pedestrian light.  
- After 10 seconds, the North-South light turns green while the East-West remains red.  
- Following a 20-second green phase, the North-South light turns yellow for 3 seconds, then red.  
- The East-West light turns green 5 seconds after North-South turns red, staying green for 20 seconds, then yellow for 3 seconds, and finally red.
- The cycle repeats, returning to both lights red.  

A pedestrian push button at each intersection can trigger a crossing mode, temporarily altering the sequence to facilitate pedestrian movement.

## State Machine Description
The state machine for the project includes the following states:  
- Both intersections red  
- North-South green, East-West red  
- North-South yellow  
- East-West green, North-South red  
- East-West yellow  
- Pedestrian crossing mode  

Transitions between states occur based on elapsed time and button inputs, with mechanisms to handle interruptions for pedestrian crossing.  

![State Diagram](/images/StateDiagram.png)

## Hardware Components
- Breadboard  
- 4 Pushbuttons for pedestrian intervention  
- 8 LEDs (2 Red, 2 Green, 2 Yellow for traffic lights; 1 Red, 1 Green for pedestrian signals)  
- 12 Resistors (300Ω to 1000Ω)  
- Jumper wires  
- Rev1B Board  
 
## Development and Testing
- Configure GPIOs for selected pins.  
- Wire LEDs to the breadboard and connect through resistors.  
- Develop and test code for state transitions and pedestrian interventions.  
