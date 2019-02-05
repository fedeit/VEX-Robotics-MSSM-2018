#ifndef ROBOT_H
#define ROBOT_H

using namespace pros;

clawMotor = motor(8, E_MOTOR_GEARSET_18, false);
baseMotorLeftFront = motor(9, E_MOTOR_GEARSET_18, false);
baseMotorRightFront = motor(10, E_MOTOR_GEARSET_18, false);
torqueLiftLeft = motor(4, E_MOTOR_GEARSET_36, false);
torqueLiftRight = motor(2, E_MOTOR_GEARSET_36, false);
ballLoader = motor(5, E_MOTOR_GEARSET_18, false);
ballShooter = motor(3, E_MOTOR_GEARSET_18, false);

#endif
