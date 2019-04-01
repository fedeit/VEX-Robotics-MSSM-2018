#include "main.h"
#include "robot.hpp"

void Robot::calibrate() {
  robot.lift.calibrate();
}

Robot robot = Robot();
