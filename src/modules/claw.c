//
//  claw.c
//
//  This file contains claw's funtionality
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "settings.h"
#include "claw.h"

void clawControl() {
    if (joystickGetDigital(joystickId, clawGroup, JOY_UP)) {
        extendClaw();
    }
    if (joystickGetDigital(joystickId, clawGroup, JOY_DOWN)) {
        retractClaw();
    }

    if (joystickGetDigital(joystickId, clawGroup, JOY_RIGHT)) {
        flipRight();
    } else if (joystickGetDigital(joystickId, clawGroup, JOY_LEFT)) {
        flipLeft();
    }

    if (joystickGetDigital(joystickId, liftGroup, JOY_UP)) {
        liftOneLevelUp();
    } else if (joystickGetDigital(joystickId, liftGroup, JOY_DOWN)) {
        liftOneLevelDown();
    }
}

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
    motorSet(clawExtendMotor, 127);
    delay(fullExtensionTime);
    motorStop(clawExtendMotor);
}

void retractClaw() {
    motorSet(clawExtendMotor, -110);
    delay(fullRetractionTime);
    motorStop(clawExtendMotor);
}

// Lift by defined levels, need to be calibrated
void liftOneLevelUp() {
    motorSet(clawLiftBottomLeft, 127);
    motorSet(clawLiftTopLeft, -127);
    motorSet(clawLiftTopRight, 127);
    motorSet(clawLiftBottomRight, -127);
    delay(levelUpTime);
    motorStop(clawLiftTopRight);
    motorStop(clawLiftBottomRight);
    motorStop(clawLiftBottomLeft);
    motorStop(clawLiftTopLeft);
}

void liftOneLevelDown() {
    motorSet(clawLiftBottomLeft, -127);
    motorSet(clawLiftTopLeft, 127);
    motorSet(clawLiftTopRight, -127);
    motorSet(clawLiftBottomRight, 127);
    delay(levelUpTime);
    motorStop(clawLiftTopLeft);
    motorStop(clawLiftTopRight);
    motorStop(clawLiftBottomLeft);
    motorStop(clawLiftBottomRight);
}
