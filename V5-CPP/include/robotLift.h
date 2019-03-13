#ifndef ROBOT_LIFT_H
#define ROBOT_LIFT_H

enum LiftLevel {
  retracted, low, high
};

class RobotLift {
  void lowPolePreset();
  void highPolePreset();
  void retractCompletely();
  LiftLevel level = retracted;
public:
  void extend();
  void retract();
  void stop();
  void toggleUp();
  void toggleDown();
};

#endif
