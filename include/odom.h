#pragma once
#include "motors.h"

const long double pi = 3.14159265358979323846264338327950288419716939937510582097;

// inches/tick (diam*pi)/360
//circum = diam*pi /360
const long double circum = 2.75*pi;
const long double circum360 = circum*360;
const long double circumover360 = 360/circum;


long double angle360(long double angle);
long double angle180(long double angle);

void starttracking(float o = 0);
long double getorientation();