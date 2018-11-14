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
int clawLiftBottomRight = 5;
int clawLiftTopLeft = 7;
int clawLiftTopRight = 8;
// Claw control motors: extension and flipping
int clawExtendMotor = 9;
int clawFlipMotor = 2;
// Base movement wheel motors
int rightDrivingWheel1 = 4;
int leftDrivingWheel1 = 3;
int rightDrivingWheel2 = 4;
int leftDrivingWheel2 = 3;

//+++++++++++++ CONTROLLER ASSIGNMENTS ++++++++++++++++ //
int joystickId = 1;
int liftGroup = 5;
int clawGroup = 7;
int slingGroup = 8;
int leftAnalogCtrl = 3;
int rightAnalogCtrl = 2;

//+++++++++++++ MECHANICAL/TIME  ANTS +++++++++++++ //
// Unit: ms
int flipRotationTime = 253; // Calibrated
int liftSmallSTtepTime = 1000;
int fullExtensionTime = 1000;
int fullRetractionTime = 1000;
int levelUpTime = 1500;
int levelDownTime = 700;
int shootTime = 800;
