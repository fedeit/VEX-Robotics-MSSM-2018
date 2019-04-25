#include "main.h"
#include "robot.hpp"
#include "robotSensors.hpp"


bool RobotSensors::isCapOrientationCorrect() {
  pros::vision_object redCapObject = capVisionSensor.get_by_sig(0, 1), blueCapObject = capVisionSensor.get_by_sig(0, 2);
  TeamColor capColor = TeamColor::red;

  if (redCapObject.signature ==  33) capColor = TeamColor::blue;
  if (blueCapObject.signature == 33) capColor = TeamColor::none;

  if (robot.teamColor == capColor || capColor == TeamColor::none) {
    return true;
  } else {
    return false;
  }
  return true;
}

void RobotSensors::autoRotateCap() {
  bool orientationCorrect = isCapOrientationCorrect();
  if (!orientationCorrect) {
    robot.lift.flipClaw();
  }
}

bool RobotSensors::didReachPole() {
  return poleButton.get_value();
}

int RobotSensors::sonarDistance() {
  return sonar.get_value();
}

//
// vex::vision::signature SIG_1 (1, 7679, 11797, 9738, -739, 445, -146, 3, 0);
// vex::vision::signature SIG_2 (2, -3503, -2655, -3078, 10585, 14529, 12558, 3, 0);
// vex::vision::signature SIG_3 (3, 0, 0, 0, 0, 0, 0, 3, 0);
// vex::vision::signature SIG_4 (4, 0, 0, 0, 0, 0, 0, 3, 0);
// vex::vision::signature SIG_5 (5, 0, 0, 0, 0, 0, 0, 3, 0);
// vex::vision::signature SIG_6 (6, 0, 0, 0, 0, 0, 0, 3, 0);
// vex::vision::signature SIG_7 (7, 0, 0, 0, 0, 0, 0, 3, 0);
// vex::vision Vision (vex::PORT1, 50, SIG_1, SIG_2, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7);

// https://www.vexforum.com/t/pros-vision-sensor/51358/2
// Unofficial error codes for vision framework
