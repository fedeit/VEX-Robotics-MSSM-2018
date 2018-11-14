//  settings.c
//
//  This file contains all the settings for the vehicle
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "settings.h"

// Shooter system
int shooterMotor = 10;
// Claw lift system
int clawLiftBottomLeft = 6;
int clawLiftBottomRight = 7;
int clawLiftTopLeft = 7;
int clawLiftTopRight = 8;
// Claw control motors: extension and flipping
int clawMotor = 9;
// Base movement wheel motors
int rightDrivingMotor1 = 1;
int rightDrivingMotor2 = 3;
int leftDrivingMotor1 = 2;
int leftDrivingMotor2 = 4;
// Flipper
int flipperMotor = 5;

//+++++++++++++ CONTROLLER ASSIGNMENTS ++++++++++++++++ //
int joystickId = 1;
int liftGroup = 5;
int clawGroup = 7;
int slingGroup = 8;
int leftAnalogCtrl = 3;
int rightAnalogCtrl = 2;

//+++++++++++++ MECHANICAL/TIME  ANTS +++++++++++++ //
// Unit: ms
int flipUpTime = 253;
int flipDownTime = 150;
int liftSmallStepTime = 1000;
int levelUpTime = 1500;
int levelDownTime = 700;
int shootTime = 800;
// Ball loader
