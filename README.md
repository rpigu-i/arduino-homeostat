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
