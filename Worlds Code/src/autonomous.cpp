#include "main.h"
#include "robot.hpp"

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
  // Cap 1
  robot.tankAssembly.goToPosition(2, 1);
  robot.tankAssembly.pickupCap();
  robot.lift.goToPreset(LiftLevel::high);
  robot.robotSensors.autoRotateCap();
  robot.tankAssembly.goToPosition(0, 1);
  robot.tankAssembly.releaseCap();

  // Cap 2...
}
