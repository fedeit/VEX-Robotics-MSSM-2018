//  settings.h
//
//  This file contains all the settings for the vehicle
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#ifndef SETTINGS_H_
#define SETTINGS_H_

// Motors ports assignments
// Ball shooter system
extern int shooterMotor;
// Claw lift system
extern int clawLiftBottomLeft;
extern int clawLiftBottomRight;
extern int clawLiftTopLeft;
extern int clawLiftTopRight;
// Claw control motors: extension and flipping
extern int clawExtendMotor;
extern int clawFlipMotor;
// Base movement wheel motors
extern int rightDrivingWheel1;
extern int leftDrivingWheel1;
extern int rightDrivingWheel2;
extern int leftDrivingWheel2;

//+++++++++++++ CONTROLLER ASSIGNMENTS ++++++++++++++++ //
extern int joystickId;
extern int liftGroup;
extern int clawGroup;
extern int slingGroup;
extern int leftAnalogCtrl;
extern int rightAnalogCtrl;

//+++++++++++++ MECHANICAL/TIME  ANTS +++++++++++++ //
// Times, TO BE CALIBRATED, unit of measure is ms
extern int flipRotationTime ;
extern int liftSmallStepTime;
extern int fullExtensionTime;
extern int fullRetractionTime;
extern int levelUpTime;
extern int levelDownTime;
extern int shootTime;
#endif // SETTINGS_H_
