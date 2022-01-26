#include "main.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor leftf (1,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftm (2,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftb (3,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor rightf (11,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightm (12,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightb (13,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor fourbar (10,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut goalmech1(A); 
pros::ADIDigitalOut goalmech2(B);
pros::ADIDigitalIn limitswitch(C);
