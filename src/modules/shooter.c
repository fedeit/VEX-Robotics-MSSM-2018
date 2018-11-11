//
//  shooter.c
//
//  This file contains shooter's functionality
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "settings.h"
#include "shooter.h"

void shooterControl() {
  // Shooting control
    if (joystickGetDigital(joystickId, slingGroup, JOY_DOWN)) {
        // Load ball
    } else if (joystickGetDigital(joystickId, slingGroup, JOY_UP)) {
        //Shoot ball
    }
}

void loadBall() {
    
}

void shootBall() {
    
}
