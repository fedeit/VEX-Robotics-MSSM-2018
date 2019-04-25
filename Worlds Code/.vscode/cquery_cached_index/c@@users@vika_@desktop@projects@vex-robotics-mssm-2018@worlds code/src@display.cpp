#include "main.h"
#include "display.hpp"
#include "robot.hpp"
#include "auto_conf.hpp"

Button autoSelection(char* name, const std::map <Button, char*> btnStrings) {
  while (true) {
    pros::lcd::print(0, name);
    pros::lcd::print(1, "%%", "Left Button:", (btnStrings.count(Button::left) ? btnStrings.at(Button::left) : "None"));
    pros::lcd::print(2, "%%", "Middle Button:", (btnStrings.count(Button::middle) ? btnStrings.at(Button::middle) : "None"));
    pros::lcd::print(3, "%%", "Right Button:", (btnStrings.count(Button::right) ? btnStrings.at(Button::right) : "None"));

    Button btnPressed = Button::None;
    while (!btnStrings.count(btnPressed)) {
      int btnPressedBit = pros::lcd::read_buttons();
      if (btnPressedBit == 1)
        btnPressed = Button::right;
      else if (btnPressedBit == 2)
        btnPressed = Button::middle;
      else if (btnPressedBit == 4)
        btnPressed = Button::left;
      else
        btnPressed = Button::None;
    }

    pros::lcd::print(0, "%:%. CONFIRM?", name, btnStrings.at(btnPressed));
    pros::lcd::print(1, "Left for NO");
    pros::lcd::print(2, "Right for YES");

    int btnPressedBit = 0;
    while (btnPressedBit == 0){
      int btnPressedBit = pros::lcd::read_buttons();
    }

    if (btnPressedBit == 1)
      return btnPressed;
  }
}
