#ifndef ROBOT_LIFT_HPP
#define ROBOT_LIFT_HPP

// Constants in potentiometer values (1490-4035)
#define HIGH_LEVEL_PRESET 3949
#define LOW_LEVEL_PRESET  3550
#define GROUND_PRESET 1935

#include "main.h"

enum class ClawState {
  flipped,
  initial
};

enum class LiftLevel {
  zero,
  low,
  high
};

class Lift {
private:
  // System status
  ClawState clawState = ClawState::initial;
  // Motors
  pros::Motor clawMotor = pros::Motor(8, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor liftLeft = pros::Motor(2, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor liftRight = pros::Motor(9, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
  // Claw functions
  void flipClawBack();
  void flipClawForward();
  // Sensors
  pros::ADIPotentiometer liftPotentiometer = pros::ADIPotentiometer('H');
  // Lift functions
public:
  Lift();
  int targetPosition = GROUND_PRESET;
  // Manual lift functions
  void manualUp();
  void manualDown();
  void stop();
  // PID Presets
  void goToPreset(LiftLevel preset);
  static void newPTask(void* self_p);
  // Flip
  void flipClaw();
  void releaseCap();
  void tiltClaw();
  bool isClawTilted = false;
};

#endif
