#include "robot.h"
#include "robotMotorDeclarations.h"

AutonomousSequence::AutonomousSequence(StartingPosition startingPosition, TeamColor color) {
  startPos = startingPosition;
  teamColor = color;
  angleFlipFactor = 1;
}

void AutonomousSequence::runSequence() {
  if (teamColor == red) {
    angleFlipFactor = -1;
  }

  motorBallShooter.tare_position();
  motorBallShooter.move_voltage(12000);
  while (motorBallShooter.get_position() <= 4400) {

  }
  motorBallShooter.move(0);
  // robot.tankAssembly.moveByTiles(200, 3);
}
