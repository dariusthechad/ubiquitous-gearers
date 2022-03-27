#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

shrek::motor leftf (11,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_DEGREES,pros::E_MOTOR_BRAKE_COAST);
shrek::motor leftm (12,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES,pros::E_MOTOR_BRAKE_COAST);
shrek::motor leftb (13,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_DEGREES,pros::E_MOTOR_BRAKE_COAST);

shrek::motor rightf (10,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES,pros::E_MOTOR_BRAKE_COAST);
shrek::motor rightm (9,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_DEGREES,pros::E_MOTOR_BRAKE_COAST);
shrek::motor rightb (8,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES,pros::E_MOTOR_BRAKE_COAST);

shrek::motor fourbar (1,pros::E_MOTOR_GEARSET_36,true,pros::E_MOTOR_ENCODER_DEGREES,pros::E_MOTOR_BRAKE_HOLD);
shrek::motor conveyor (7,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);

shrek::digitalout backclamp('g');
shrek::digitalout clawe ({{2,'a'},1}); 
shrek::digitalout clawr ({{2,'b'}});
pros::ADIDigitalIn limitswitch(100);

pros::ADIEncoder trackr('a','b',true);
pros::ADIEncoder trackl('e','f');

