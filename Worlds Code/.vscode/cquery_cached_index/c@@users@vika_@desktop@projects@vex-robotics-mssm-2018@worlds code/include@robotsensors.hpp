#ifndef ROBOT_SENSORS_HPP
#define ROBOT_SENSORS_HPP

#include "main.h"

class RobotSensors {
private:
  pros::Vision capVisionSensor = pros::Vision(1);
  pros::ADIButton poleButton = pros::ADIButton('F');
  pros::ADIUltrasonic sonar = pros::ADIUltrasonic('A', 'B');
  bool isCapOrientationCorrect();
public:
  bool didReachPole();
  void autoRotateCap();
  int sonarDistance();
};

#endif
