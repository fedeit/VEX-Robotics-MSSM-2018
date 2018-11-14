//
//  drive.c
//
//  This file contains driving funtionality
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "settings.h"
#include "drive.h"


void driveControl() {
    tankMoveLeftMotors();
    tankMoveRightMotors();
}

void tankMoveLeftMotors() {
    int speed = joystickGetAnalog(joystickId, leftAnalogCtrl);
    motorSet(leftDrivingMotor1, speed);
    motorSet(leftDrivingMotor2, speed);
}

void tankMoveRightMotors() {
    int speed = joystickGetAnalog(joystickId, rightAnalogCtrl);
    motorSet(rightDrivingMotor1, -speed);
    motorSet(rightDrivingMotor2, -speed);
}

void rotateBaseBy(int deg) {
  
}
