#include "robot.h"
#include "main.h"
#include "robotMotorDeclarations.h"

using namespace std;

Robot::Robot() {

}

void Robot::runAutonomous() {
  AutonomousSequence autoSequence = AutonomousSequence(startPos, teamColor);
  autoSequence.runSequence();
}

void Robot::runManual() {
    bool previouslyActive = false;
    int pressR1Status = 0;
    int pressR2Status = 0;
    while (true) {
        // DRIVE CONTROL
        int left = master.get_analog(ANALOG_LEFT_Y);
    		int right = master.get_analog(ANALOG_RIGHT_Y);
        tankAssembly.moveLeftSide(left);
        tankAssembly.moveRightSide(right);

        // CAP FLIPPER AND BALL LOADER
        if (master.get_digital_new_press(DIGITAL_R1)) {
          pressR1Status += 1;
        }

        if (pressR1Status == 1) {
          pressR2Status = 0;
          capFlipper.spinFlipper();
          ballIntake.stop();
        } else if (pressR1Status == 2) {
          capFlipper.stop();
          ballIntake.stop();
          pressR1Status = 0;
          pressR2Status = 0;
        }

        if (master.get_digital_new_press(DIGITAL_R2)) {
          pressR2Status += 1;
        }

        if (pressR2Status == 1) {
          pressR1Status = 0;
          capFlipper.reversedFlipper();
          ballIntake.spinIntake();
        } else if (pressR2Status == 2) {
          capFlipper.stop();
          ballIntake.stop();
          pressR1Status = 0;
          pressR2Status = 0;
        }

        // BALL SHOOTER
        if (master.get_digital(DIGITAL_L1)) {
          ballShooter.spin();
        } else {
          ballShooter.stop();
        }

        // DESCORE
        if (master.get_digital(DIGITAL_UP)) {
          previouslyActive = true;
          descore.extend();
        } else if (!master.get_digital(DIGITAL_UP) && previouslyActive) {
          descore.retract();
          previouslyActive = false;
        }
        pros::delay(20);

        // UNCOMMENT FOR TESTING ONLY
        // if (master.get_digital_new_press(DIGITAL_LEFT)) {
        //   runAutonomous();
        // }

        if (master.get_digital(/*DECIDE BUTTON*/)) {
          lift.toggleUp();
        } else if (master.get_digital(/*DECIDE BUTTON*/)) {
          lift.toggleDown();
        }
    }
}

void Robot::runDisplaySetup() {
  bool checker = true;
  bool colorSatisfied = false;
  bool tileSatisfied = false;

  while (checker) {
    if (!colorSatisfied)
      teamColor = robot.brainDisplay.chooseTeamColor();

    pros::delay(2);
    if (!tileSatisfied)
      startPos = robot.brainDisplay.chooseStartingTile();

    colorSatisfied = robot.brainDisplay.checkColor();
    tileSatisfied = robot.brainDisplay.checkTile();

    if (colorSatisfied && tileSatisfied)
      checker = false;
  }
  pros::delay(2);
}
