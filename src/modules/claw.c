#include "main.h"
#include "claw.h"

void claw_control(){
  int extend = joystickGetAnalog(1, ACCEL_Y); // Vertical axis left joystick (just 2?)
  int extrude = joystickGetAnalog(1, ACCEL_X); // Horizonal axis left joystick (just 1?)
  int flipBtn = joystickGetAnalog(1, 2); // U button on the left

  motorSet(clawLiftBottomLeft, extend);
  motorSet(clawLiftTopLeft, extend);
  motorSet(clawLiftTopRight, extend);
  motorSet(clawLiftBottomRight, extend);

  motorSet(armMotor, extrude);

  motorSet(flipMotor, flipBtn);
}


