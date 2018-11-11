//
//  drive.c
//
//  This file contains driving funtionality
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "drive.h"
#include "settings.c"

// Main drive control function
void drive_control(){
    int power = joystickGetAnalog(2, ACCEL_Y); // vertical axis right joystick (just 2?)
    int turn = joystickGetAnalog(2, ACCEL_X); // horizonta; axis right joystick (just 1?)

    motorSet(leftDrivingWheel, power + turn);
    motorSet(rightDrivingWheel, power - turn);
}

void tankMoveLeftMotors() {
    int speed = joystickGetAnalog(joystickId, 3);
    motorSet(leftDrivingWheel, speed);
}


void tankMoveRightMotors() {
    int speed = joystickGetAnalog(joystickId, 2);
    motorSet(rightDrivingWheel, speed);
}
