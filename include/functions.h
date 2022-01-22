#include "motors.h"
int f = 1;
bool reversed = 0;
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
  int leftj = master.get_analog(ANALOG_LEFT_Y);
  int rightj = master.get_analog(ANALOG_RIGHT_Y);
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
}
