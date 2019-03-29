#include "main.h"
#include "robot.hpp"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the rosbot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  // // Autonomous
  // if (startPos == front){
  //   robot.ballIntake.spinIntake();
  //   robot.capFlipper.reversedFlipper();
  //
  //   motorBallShooter.tare_position();
  //   motorBallShooter.move_voltage(12000);
  //
  //   while (motorBallShooter.get_position() <= 1000) {
  //     continue;
  //   }
  //
  //   motorBallShooter.move_voltage(0);
  //
  //   robot.tankAssembly.moveBase(127);
  //   pros::delay(1500);
  //
  //   robot.tankAssembly.moveBase(-127);
  //   pros::delay(2400);
  //
  //   robot.tankAssembly.moveBase(0);
  //   pros::delay(200);
  //
  //   if (teamColor == red)
  //     robot.tankAssembly.moveLeftSide(127);
  //   else
  //     robot.tankAssembly.moveRightSide(127);
  //   pros::delay(800);
  //
  //   robot.tankAssembly.moveBase(127);
  //   pros::delay(1200);
  // }
  // else {
  //   robot.tankAssembly.moveBase(127);
  //   pros::delay(500);
  //
  //   robot.tankAssembly.moveBase(0);
  //
  //   if (teamColor == red)
  //     robot.tankAssembly.moveLeftSide(127);
  //   else
  //     robot.tankAssembly.moveRightSide(127);
  //   pros::delay(800);
  //
  //   robot.tankAssembly.moveBase(127);
  //   pros::delay(1200);
  // }
}
