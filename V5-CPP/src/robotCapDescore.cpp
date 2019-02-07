#include "robotCapDescore.h"
#include "robotMotorDeclarations.h"


void RobotCapDescore::extend() {
  capDescore.move(70);
  pros::delay(200);
  capDescore.move(0);
  currentPosition = extended;
}

void RobotCapDescore::retract() {
  capDescore.move(-70);
  pros::delay(200);
  capDescore.move(0);
  currentPosition = retracted;
}

void RobotCapDescore::toggle() {
  if (currentPosition == retracted) {
    extend();
  } else if (currentPosition == extended) {
    retract();
  }
}

