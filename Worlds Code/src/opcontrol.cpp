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
	bool reversed = false;
	pros::Motor motorLeftFront = pros::Motor(16, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor motorLeftBack = pros::Motor(17, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor motorRightFront = pros::Motor(10, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor motorRightBack  = pros::Motor(5, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Controller controller = pros::Controller(pros::E_CONTROLLER_MASTER);

	while (true) {
		// Drive control
		if (!reversed){
			// robot.tankAssembly.moveLeftSide(robot.controller.get_analog(ANALOG_LEFT_Y));
			// robot.tankAssembly.moveRightSide(robot.controller.get_analog(ANALOG_RIGHT_Y));
			motorLeftBack = controller.get_analog(ANALOG_LEFT_Y);
			motorLeftFront = controller.get_analog(ANALOG_LEFT_Y);
			motorRightBack = controller.get_analog(ANALOG_RIGHT_Y);
			motorRightFront = controller.get_analog(ANALOG_RIGHT_Y);
		} else {
			// robot.tankAssembly.moveRightSide(-robot.controller.get_analog(ANALOG_LEFT_Y));
			// robot.tankAssembly.moveLeftSide(-robot.controller.get_analog(ANALOG_RIGHT_Y));
			motorLeftBack = -controller.get_analog(ANALOG_RIGHT_Y);
			motorLeftFront = -controller.get_analog(ANALOG_RIGHT_Y);
			motorRightBack = -controller.get_analog(ANALOG_LEFT_Y);
			motorRightFront = -controller.get_analog(ANALOG_LEFT_Y);
		}

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

		if (robot.controller.get_digital_new_press(DIGITAL_LEFT)) {
			reversed = !reversed;
		}

		if (robot.controller.get_digital_new_press(DIGITAL_A)) {
			robot.lift.tiltClaw();
		}
	}
}
