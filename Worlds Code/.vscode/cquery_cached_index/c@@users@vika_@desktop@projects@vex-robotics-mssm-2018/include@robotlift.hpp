#ifndef ROBOT_LIFT_H
#define ROBOT_LIFT_H

#include "api.h"
using namespace pros;

enum LiftLevel {
  retracted, low, high
};

class RobotLift {
private:
  LiftLevel level = retracted;
  Motor motor = Motor(4, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
public:
  void extend();
  void retract();
  void stop();
  void toggleUp();
  void toggleDown();
  void lowPolePreset();
  void highPolePreset();
  void retractCompletely();
};

#endif
