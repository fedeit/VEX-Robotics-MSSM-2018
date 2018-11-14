//
//  unit_testing.c
//  
//
//  Created by Federico Galbiati on 13/11/2018.
//

#include "unit_testing.h"
#include "main.h"
#include "claw.h"
#include "drive.h"
#include "shooter.h"

void beginUnitTesting() {
    // Begin with lift testing
    clawTesting();
    liftTesting();
    driveTesting();
    shooterTesting();
}

void clawTesting() {
    for (int i = 0; i < 30; i++) {
        extendClaw();
        retractClaw();
    }
}

void liftTesting() {
    for (int i = 0; i < 30; i++) {
        liftOneLevelUp();
        liftOneLevelUp();
        liftOneLevelDown();
        liftOneLevelDown();
    }
}

void driveTesting() {
    
}

void shooterTesting() {
    for (int i = 0; i < 25; i++) {
        shootBall();
    }
}
