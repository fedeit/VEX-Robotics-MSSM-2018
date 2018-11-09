#include "main.h"
#include "drive.h"

// PORTS NUMBERS
const short rWheel = 3;
const short lWheel = 4;

// Main drive control function
void drive_control(){
  int power = joystickGetAnalog(2, ACCEL_Y); // vertical axis right joystick (just 2?)
  int turn = joystickGetAnalog(2, ACCEL_X); // horizonta; axis right joystick (just 1?)

  motorSet(lWheel, power + turn);
  motorSet(rWheel, power - turn);
}
