#ifndef ROBOT_DISPLAY_HPP
#define ROBOT_DISPLAY_HPP

#include <map>

enum class Button {
  left,
  middle,
  right,
  None
};

Button autoSelection(char* name, const std::map <Button, char*> btnStrings);

#endif
