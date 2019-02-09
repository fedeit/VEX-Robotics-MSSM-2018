#include "robot.h"
#include "robotMotorDeclarations.h"

AutonomousSequence::AutonomousSequence(StartingPosition startingPosition, TeamColor color) {
  startPos = startingPosition;
  teamColor = color;
  angleFlipFactor = teamColor == red ? 1 : -1;
}

void AutonomousSequence::runSequence() {
  // if (startPos == front){
  //
  //   ballLoader.tare_position();
  //   robot.ballIntake.spinIntake();
  //   robot.capFlipper.reversedFlipper();
  //
  //   motorBallShooter.tare_position();
  //   motorBallShooter.move_voltage(12000);
  //   std::cout << motorBallShooter.get_position();
  //   while (motorBallShooter.get_position() <= 4400) {
  //     continue;
  //   }
  //   motorBallShooter.move_voltage(0);
  //   robot.tankAssembly.moveByTiles(200, 1);
  //
  //   motorBallShooter.tare_position();
  //   motorBallShooter.move_voltage(12000);
  //   while (motorBallShooter.get_position() <= 4400) {
  //     continue;
  //   }
  //
  //   motorBallShooter.move(0);
  //   robot.capFlipper.stop();
  //
  //   robot.tankAssembly.moveByTiles(200, 1);
  //   robot.tankAssembly.moveByTiles(200, -1);
  //
  //   robot.tankAssembly.rotateBaseByAngle(angleFlipFactor*90);
  //   robot.capFlipper.spinFlipper();
  //   robot.tankAssembly.moveByTiles(200, 1.5);
  //   robot.capFlipper.stop();
  //   robot.tankAssembly.rotateBaseByAngle(angleFlipFactor*90);
  //   robot.capFlipper.reversedFlipper();
  //   robot.tankAssembly.moveByTiles(200, 2);
  // }
  // else {
  //   robot.tankAssembly.moveByTiles(200, -1);
  //   robot.tankAssembly.rotateBaseByAngle(angleFlipFactor*90);
  //   robot.capFlipper.spinFlipper();
  //   robot.tankAssembly.moveByTiles(200, 2);
  //
  //   robot.tankAssembly.rotateBaseByAngle(-angleFlipFactor*90);
  //   robot.tankAssembly.moveByTiles(200, 1);
  //   robot.tankAssembly.moveByTiles(200, -1);
  //
  //   robot.tankAssembly.rotateBaseByAngle(angleFlipFactor*90);
  //   robot.tankAssembly.moveByTiles(200, -0.5);
  //
  //   robot.tankAssembly.rotateBaseByAngle(-angleFlipFactor*90);
  //
  //   robot.capFlipper.reversedFlipper();
  //   robot.tankAssembly.moveByTiles(200, 2);
  // }
}
