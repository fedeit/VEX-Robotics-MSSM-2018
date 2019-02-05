#ifndef ROBOT_MOTOR_DECLARATIONS_H
#define ROBOT_MOTOR_DECLARATIONS_H

#include "api.h"
#include "robot.h"

using namespace pros;

extern Robot robot;

extern Motor baseMotorLeftFront = Motor(9, E_MOTOR_GEARSET_18, false);
extern Motor baseMotorRightFront = Motor(10, E_MOTOR_GEARSET_18, false);
extern Motor baseMotorLeftBack = Motor(11, E_MOTOR_GEARSET_18, false);
extern Motor baseMotorRightBack  = Motor(12, E_MOTOR_GEARSET_18, false);

//extern Motor clawMotor;
//extern Motor torqueLiftLeft;
//extern Motor torqueLiftRight;

extern Motor ballLoader = Motor(5, E_MOTOR_GEARSET_18, false);
extern Motor ballShooter = Motor(3, E_MOTOR_GEARSET_18, false);

extern Motor capFlipper = Motor(8,E_MOTOR_GEARSET_18, false);
extern Motor capDebouncer = Motor(8,E_MOTOR_GEARSET_18, false);

#endif
