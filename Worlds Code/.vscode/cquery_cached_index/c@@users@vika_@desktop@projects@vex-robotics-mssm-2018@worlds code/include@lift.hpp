#ifndef _ROBOT_LIFT_HPP_
#define _ROBOT_LIFT_HPP_

// Constants in potentiometer values (1490-4035)
const int LOW_POLE = 3550;
const int HIGH_POLE = 3949;

const int LIFT_ZERO = 1935;
const int LIFT_MAX = 4000;

const int CLAW_ZERO = 0; // Change later
const int CLAW_FLIPPED = 1000;

const int PCONST  = 3;

typedef unsigned int uint;

#include "api.h"

enum class LiftLevel {
  zero,
  low,
  high
};

enum class LiftMode {
  manual,
  presets
};

enum class Status {
  rest,
  moving
};

enum class ClawState {
  initial,
  flipped
};

class Lift {
private:
  uint liftTargetPos = LIFT_ZERO;
  uint currLiftPotValue = LIFT_ZERO;
  uint prevLiftPotValue = LIFT_ZERO;

  LiftMode liftMode = LiftMode::presets;
  Status liftStatus = Status::rest;

  ClawState clawState = ClawState::initial;

  pros::Motor liftMotorLeft = pros::Motor(2, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor liftMotorRight = pros::Motor(9, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor clawMotor = pros::Motor(8, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
public:
  pros::ADIPotentiometer liftPotentiometer = pros::ADIPotentiometer('B');
  pros::ADIButton guidebarSwitch = pros::ADIButton('F');

  void update();

  int getLiftVoltage();

  void extend();
  void retract();

  void toggleUp();
  void toggleDown();

  void lowPolePreset();
  void highPolePreset();
  void retractCompletely();

  void hold();
  void stop();

  // Claw methods
  void flipClaw();

  // Misc methods
  void calibrate();
};

#endif
