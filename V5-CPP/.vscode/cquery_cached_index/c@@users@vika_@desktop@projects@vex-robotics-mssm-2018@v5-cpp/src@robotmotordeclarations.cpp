#include "robotMotorDeclarations.h"

using namespace pros;

baseMotorLeftFront = Motor(9, E_MOTOR_GEARSET_18, false);
baseMotorRightFront = Motor(10, E_MOTOR_GEARSET_18, false);
baseMotorLeftBack = Motor(11, E_MOTOR_GEARSET_18, false);
baseMotorRightBack = Motor(12, E_MOTOR_GEARSET_18, false);

//clawMotor = Motor(8, E_MOTOR_GEARSET_18, false);
//torqueLiftLeft = Motor(4, E_MOTOR_GEARSET_36, false);
//torqueLiftRight = Motor(2, E_MOTOR_GEARSET_36, false);

ballLoader = Motor(5, E_MOTOR_GEARSET_18, false);
ballShooter = Motor(3, E_MOTOR_GEARSET_18, false);

capFlipper = Motor(8,E_MOTOR_GEARSET_18, false);
capDebouncer = Motor(8,E_MOTOR_GEARSET_18, false);
