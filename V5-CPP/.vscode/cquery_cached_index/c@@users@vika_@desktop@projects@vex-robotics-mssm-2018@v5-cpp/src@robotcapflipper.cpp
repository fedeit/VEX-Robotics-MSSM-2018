#include "robotCapFlipper.h"
#include "robotMotorDeclarations.h"

void RobotCapFlipper::spinFlipper() {
  capFlipper.move(80);
}

void RobotCapFlipper::reversedFlipper() {
  capFlipper.move(-80);
}

void RobotCapFlipper::stop() {
  capFlipper.move(0);
}
