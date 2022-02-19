#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

shrek::motor leftf (1,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_DEGREES);
shrek::motor leftm (2,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES);
shrek::motor leftb (3,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_DEGREES);

shrek::motor rightf (11,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES);
shrek::motor rightm (12,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_DEGREES);
shrek::motor rightb (13,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES);

shrek::motor fourbar (10,pros::E_MOTOR_GEARSET_36,false,pros::E_MOTOR_ENCODER_DEGREES);
shrek::motor conveyor (20,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);

shrek::digitalout goalmech1('b',1); bool gmb=1;
shrek::digitalout goalmech2('c',1);
shrek::digitalout claw('d',1);
pros::ADIDigitalIn limitswitch('g');

pros::ADIEncoder trackl('e','f');
pros::ADIEncoder trackr('g','h');
