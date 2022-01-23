#include "main.h"

bool reversed = 0;
void variable(){
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

pros::controller_digital_e_t shortbutton(button b){
  switch (b) {
  case L1:return pros::E_CONTROLLER_DIGITAL_L1;
  case L2:return pros::E_CONTROLLER_DIGITAL_L2;
  case R1:return pros::E_CONTROLLER_DIGITAL_R2;
  case R2:return pros::E_CONTROLLER_DIGITAL_R2;
  case UP:return pros::E_CONTROLLER_DIGITAL_UP;
  case DOWN:return pros::E_CONTROLLER_DIGITAL_DOWN;
  case LEFT:return pros::E_CONTROLLER_DIGITAL_LEFT;
  case RIGHT:return pros::E_CONTROLLER_DIGITAL_RIGHT;
  case X:return pros::E_CONTROLLER_DIGITAL_X;
  case B:return pros::E_CONTROLLER_DIGITAL_B;
  case Y:return pros::E_CONTROLLER_DIGITAL_Y;
  case A:return pros::E_CONTROLLER_DIGITAL_A;
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
  void piston(button eb,pros::ADIDigitalOut p,pros::Controller c,int po){
    static bool v = 0;
    pros::controller_digital_e_t b = shortbutton(eb);
    if (c.get_digital_new_press(b)){
      v =! v;
      p.set_value(v);
    }
  }
  void motor(button bf,button bb,pros::Motor m,pros::Controller c=master,int p=12000){
    pros::controller_digital_e_t fwd = shortbutton(bf);
    pros::controller_digital_e_t bwd = shortbutton(bb);
    if (c.get_digital(fwd)){
      m.move_voltage(p);
    }
    else if(c.get_digital(bwd)){
      m.move_voltage(-p);
    }
    else{
      m.move_velocity(0);
    }
  } 

}
