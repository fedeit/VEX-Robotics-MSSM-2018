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

  robot.tankAssembly.moveByTiles(100, 3);
  robot.tankAssembly.moveByTiles(-100, 1);
  robot.tankAssembly.rotateBaseByAngle(angleFlipFactor * 90);
  robot.tankAssembly.moveByTiles(100, 1);
}
