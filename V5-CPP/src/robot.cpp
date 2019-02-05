#include "robot.h"

void Robot::Robot() {
    master = pros::Controller(pros::E_CONTROLLER_MASTER);
    
}

void Robot::runAutonomous() {
    AutonomousSequence autoSequence = AutonomousSequence(teamColor, startPos);
}

void Robot::runManual() {
    while (true) {
        // read joystick movements
        // read buttons pressed
        
        pros::delay(20);
    }
}

void Robot::runDisplaySetup() {
    teamColor = brainDisplay.chooseTeamColor();
    startingTile = brainDisplay.chooseStartingTile();
}
