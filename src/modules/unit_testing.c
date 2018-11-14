//
//  unit_testing.c
//
//  Created by Federico Galbiati and Alex Nikanov on 13/11/2018.
//

#include "unit_testing.h"
#include "main.h"
#include "claw.h"
#include "drive.h"
#include "shooter.h"
#include "flipper.h"
#include "ballLoader.h"

void beginUnitTesting() {
    clawTesting();
    delay(1000);
    liftTesting();
    delay(1000);
    driveTesting();
    delay(1000);
    shooterTesting();
    delay(1000);
    flipperTesting();
    delay(1000);
    loaderTesting();
}

void clawTesting() {
    for (int i = 0; i < 30; i++) {
        clawUp();
        delay(100);
        clawDown();
    }
}

void liftTesting() {
    for (int i = 0; i < 30; i++) {
        liftOneLevelUp();
        delay(100);
        liftOneLevelUp();
        delay(100);
        liftOneLevelDown();
        delay(100);
        liftOneLevelDown();
    }
}

void driveTesting() {
  tankMoveLeftMotors(127);
  tankMoveRightMotors(-127);
  delay(10000);
  tankMoveLeftMotors(0);
  tankMoveRightMotors(0);
}

void shooterTesting() {
    for (int i = 0; i < 25; i++) {
        shootBall();
        delay(100);
    }
}

void flipperTesting() {
  flipperControl(127);
  delay(5000);
  flipperControl(0);
}

void loaderTesting() {
  for (int i = 0; i < 25; ++i){
      ballLoaderControl();
      delay(100);
  }
}
