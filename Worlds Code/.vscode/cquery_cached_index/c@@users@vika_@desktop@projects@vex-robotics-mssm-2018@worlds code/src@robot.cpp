#include "main.h"
#include "robot.hpp"

void Robot::update() {
  this->lift.update();
}

Robot robot = Robot();
