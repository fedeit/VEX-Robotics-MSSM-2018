#include "robotCapFlipper.h"
#include "robotMotorDeclarations.h"

void RobotCapFlipper::spinFlipper() {
  motorCapFlipper.move(80);
}

void RobotCapFlipper::reversedFlipper() {
  motorCapFlipper.move(-80);
}

void RobotCapFlipper::stop() {
  motorCapFlipper.move(0);
}
