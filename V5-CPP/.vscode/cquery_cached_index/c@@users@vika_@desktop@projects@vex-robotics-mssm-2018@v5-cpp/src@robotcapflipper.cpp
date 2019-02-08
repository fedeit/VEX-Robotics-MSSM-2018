#include "robotCapFlipper.h"
#include "robotMotorDeclarations.h"

void RobotCapFlipper::toggleFlipper() {
  if (capFlipper.get_actual_velocity() <= 0) {
    capFlipper.move(80);
  } else {
    capFlipper.move_velocity(0);
  }
}

void RobotCapFlipper::toggleReversedFlipper() {
  if (capFlipper.get_actual_velocity() >= 0) {
    capFlipper.move(-80);
  } else {
    capFlipper.move_velocity(0);
  }
}
