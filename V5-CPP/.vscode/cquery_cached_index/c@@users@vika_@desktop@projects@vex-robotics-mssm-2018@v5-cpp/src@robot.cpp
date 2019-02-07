#include "robot.h"
#include "main.h"

Robot::Robot() {

}

void Robot::runAutonomous() {
    AutonomousSequence autoSequence = AutonomousSequence(startPos, teamColor);

    /*
     * 1. Shoot the top flag
     * 2. Go fwd, hit the bottom flag
     * 3. Go fwd with the flipper on, flip the cap
     * 4. Get on the platform
     * 5. If enough time, add more flag/cap
     */
    tankAssembly.moveByTiles(200, 2);
    tankAssembly.moveByTiles(-200, 1);
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
