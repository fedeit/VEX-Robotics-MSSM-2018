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
extern int clawLiftTopLeft;
extern int clawLiftTopRight;
extern int clawLiftBottomRight;
// Claw control motors: extension and flipping
extern int clawMotor;
// Base movement wheel motors
extern int rightDrivingMotor1;
extern int leftDrivingMotor1;
extern int rightDrivingMotor2;
extern int leftDrivingMotor2;
// Flipper
extern int flipperMotor;
// Ball loader
extern int ballLoaderMotor;

//+++++++++++++ CONTROLLER ASSIGNMENTS ++++++++++++++++ //
extern int joystickId;
extern int liftGroup;
extern int clawGroup;
extern int slingGroup;
extern int leftAnalogCtrl;
extern int rightAnalogCtrl;

//+++++++++++++ MECHANICAL/TIME  ANTS +++++++++++++ //
// Times, TO BE CALIBRATED, unit of measure is ms
extern int flipUpTime;
extern int flipDownTime;
extern int liftSmallStepTime;
extern int levelUpTime;
extern int levelDownTime;
extern int shootTime;
// BollLoader
#endif // SETTINGS_H_
