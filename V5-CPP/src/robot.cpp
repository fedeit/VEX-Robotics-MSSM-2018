#include "robot.h"
#include "main.h"
#include "robotMotorDeclarations.h"

Robot::Robot() {
  capDescore.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
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
    bool previouslyActive = false;
    while (true) {
        int left = master.get_analog(ANALOG_LEFT_Y);
    		int right = master.get_analog(ANALOG_RIGHT_Y);
        tankAssembly.moveLeftSide(left);
        tankAssembly.moveRightSide(right);

        if (master.get_digital_new_press(DIGITAL_R1)) {
          capFlipper.toggleFlipper();
        }
        if (master.get_digital_new_press(DIGITAL_R2)) {
          capFlipper.toggleReversedFlipper();
          ballIntake.toggleIntake();
        }

        if (master.get_digital(DIGITAL_L1)) {
          ballShooter.spin();
        } else {
          ballShooter.stop();
        }

        if (master.get_digital(DIGITAL_UP)) {
          previouslyActive = true;
          descore.extend();
        } else if (!master.get_digital(DIGITAL_UP) && previouslyActive) {
          descore.retract();
          previouslyActive = false;
        }

        pros::delay(20);
    }
}

void Robot::runDisplaySetup() {
    teamColor = brainDisplay.chooseTeamColor();
    startPos = brainDisplay.chooseStartingTile();
}
