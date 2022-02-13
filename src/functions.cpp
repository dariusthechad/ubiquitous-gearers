#include "main.h"
#include "motors.h"

bool reversed = 1;
void variable(pros::controller_digital_e_t b){
  if(master.get_digital_new_press(b)){
    reversed =! reversed;
    if(reversed){
      master.clear_line(2);
      pros::delay(50);
	    master.set_text(2, 0, "reversed");
    }
    else{
      master.clear_line(2);
      pros::delay(50);
	    master.set_text(2, 0, "normal");
    }
  }
}
int curvespeed(bool red, int input, double t){
  int val;
  if(red){
    val = (std::exp(-t/10)+std::exp((std::abs(input)-100)/10)*(1-std::exp(-t/10))) * input;
  }else{
    //blue
    val = std::exp(((std::abs(input)-100)*t)/1000) * input;
  }
  return val;
}

void drive(){
  int lefts = curvespeed(true,master.get_analog(ANALOG_LEFT_Y),10);
  int rights = curvespeed(true,master.get_analog(ANALOG_RIGHT_Y),10);
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
void fwd(int v){
  leftb.move_voltage(v);
  leftm.move_voltage(v);
  leftf.move_voltage(v);
  rightb.move_voltage(v);
  rightm.move_voltage(v);
  rightf.move_voltage(v);
}
void turn(int v){
  leftb.move_voltage(v);
  leftm.move_voltage(v);
  leftf.move_voltage(v);
  rightb.move_voltage(-v);
  rightm.move_voltage(-v);
  rightf.move_voltage(-v);
}
void stop(){
  leftf.move_velocity(0);
  leftm.move_velocity(0);
  leftb.move_velocity(0);
  rightf.move_velocity(0);
  rightm.move_velocity(0);
  rightb.move_velocity(0);
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
  void piston(e_button eb,pros::ADIDigitalOut p,bool &v,pros::Controller c){
    pros::controller_digital_e_t b = buttonmap(eb);
    if (c.get_digital_new_press(b)){
      v =! v;
      p.set_value(v);
    }
  }
  void motor(e_button bf,e_button bb,pros::Motor m,pros::Controller c,int p){
    pros::controller_digital_e_t fwd = buttonmap(bf);
    pros::controller_digital_e_t bwd = buttonmap(bb);
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
