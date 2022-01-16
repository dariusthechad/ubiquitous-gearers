#pragma once
#include "main.h"

pros::Controller master(CONTROLLER_MASTER);

pros::Motor leftf (1,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);
pros::Motor leftm (2,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);
pros::Motor leftb (1,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);

pros::Motor rightf (1,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);
pros::Motor rightm (1,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);
pros::Motor rightb (1,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);