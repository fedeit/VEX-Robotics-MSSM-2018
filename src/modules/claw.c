//
//  claw.c
//
//  This file contains claw's funtionality
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "settings.h"
#include "claw.h"

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

void retractClaw() {
    motorSet(clawExtendMotor, -110);
    delay(fullRetractionTime);
    motorStop(clawExtendMotor);
}
