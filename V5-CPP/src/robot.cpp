#include "robot.h"

void Robot::runAutonomous() {
    AutonomousSequence autoSequence = AutonomousSequence(teamColor, startPos);
}

void Robot::runManual() {
    while (true) {
        pros::delay(20);
    }
}

void Robot::runDisplaySetup() {
    brainDisplay.chooseAlliance();
    brainDisplay.chooseTile();
}
