# Arduino Homeostat
Arduino based project demonstrating W. Ross Ashby's Homeostat.


##  Step-by-Step Guide to Building a Homeostat Replica Using Arduino
The Homeostat was a device made of four electro-mechanical units that adjusted their internal parameters to reach dynamic equilibrium. This project was one of the earliest to demonstrate Cybernetic concepts.

To replicate this, you’ll want to simulate multiple interacting systems with feedback loops that can adapt toward stability. This project uses Arduino's to achieve this goal.

Ashby’s Homeostat involved:

1. Four units (each a system with a variable internal state)
2. Each unit affected others through output connections
3. When disturbed, units randomly changed parameters until the system stabilized
4. Stabilization = All units within acceptable operating bounds

## Core Components 

In order to build th Homeostat you will need a combination of Hardware and Software. The core (recommended) components are:

1. Microcontrollers: 1 Arduino (e.g., Uno or Nano) per "unit"
2. Actuators: Servo motors or analog outputs (e.g., PWM signals) to simulate system outputs
3. Sensors: Potentiometers, light sensors, or simple analog inputs for feedback signals
4. Display/Debug: LEDs or Serial Monitor for visualizing state changes
5. Randomness: Arduino's random() function to simulate random reconfiguration

## Unit Design

Each unit should:

1. Have an internal state (e.g. a variable: float state)
2. Receive inputs from other units
3. Have a transfer function: output = f(input, internal_params)
4. Have thresholds for stability
5. When unstable, randomly modify its internal parameters

The following pseudocode demonstrates the above concepts:

```cpp
float state;
float param;
float input;
float output;

void update(float inputSignal) {
  input = inputSignal;
  output = input * param; // transfer function
  if (abs(output - target) > threshold) {
    param = random(minParam, maxParam); // adaptation example
  }
}
```


