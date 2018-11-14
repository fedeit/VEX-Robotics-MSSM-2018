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
int clawLiftBottomLeft = 5;
int clawLiftBottomRight = 6;
int clawLiftTopLeft = 7;
int clawLiftTopRight = 8;
// Claw control motors: extension and flipping
int clawMotor = 9;
// Base movement wheel motors
int rightDrivingMotor1 = 4;
int rightDrivingMotor2 = 2;
int leftDrivingMotor1 = 1;
int leftDrivingMotor2 = 3;
// Flipper
int flipperMotor = 10;

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
int shortLevelUpTime = 1000;
int shortLevelDownTime = 1000;
int levelUpTime = 1500;
int levelDownTime = 700;
int shootTime = 800;
// Ball loader


// Hello

