
#pragma once
#include "api.h"
#include "classes.h"

extern pros::Controller master;
extern pros::Controller partner;

extern shrek::motor leftf;
extern shrek::motor leftm;
extern shrek::motor leftb;

extern shrek::motor rightf;
extern shrek::motor rightm;
extern shrek::motor rightb;

extern shrek::motor fourbar;
extern shrek::motor conveyor;

extern shrek::digitalout backclamp;
extern shrek::digitalout clawe;
extern shrek::digitalout clawr;
extern pros::ADIDigitalIn limitswitch;

extern pros::ADIEncoder trackl;
extern pros::ADIEncoder trackr;