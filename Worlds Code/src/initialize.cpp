#include "main.h"
#include "robot.hpp"
#include "display.hpp"
#include "auto_conf.hpp"

#include <vector>
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

void competition_initialize() {
	switch(autoSelection((char*)"Auto Type", {{Button::left, (char*)"MATCH"}, {Button::right, (char*)"SKILLS"}})) {
		case Button::left:
			autoType = AutoType::match;
			break;
		case Button::right:
			autoType = AutoType::skills;
			break;
		default:
			break;
	}
	switch(autoSelection((char*)"Team Color", {{Button::left, (char*)"RED"}, {Button::right, (char*)"BLUE"}})) {
		case Button::left:
			teamColor = TeamColor::red;
			break;
		case Button::right:
			teamColor = TeamColor::blue;
			break;
		default:
			break;
	}
	switch(autoSelection((char*)"Starting Position", {{Button::left, (char*)"FRONT"}, {Button::right, (char*)"BACK"}})) {
		case Button::left:
			startPos = StartingPosition::front;
			break;
		case Button::right:
			startPos = StartingPosition::back;
			break;
		default:
			break;
	}
	switch(autoSelection((char*)"Platform", {{Button::left, (char*)"ON"}, {Button::right, (char*)"OFF"}})) {
		case Button::left:
			platform = true;
			break;
		case Button::right:
			platform = false;
			break;
		default:
			break;
	}
	switch(autoSelection((char*)"Stacking", {{Button::left, (char*)"ON"}, {Button::right, (char*)"OFF"}})) {
		case Button::left:
			stacking = true;
			break;
		case Button::right:
			stacking = false;
			break;
		default:
			break;
	}
	switch(autoSelection((char*)"Flipping", {{Button::left, (char*)"ON"}, {Button::right, (char*)"OFF"}})) {
		case Button::left:
			flipping = true;
			break;
		case Button::right:
			flipping = false;
			break;
		default:
			break;
	};
}
