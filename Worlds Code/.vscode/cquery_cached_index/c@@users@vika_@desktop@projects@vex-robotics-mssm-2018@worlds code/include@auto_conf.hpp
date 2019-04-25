#ifndef _AUTO_CONF_HPP_
#define _AUTO_CONF_HPP_

enum class AutoType {
  match, // 15s
  skills // 1min
};

enum class TeamColor {
    red,
    blue,
    none
};

enum class StartingPosition {
    front,
    back
};

AutoType autoType = AutoType::match;
TeamColor teamColor = TeamColor::red;
StartingPosition startPos = StartingPosition::front;

bool platform = true;
bool stacking = true;
bool flipping = true;

#endif
