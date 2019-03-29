#include "capFlipper.hpp"

void RobotCapFlipper::spin(Direction dir) {
  switch(dir) {
    case forward:
      this->motor.move(100);
      break;
    case backward:
      this->motor.move(-70);
      break;
    case stop:
      this->motor.move(0);
      break;
  }
}
