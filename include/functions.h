#include "api.h"
#pragma once

extern bool reversed;
int curvespeed(bool red, int input, double t);
void drive(pros::controller_digital_e_t b);
void fwd(int v =12000);
void turn(int v =12000);
void stop();
void autoclampf();
