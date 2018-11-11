//  settings.c
//
//  This file contains all the settings for the vehicle
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "settings.h"

int shooterMotor = 2;
// Claw lift system
int clawLiftBottomLeft = 5;
int clawLiftBottomRight = 6;
int clawLiftTopLeft = 7;
int clawLiftTopRight = 8;
// Claw control motors: extension and flipping
int clawExtendMotor = 9;
int clawFlipMotor = 10;
// Base movement wheel motors
int rightDrivingWheel = 4;
int leftDrivingWheel = 3;

//+++++++++++++ CONTROLLER ASSIGNMENTS ++++++++++++++++ //
int joystickId = 1;
int liftGroup = 5;
int clawGroup = 7;
int slingGroup = 8;
int leftAnalogCtrl = 3;
int rightAnalogCtrl = 2;

//+++++++++++++ MECHANICAL/TIME  ANTS +++++++++++++ //
// Time  s, TO BE CALIBRATED, unit of measure is ms
int flipRotationTime = 1000;
int liftSmallStepTime = 1000;
int fullExtensionTime = 500;
int fullRetractionTime = 500;
int levelUpTime = 1500;
