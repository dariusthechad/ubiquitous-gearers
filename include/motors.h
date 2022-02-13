#include "api.h"
#pragma once
extern pros::Controller master;
extern pros::Controller partner;

extern pros::Motor leftf;
extern pros::Motor leftm;
extern pros::Motor leftb;

extern pros::Motor rightf;
extern pros::Motor rightm;
extern pros::Motor rightb;

extern pros::Motor fourbar;

extern pros::ADIDigitalOut goalmech1; extern bool gmb;
extern pros::ADIDigitalOut goalmech2;
extern pros::ADIDigitalOut claw; extern bool clawb;
extern pros::ADIDigitalIn limitswitch;