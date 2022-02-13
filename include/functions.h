#include "api.h"
#pragma once

extern bool reversed;
void variable(pros::controller_digital_e_t b);
int curvespeed(bool red, int input, double t);
void drive();
void fwd(int v =12000);
void turn(int v =12000);
void stop();