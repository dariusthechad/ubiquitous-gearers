#include "api.h"
#pragma once
int f = 1;
bool reversed = 0;
void variable();

int function(int x,int y);
void drive();

std::string digital = "DIGITAL_";


namespace op {
  void brake(pros::Motor m,pros::motor_brake_mode_e_t b);
  void piston(pros::controller_digital_e_t b,pros::ADIDigitalOut p);
  void motor(pros::controller_digital_e_t mf,pros::controller_digital_e_t mb,pros::Motor m,pros::Controller,int p);
/*  void motortest(std::string sf,std::string sb,pros::Motor m,pros::Controller=master,int p=12000);
  */
}
