#include "capFlipper.hpp"
#include "robot.hpp"

void CapFlipper::spin(Direction dir) {
  switch(dir) {
    case forward:
      this->motor.move(127);
      break;
    case backward:
      this->motor.move(-127);
      break;
    default:
      break;
  }
}

void CapFlipper::stop() {
  this->motor.move(0);
}
