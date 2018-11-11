//
//  claw.c
//
//  This file contains claw's funtionality
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "claw.h"
#include "settings.c"

//void claw_control(){
//  int extend = joystickGetAnalog(joystickId, ACCEL_Y); // Vertical axis left joystick (just 2?)
//  int extrude = joystickGetAnalog(joystickId, ACCEL_X); // Horizonal axis left joystick (just 1?)
//  int flipBtn = joystickGetAnalog(1, 2); // U button on the left
//
//  motorSet(clawLiftBottomLeft, extend);
//  motorSet(clawLiftTopLeft, extend);
//  motorSet(clawLiftTopRight, extend);
//  motorSet(clawLiftBottomRight, extend);
//
//  motorSet(armMotor, extrude);
//
//  motorSet(flipMotor, flipBtn);
//}
//
//

void flipRight() {
    motorSet(clawFlipMotor, 110); // Set motor to speed 100 (right), not max speed (127) because it might be unstable...
    delay(flipRotationTime);
    motorStop(clawFlipMotor);
}

void flipLeft() {
    motorSet(clawFlipMotor, -110);
    delay(flipRotationTime);
    motorStop(clawFlipMotor);
}

void extendClaw() {
    motorSet(clawExtendMotor, 110);
    delay(fullExtensionTime);
    motorStop(clawExtendMotor);
}

void extendClaw() {
    motorSet(clawExtendMotor, -110);
    delay(fullRetractionTime);
    motorStop(clawExtendMotor);
}
