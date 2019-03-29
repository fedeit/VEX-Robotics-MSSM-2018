#include "main.h"
#include "robot.hpp"

void Robot::runDisplaySetup() {
  // bool checker = true;
  // bool colorSatisfied = false;
  // bool tileSatisfied = false;
  //
  // while (checker) {
  //   if (!colorSatisfied)
  //     teamColor = robot.brainDisplay.chooseTeamColor();
  //
  //   pros::delay(2);
  //   if (!tileSatisfied)
  //     startPos = robot.brainDisplay.chooseStartingTile();
  //
  //   colorSatisfied = robot.brainDisplay.checkColor();
  //   tileSatisfied = robot.brainDisplay.checkTile();
  //
  //   if (colorSatisfied && tileSatisfied)
  //     checker = false;
  // }
  // pros::delay(2);
}

Robot robot = Robot();
