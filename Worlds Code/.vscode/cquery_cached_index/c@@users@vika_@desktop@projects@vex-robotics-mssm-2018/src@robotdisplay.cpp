#include "main.h"
#include "robotDisplay.hpp"
#include "robot.hpp"

TeamColor RobotDisplay::chooseTeamColor() {
    pros::lcd::print(1, "Choose the Color");
    pros::lcd::print(3, "Left for Blue");
    pros::lcd::print(4, "Right for Red");
    while (pros::lcd::read_buttons() == 0){
      pros::delay(2);
    }
    if(pros::lcd::read_buttons() == 4){
        return TeamColor::blue;
    } else {
        return TeamColor::red;
    }
}

StartingPosition RobotDisplay::chooseStartingTile() {
    pros::lcd::print(1, "Choose the Starting Tile");
    pros::lcd::print(3, "Left for Front");
    pros::lcd::print(4, "Right for Back");
    while (pros::lcd::read_buttons() == 0){
      pros::delay(2);
    }
    if(pros::lcd::read_buttons() == 4){
        return StartingPosition::front;
    } else {
        return StartingPosition::back;
    }
}

bool RobotDisplay::checkColor() {
  pros::lcd::print(1, "Color of the tile: %s", (robot.teamColor == red ? "RED" : "BLUE"));
  pros::lcd::print(3, "Confirm? Left for YES, right for NO");
  while (pros::lcd::read_buttons() == 0){
    pros::delay(2);
  }
  if(pros::lcd::read_buttons() == 4){
      return true;
  } else {
      return false;
  }
}

bool RobotDisplay::checkTile() {
  pros::lcd::print(1, "Type of the tile: %s", (robot.startPos == front ? "FRONT" : "BACK"));
  pros::lcd::print(3, "Confirm? Left for YES, right for NO");
  while (pros::lcd::read_buttons() == 0){
    pros::delay(2);
  }
  if(pros::lcd::read_buttons() == 4){
      return true;
  } else {
      return false;
  }
}
