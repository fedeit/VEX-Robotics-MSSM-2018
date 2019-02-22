#include "robot.h"
#include "robotMotorDeclarations.h"

AutonomousSequence::AutonomousSequence(StartingPosition startingPosition, TeamColor color) {
  startPos = startingPosition;
  teamColor = color;
  angleFlipFactor = teamColor == red ? 1 : -1;
}

void AutonomousSequence::runSequence() {
  if (startPos == front){
    robot.ballIntake.spinIntake();
    robot.capFlipper.reversedFlipper();

    motorBallShooter.tare_position();
    motorBallShooter.move_voltage(12000);

    while (motorBallShooter.get_position() <= 1000) {
      continue;
    }

    motorBallShooter.move_voltage(0);

    robot.tankAssembly.moveBase(127);
    pros::delay(1500);

    robot.tankAssembly.moveBase(-127);
    pros::delay(2300);

    robot.tankAssembly.moveBase(0);
    pros::delay(200);

    if (teamColor == red)
      robot.tankAssembly.moveLeftSide(127);
    else
      robot.tankAssembly.moveRightSide(127);
    pros::delay(800);

    robot.tankAssembly.moveBase(127);
    pros::delay(1200);
  }
  else {
    robot.tankAssembly.moveBase(127);
    pros::delay(500);

    robot.tankAssembly.moveBase(0);

    if (teamColor == red)
      robot.tankAssembly.moveLeftSide(127);
    else
      robot.tankAssembly.moveRightSide(127);
    pros::delay(800);

    robot.tankAssembly.moveBase(127);
    pros::delay(1200);
  }
}
