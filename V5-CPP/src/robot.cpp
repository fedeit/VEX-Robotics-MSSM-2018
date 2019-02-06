#include "robot.h"
#include "main.h"

Robot::Robot() {
  
}

void Robot::runAutonomous() {
    AutonomousSequence autoSequence = AutonomousSequence(startPos, teamColor);
}

void Robot::runManual() {
    while (true) {
        // read joystick movements
        // read buttons pressed
        // Do we want to create a controller class that has logs buttons pressed
        // and has call back functions on the hardware instance vars of the robot?
        int left = master.get_analog(ANALOG_LEFT_Y);
    		int right = master.get_analog(ANALOG_RIGHT_Y);
        tankAssembly.moveLeftSide(left);
        tankAssembly.moveRightSide(right);

        if (master.get_digital_new_press(DIGITAL_Y)) {
          capFlipper.toggleFlipper();
        }
        if (master.get_digital_new_press(DIGITAL_A)) {
          capFlipper.toggleReversedFlipper();
        }

        if (master.get_digital(DIGITAL_X)) {
          ballShooter.spin();
        } else {
          ballShooter.stop();
        }

        if (master.get_digital_new_press(DIGITAL_R1)) {
          ballIntake.toggleIntake();
        }

        if (master.get_digital_new_press(DIGITAL_Y)) {
          descore.toggle();
        }

        pros::delay(20);
    }
}

void Robot::runDisplaySetup() {
    teamColor = brainDisplay.chooseTeamColor();
    startPos = brainDisplay.chooseStartingTile();
}
