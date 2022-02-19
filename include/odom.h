#pragma once
#include "motors.h"

const double pi = 3.141592653589793238462643;

double angle360(double angle);
double angle180(double angle);

void starttracking(float o = 0);
double getorientation();