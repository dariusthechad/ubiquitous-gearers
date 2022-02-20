#pragma once
#include "motors.h"

const double pi = 3.141592653589793238462643;

long double angle360(long double angle);
long double angle180(long double angle);

void starttracking(float o = 0);
long double getorientation();