#include "main.h"
#include "pros/motors.h"

void variable(){
  if (master.get_digital_new_press(DIGITAL_LEFT)){
    f=f-1;
  }
  if(master.get_digital_new_press(DIGITAL_RIGHT)){
    f=f+1;
  }
  if(master.get_digital_new_press(DIGITAL_B)){
    reversed =! reversed;
  }
}
int function(int x,int y){
  return (x^y)/(127^(y-1));
}
void drive(){
  float leftj = master.get_analog(ANALOG_LEFT_Y);
  float rightj = master.get_analog(ANALOG_RIGHT_Y);
  int lefts = leftj;
  int rights = rightj;
  if (reversed==0){
    leftb.move(lefts);
    leftm.move(lefts);
    leftf.move(lefts);

    rightb.move(rights);
    rightm.move(rights);
    rightf.move(rights);
  }
  else if (reversed){
    leftb.move(-rights);
    leftm.move(-rights);
    leftf.move(-rights);
    
    rightb.move(-lefts);
    rightm.move(-lefts);
    rightf.move(-lefts);
  }
}

namespace op {
  
  void brake(pros::Motor m,pros::motor_brake_mode_e_t b = pros::E_MOTOR_BRAKE_INVALID){
    pros::motor_brake_mode_e_t save = m.get_brake_mode();
    if (b==pros::E_MOTOR_BRAKE_INVALID){
      m.move_velocity(0);
    }
    else{
      m.set_brake_mode(b);
      m.move_velocity(0);
      m.set_brake_mode(save);
    }
  }
  void piston(pros::controller_digital_e_t b,pros::ADIDigitalOut p){
    static bool v = 0;
    if (master.get_digital_new_press(b)){
      v =! v;
      p.set_value(v);
    }
  }
  void motor(pros::controller_digital_e_t mf,pros::controller_digital_e_t mb,pros::Motor m,pros::Controller=master,int p=12000){
    if (master.get_digital(mf)){
      m.move_voltage(p);
    }
    else if(master.get_digital(mb)){
      m.move_voltage(-p);
    }
    else{
      m.move_velocity(0);
    }
  }
/*  void motortest(std::string sf,std::string sb,pros::Motor m,pros::Controller=master,int p=12000){
    sf = digital.append(sf);
    sb = digital.append(sb);
    pros::controller_digital_e_t mf {static_cast <pros::controller_digital_e_t> (sf)};
    pros::controller_digital_e_t mb {static_cast <pros::controller_digital_e_t> (sb)};
    if (master.get_digital(mf)){
      m.move_voltage(p);
    }
    else if(master.get_digital(mb)){
      m.move_voltage(-p);
    }
    else{
      m.move_velocity(0);
    }
  } 
  WIP, need to conv from string to controller_digital_e_t
  */
}
