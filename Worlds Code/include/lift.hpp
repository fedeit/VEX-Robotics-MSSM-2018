#ifndef _ROBOT_LIFT_HPP_
#define _ROBOT_LIFT_HPP_

// Constants in potentiometer values (1490-4035)
#define LOW_POLE 3160
#define HIGH_POLE 3850

#define LIFT_ZERO 1980
#define LIFT_MAX 4000

#define CLAW_ZERO 0 // Change later
#define CLAW_FLIPPED 1000

#define PCONST 3

typedef unsigned int uint;

#include "api.h"
using namespace pros;

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

class Lift {
private:
  uint liftTargetPos = LIFT_ZERO;
  uint clawTargetPos = CLAW_ZERO;

  uint currLiftPotValue = LIFT_ZERO;
  uint prevLiftPotValue = LIFT_ZERO;

  uint currClawPotValue = CLAW_ZERO;
  uint prevClawPotValue = CLAW_ZERO;

  LiftMode liftMode = LiftMode::presets;
  Status liftStatus = Status::moving;
  Status clawStatus = Status::moving;

  Motor liftMotorLeft = Motor(2, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
  Motor liftMotorRight = Motor(9, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
  Motor clawMotor = Motor(3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
public:
  ADIPotentiometer liftPotentiometer = ADIPotentiometer('H');
  ADIPotentiometer clawPotentiometer = ADIPotentiometer('G'); // Modify the port

  void update();

  int getLiftVoltage();
  int getClawVoltage();

  void extend(uint speed);
  void retract(uint speed);

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
