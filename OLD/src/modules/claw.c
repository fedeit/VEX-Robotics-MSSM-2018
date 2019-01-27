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
        clawUp();
    }
    if (joystickGetDigital(joystickId, clawGroup, JOY_DOWN)) {
        clawDown();
    }

    if (joystickGetDigital(joystickId, liftGroup, JOY_UP)) {
        liftOneLevelUp();
    } else if (joystickGetDigital(joystickId, liftGroup, JOY_DOWN)) {
        liftOneLevelDown();
    }
}

void clawUp() {
    motorSet(clawMotor, 127);
    delay(flipUpTime);
    motorStop(clawMotor);
}

void clawDown() {
    motorSet(clawMotor, -100);
    delay(flipDownTime);
    motorStop(clawMotor);
}

// Lift by defined levels, need to be calibrated
void liftOneLevelUp() {
    motorSet(clawLiftBottomLeft, 127);
    motorSet(clawLiftTopLeft, -127);
    motorSet(clawLiftTopRight, 127);
    motorSet(clawLiftBottomRight, -127);
    delay(levelUpTime);
    motorStop(clawLiftTopRight);
    motorStop(clawLiftBottomLeft);
    motorStop(clawLiftTopLeft);
    motorStop(clawLiftBottomRight);
}

void liftOneLevelDown() {
    motorSet(clawLiftBottomLeft, -127);
    motorSet(clawLiftTopLeft, 127);
    motorSet(clawLiftTopRight, -127);
    motorSet(clawLiftBottomRight, 127);
    delay(levelDownTime);
    motorStop(clawLiftTopLeft);
    motorStop(clawLiftTopRight);
    motorStop(clawLiftBottomLeft);
    motorStop(clawLiftBottomRight);
}
