#include "robotDisplay.h"

TeamColor RobotDisplay::chooseTeamColor() {
    pros::lcd::clear();
    pros::lcd::set_text(1, "Choose an Alliance");
    pros::lcd::set_text(3, "Left for Blue");
    pros::lcd::set_text(4, "Right for Red");
    if(pros::lcd::read_buttons() == 4){
        return TeamColor::blue;
    } else if (pros::lcd::read_buttons() == 2){
        return TeamColor::red;
    }
}

StartingPosition RobotDisplay::chooseTile() {
    pros::lcd::clear();
    pros::lcd::set_text(1, "Choose a Tile");
    pros::lcd::set_text(3, "Left for Front");
    pros::lcd::set_text(4, "Right for Back");
    if(pros::lcd::read_buttons() == 4){
        return StartingPosition::front;
    } else if (pros::lcd::read_buttons() == 2){
        return StartingPosition::back;
    }
}
