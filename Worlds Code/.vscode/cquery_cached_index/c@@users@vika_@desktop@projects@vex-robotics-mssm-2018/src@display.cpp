#include "main.h"
#include "display.hpp"
#include "robot.hpp"
#include "conf.hpp"

TeamColor Display::chooseTeamColor() {
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

StartingPosition Display::chooseStartingTile() {
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

bool Display::checkColor() {
  pros::lcd::print(1, "Color of the tile: %s", (TEAM_COLOR == red ? "RED" : "BLUE"));
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

bool Display::checkTile() {
  pros::lcd::print(1, "Type of the tile: %s", (STARTING_POSITION == front ? "FRONT" : "BACK"));
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
