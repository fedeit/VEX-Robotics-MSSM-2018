#include "robotBallIntake.h"
#include "robotMotorDeclarations.h"

void RobotBallIntake::spinIntake() {
  if (motorBallLoader.get_actual_velocity() == 0) {
    motorBallLoader.move(110);
  }
}

void RobotBallIntake::stop() {
  motorBallLoader.move_velocity(0);
}

void RobotBallIntake::reverseIntake() {
  if (motorBallLoader.get_actual_velocity() == 0) {
    motorBallLoader.move(-110);
  }
}
