#ifndef ROBOT_LIFT_H
#define ROBOT_LIFT_H

#include "api.h"
using namespace pros;

enum ClawState {
  flipped,
  initial
};

enum LiftLevel {
  retracted,
  low,
  high
};

class Lift {
private:
  LiftLevel level = retracted;
  ClawState clawState = initial;

  Motor liftMotorLeft = Motor(2, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
  Motor liftMotorRight = Motor(9, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
  Motor clawMotor = Motor(3, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
public:
  void extend();
  void retract();
  void stop();
  void toggleUp();
  void toggleDown();
  void lowPolePreset();
  void highPolePreset();
  void retractCompletely();

  void flipClawBack();
  void flipClawForward();
  void flipClaw();
};

#endif
