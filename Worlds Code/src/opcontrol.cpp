#include "main.h"
#include "robot.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	while (true) {
		// Drive control
		robot.tankAssembly.moveLeftSide(robot.controller.get_analog(ANALOG_LEFT_Y));
		robot.tankAssembly.moveRightSide(robot.controller.get_analog(ANALOG_RIGHT_Y));

		// Lift contol
		if (robot.controller.get_digital(DIGITAL_R1)) {
			robot.lift.extend();
		}
		else if (robot.controller.get_digital(DIGITAL_R2)) {
			robot.lift.retract();
		}
		else {
			robot.lift.stop();
		}

		// Claw control
		if (robot.controller.get_digital_new_press(DIGITAL_L1)) {
			robot.lift.flipClaw();
		}
	}
}
