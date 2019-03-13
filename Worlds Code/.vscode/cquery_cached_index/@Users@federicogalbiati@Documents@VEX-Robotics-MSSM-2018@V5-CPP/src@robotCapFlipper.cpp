#include "robotCapFlipper.h"
#include "robotMotorDeclarations.h"

void RobotCapFlipper::spinFlipper() {
  motorCapFlipper.move(100);
}

void RobotCapFlipper::reversedFlipper() {
  motorCapFlipper.move(-70);
}

void RobotCapFlipper::stop() {
  motorCapFlipper.move(0);
}
