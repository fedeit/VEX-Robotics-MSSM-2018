#ifndef ROBOT_LIFT_H
#define ROBOT_LIFT_H

// Constants in potentiometer values (0-4095)
#define ABOVE_LOW_LEVEL_POT_PRESET 180
#define ABOVE_HIGH_LEVEL_POT_PRESET 94

#define LOW_LEVEL_POT_PRESET 190
#define HIGH_LEVEL_POT_PRESET 85

#include "api.h"
using namespace pros;

enum ClawState {
  flipped,
  initial
};

enum LiftLevel {
  zero,
  low,
  high
};

class Lift {
private:
  LiftLevel level = zero;
  ClawState clawState = initial;

  Motor liftMotorLeft = Motor(2, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
  Motor liftMotorRight = Motor(9, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
  Motor clawMotor = Motor(3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
public:
  // Lift functions
  void extend();
  void retract();
  void toggleUp();
  void toggleDown();
  void lowPolePreset();
  void highPolePreset();
  void retractCompletely();
  void stop();
  void holdToPosition(int position);
  void holdToClosest();

  // Claw functions
  void flipClawBack();
  void flipClawForward();
  void flipClaw();

  // Misc functions
  void calibrate();
  int getLiftPotentiometerValue();

  ADIPotentiometer liftPotentiometer = ADIPotentiometer('H');
};

#endif
