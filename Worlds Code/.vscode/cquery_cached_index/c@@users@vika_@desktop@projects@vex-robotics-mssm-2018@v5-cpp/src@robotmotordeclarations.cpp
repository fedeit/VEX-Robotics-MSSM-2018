#include "robotMotorDeclarations.h"
#include "robot.h"
using namespace pros;


//clawMotor = Motor(8, E_MOTOR_GEARSET_18, false);
//torqueLiftLeft = Motor(4, E_MOTOR_GEARSET_36, false);
//torqueLiftRight = Motor(2, E_MOTOR_GEARSET_36, false);
Robot robot = Robot();
Motor baseMotorLeftFront = Motor(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor baseMotorRightFront = Motor(20, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor baseMotorLeftBack = Motor(9, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor baseMotorRightBack  = Motor(13, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

//Motor clawMotor;
//Motor torqueLiftLeft;
//Motor torqueLiftRight;

Motor motorBallLoader = Motor(19, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor motorBallShooter = Motor(12, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);

Motor motorCapFlipper = Motor(10,E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor capDescore = Motor(8,E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
