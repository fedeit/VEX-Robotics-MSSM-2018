#include "main.h"
#include "robot.hpp"
#include "auto_conf.hpp"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  int colorConst = teamColor == TeamColor::red ? -1 : 1;
  if (autoType == AutoType::match) {
    if (startPos == StartingPosition::back) {
      robot.tankAssembly.driveStraightByTiles(-1);
      robot.tankAssembly.turnByAngle(colorConst*90);
      robot.tankAssembly.driveStraightBy(-24); // inches
    } else {
      robot.tankAssembly.driveStraightByTiles(1);
      robot.tankAssembly.turnByAngle(colorConst*90);
      robot.tankAssembly.driveStraightBy(-24); // inches
    }
  } else {
    if (startPos == StartingPosition::back) {
      robot.tankAssembly.driveStraightByTiles(-1);
      robot.tankAssembly.turnByAngle(colorConst*90);
      robot.tankAssembly.driveStraightBy(-42); // inches
    } else {
      robot.tankAssembly.driveStraightByTiles(1);
      robot.tankAssembly.turnByAngle(colorConst*90);
      robot.tankAssembly.driveStraightBy(-42); // inches
    }
  }
}
