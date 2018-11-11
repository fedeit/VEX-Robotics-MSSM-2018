//
//  consts.c
//  
//  This file contains the ports assignments for all the motors of the vehicle
//  Created by Federico Galbiati on 10/11/2018.
//

#include "main.h"

// Ball shooter system
const int shooterMotor = 2;
// Claw lift system
const int clawLiftBottomLeft = 5;
const int clawLiftBottomRight = 6;
const int clawLiftTopLeft = 7;
const int clawLiftTopRight = 8;
// Claw control motors: extension and flipping
const int clawExtendMotor = 9;
const int clawFlipMotor = 10;
// Base movement wheel motors
const short rightDrivingWheel = 3;
const short leftDrivingWheel = 4;
// joystick identifiers
const int joystickId = 1;
const int liftGroup = 5;
const int clawGroup = 7;
const int slingGroup = 6;

// Time consts, TO BE CALIBRATED, unit of measure is ms
const int flipRotationTime = 1000;
const int liftSmallStepTime = 1000;
