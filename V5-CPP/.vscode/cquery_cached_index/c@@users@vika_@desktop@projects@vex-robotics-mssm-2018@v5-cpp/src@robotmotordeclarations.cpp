#include "robotMotorDeclarations.h"
#include "robot.h"
using namespace pros;


//clawMotor = Motor(8, E_MOTOR_GEARSET_18, false);
//torqueLiftLeft = Motor(4, E_MOTOR_GEARSET_36, false);
//torqueLiftRight = Motor(2, E_MOTOR_GEARSET_36, false);
Robot robot = Robot();
Motor baseMotorLeftFront = Motor(2, E_MOTOR_GEARSET_18, false);
Motor baseMotorRightFront = Motor(20, E_MOTOR_GEARSET_18, true);
Motor baseMotorLeftBack = Motor(9, E_MOTOR_GEARSET_18, false);
Motor baseMotorRightBack  = Motor(13, E_MOTOR_GEARSET_18, true);

//Motor clawMotor;
//Motor torqueLiftLeft;
//Motor torqueLiftRight;

Motor ballLoader = Motor(19, E_MOTOR_GEARSET_18, false);
Motor ballShooter = Motor(12, E_MOTOR_GEARSET_36, true);

Motor capFlipper = Motor(10,E_MOTOR_GEARSET_18, false);
Motor capDescore = Motor(8,E_MOTOR_GEARSET_18, true);
