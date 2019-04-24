#include "main.h"
#include "robot.hpp"

void Robot::update() {
  lift.update();
}

Robot robot = Robot();
