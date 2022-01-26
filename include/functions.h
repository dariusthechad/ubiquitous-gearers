#include "api.h"
#pragma once

extern bool reversed;
void variable();

int function(int x,int y);
void drive();
void fwd(int v =12000);
void turn(int v =12000);
enum button{
  L1,L2,R1,R2,UP,DOWN,LEFT,RIGHT,X,B,Y,A
};
pros::controller_digital_e_t shortbutton(button b);
namespace op {
  void brake(pros::Motor m,pros::motor_brake_mode_e_t b);
  void piston(button eb,pros::ADIDigitalOut p,pros::Controller c,int po=12000);
  void motor(button bf,button bb,pros::Motor m,pros::Controller c,int p=12000);
}

pros::controller_digital_e_t str_to_button(button b);
