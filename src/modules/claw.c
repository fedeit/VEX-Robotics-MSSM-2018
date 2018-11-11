//
//  claw.c
//
//  This file contains the claw lifting, extending and flipping functions
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "claw.h"
#include "consts.c"

void claw_control(){
  int lifter = joystickGetAnalog(1, ACCEL_Y); // Vertical axis left joystick (just 2?)
  int extender = joystickGetAnalog(1, ACCEL_X); // Horizonal axis left joystick (just 1?)
  int flipper = joystickGetAnalog(1, 2); // Button U on the left

  motorSet(clawLiftBottomLeft, lifter);
  motorSet(clawLiftTopLeft, lifter);
  motorSet(clawLiftTopRight, lifter);
  motorSet(clawLiftBottomRight, lifter);

  motorSet(clawExtendMotor, extender);

  motorSet(clawFlipMotor, flipper);
}
