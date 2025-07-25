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

The cybernetic concepts the device and this recreation of it explore are:

1. Variety: Each unit has a range of possible states
2. Feedback: Outputs influence other inputs 
3. Adaptation: Unstable units change configuration
4. Equilibrium: System converges to a stable state
5. Redundancy of potential command: Multiple pathwats to stability


## Core Components 

In order to build the Homeostat you will need a combination of Hardware and Software. The core (recommended) components are:

1. Microcontrollers: 1 Arduino (e.g., Uno or Nano) per "unit"
2. Actuators: Servo motors or analog outputs (e.g., PWM signals) to simulate system outputs
3. Sensors: Potentiometers, light sensors, or simple analog inputs for feedback signals
4. Display/Debug: LEDs or Serial Monitor for visualizing state changes
5. Randomness: Arduino's random() function to simulate random reconfiguration
6. Wire.h library for I2C comms between multiple Arduino devices
7. Breadboard: For connecting the devices together. 

See the assembly diagram below for an example of a simple configuration. 


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

Based upon the design the homeostat each unit's output becomes an input for the other units, for example:

```cpp

Unit 1 → 2
Unit 2 → 3
Unit 3 → 4
Unit 4 → 1 (closed loop)

```

## Source Code

Code for each homeostat device is located in the `src` directory. Use the Arduino IDE to upload a copy of the `.ino` to each device.

Prior to uploading, ensure you update the Unit number so it is unique for each Arduino board:

```cpp

#define UNIT_ID 1  // Change per board: 1, 2, 3, 4

```


## Futher Reading

You can learn more about the topic of cybernetics via"

1. W. Ross Ashby - An introduction to Cybernetics (1959)
2. Andrew Pickering - The Cybernetic Brain (2010)
3. Norbert Weiner - Cybernetics: Or Control and Communication in the Animal and the Machine (1948)
4. Norbert Weiner - The Human Use of Human Beings: Cybernetics and Society (1950)
5. Thomas Rid - Rise of the Machines: A Cybernetic History (2016)

