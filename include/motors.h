
#pragma once
#include "api.h"
#include "shrek.h"

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

extern shrek::digitalout goalmech1; extern bool gmb;
extern shrek::digitalout goalmech2;
extern shrek::digitalout claw;
extern pros::ADIDigitalIn limitswitch;

extern pros::ADIEncoder trackl;
extern pros::ADIEncoder trackr;