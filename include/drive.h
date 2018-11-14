#ifndef DRIVE_H_
#define DRIVE_H_

#include "main.h"

void driveControl();

void tankMoveLeftMotors(int speed);

void tankMoveRightMotors(int speed);

void rotateBaseBy(int deg);

#endif // DRIVE_H_
