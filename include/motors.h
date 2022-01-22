#include "main.h"

pros::Controller master(CONTROLLER_MASTER);
pros::Controller partner(CONTROLLER_PARTNER);

pros::Motor leftf (1,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);
pros::Motor leftm (2,MOTOR_GEARSET_18,true,MOTOR_ENCODER_DEGREES);
pros::Motor leftb (3,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);

pros::Motor rightf (11,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);
pros::Motor rightm (12,MOTOR_GEARSET_18,true,MOTOR_ENCODER_DEGREES);
pros::Motor rightb (13,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);

pros::Motor fourbar (4,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);
pros::Motor holder (5,MOTOR_GEARSET_18,false,MOTOR_ENCODER_DEGREES);