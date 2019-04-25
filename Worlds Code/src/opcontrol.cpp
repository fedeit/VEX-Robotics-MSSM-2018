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
		if (robot.controller.get_digital(DIGITAL_X)) {
			robot.lift.manualUp();
		} else if (robot.controller.get_digital(DIGITAL_B)) {
			robot.lift.manualDown();
		} else if (robot.controller.get_digital_new_press(DIGITAL_R1)) {
			robot.lift.goToPreset(LiftLevel::high);
		} else if (robot.controller.get_digital_new_press(DIGITAL_R2)) {
			robot.lift.goToPreset(LiftLevel::low);
		} else if (robot.controller.get_digital_new_press(DIGITAL_L2)) {
			robot.lift.goToPreset(LiftLevel::zero);
		} else if (robot.lift.targetPosition == 9000) {
			robot.lift.stop();
		}

		// Claw control
		if (robot.controller.get_digital_new_press(DIGITAL_L1)) {
			robot.lift.flipClaw();
		}

		// CapFlipper
		if (robot.controller.get_digital(DIGITAL_UP)) {
			robot.capFlipper.spin(forward);
		} else if (robot.controller.get_digital(DIGITAL_DOWN)) {
			robot.capFlipper.spin(backward);
		} else {
			robot.capFlipper.stop();
		}
	}
}

// while (true) {
// 	pros::ADIButton poleButton = pros::ADIButton('F');
// 	if (poleButton.get_value() == 1) {
// 		std::cout << "Pressed" << std::endl;
// 	}
//
// 	pros::Vision capVisionSensor = pros::Vision(1);
// 	pros::vision_signature redCapObject = capVisionSensor.get_signature(1);
// 	pros::vision_signature blueCapObject = capVisionSensor.get_signature(0);
// 	std::cout << redCapObject.id << std::endl;
// 	std::cout << blueCapObject.id << std::endl;
// }
