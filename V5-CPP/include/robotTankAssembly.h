#ifndef ROBOT_TANK_ASSEMBLY
#define ROBOT_TANK_ASSEMBLY

class RobotTankAssembly {
public:
    void moveBase(double speed, Direction direction);
    void moveLeftSide(double speed, Direction direction);
    void moveRightSide(double speed, Direction direction);
    void moveLeftSide(double speed);
    void moveRightSide(double speed);
    void moveByTile(double speed, Direction direction);
    void rotateBaseOfAngle(double angle);
};

#endif

