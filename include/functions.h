#include "api.h"
#pragma once
void variable();

int function(int x,int y);
void drive();

enum button{
  L1,L2,R1,R2,UP,DOWN,LEFT,RIGHT,X,B,Y,A
};
pros::controller_digital_e_t shortbutton(button b);
namespace op {
  void brake(pros::Motor m,pros::motor_brake_mode_e_t b);
  void piston(pros::controller_digital_e_t b,pros::ADIDigitalOut p);
  void motor(pros::controller_digital_e_t mf,pros::controller_digital_e_t mb,pros::Motor m,pros::Controller,int p);
  void motortest(button bf,button bb,pros::Motor m,pros::Controller,int p);
  
}

pros::controller_digital_e_t str_to_button(button b);
