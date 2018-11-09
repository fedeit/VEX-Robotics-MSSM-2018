#include "main.h"
#include "claw.h"

// PORTS NUMBERS
const int lBtm = 5;
const int rBtm = 6;
const int lTop = 7;
const int rTop = 8;
const int armMotor = 9;
const int flipMotor = 10;

void claw_control(){
  int extend = joystickGetAnalog(1, ACCEL_Y); // Vertical axis left joystick (just 2?)
  int extrude = joystickGetAnalog(1, ACCEL_X); // Horizonal axis left joystick (just 1?)
  int flipBtn = joystickGetAnalog(1, 2); // U button on the left

  motorSet(lBtm, extend);
  motorSet(rBtm, extend);
  motorSet(lTop, extend);
  motorSet(rTop, extend);

  motorSet(armMotor, extrude);

  motorSet(flipMotor, flipBtn);
}
