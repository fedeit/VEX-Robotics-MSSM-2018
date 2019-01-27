# VEX-Robotics-MSSM-2018

This is the code for the robot of the VEX Team 4393Z
It is written using Pro C++ and not minor C++ implementations such as VEX C++, allowing for complex implementations.

The robot uses a vertical lift, a fly wheel, a rotating ball feeder, and a claw. 

The user joystick controls are mapped as following:
- X: Spin fly wheel
- R1: Ball feeder load
- R2: Ball feeder unload
- Axis 2: Tank control right base motor wheels
- Axis 3: Left base motor wheels
- L1: Lift up
- L2: Lift down
- Button up: Claw up
- Button down: Claw down

We make use of the VEX C++ PRO API, both to actively control mechanical parts, and to constantly check system integrity (temperature, stability, speed, efficiency...)
