#include "robot.h"
#include "main.h"
#include "robotMotorDeclarations.h"

Robot::Robot() {
  capDescore.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  motorBallShooter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
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
    }
}

void Robot::runDisplaySetup() {
    teamColor = brainDisplay.chooseTeamColor();
    startPos = brainDisplay.chooseStartingTile();
}
