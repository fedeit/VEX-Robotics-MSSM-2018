#include "robotBallIntake.h"
#include "robotMotorDeclarations.h"

void RobotBallIntake::toggleIntake() {
  if (ballLoader.get_actual_velocity() == 0) {
    ballLoader.move(110);
  } else {
    ballLoader.move_velocity(0);
  }

}

void RobotBallIntake::reverseIntake() {
  if (ballLoader.get_actual_velocity() == 0) {
    ballLoader.move(110);
  } else {
    ballLoader.move_velocity(0);
  }

}
