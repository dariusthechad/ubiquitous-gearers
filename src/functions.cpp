#include "main.h"

bool reversed = 0;

//https://www.desmos.com/calculator/sdcgzah5ya
int curvespeed(bool red, int input, double t){
  int val = 0;
  if(red){
    val = (std::exp(-t/10)+std::exp((std::abs(input)-100)/10)*(1-std::exp(-t/10))) * input;
  }else{
    //blue
    val = std::exp(((std::abs(input)-100)*t)/1000) * input;
  }
  return val;
}

void fwd(int v){
  leftb.move_voltage(v);
  leftm.move_voltage(v);
  leftf.move_voltage(v);
  rightb.move_voltage(v);
  rightm.move_voltage(v);
  rightf.move_voltage(v);
}
void leftfwd(int v){
  leftb.move_voltage(v);
  leftm.move_voltage(v);
  leftf.move_voltage(v);
}
void rightfwd(int v){
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
void leftstop(){
  leftf.move_velocity(0);
  leftm.move_velocity(0);
  leftb.move_velocity(0);
}
void rightstop(){
  rightf.move_velocity(0);
  rightm.move_velocity(0);
  rightb.move_velocity(0);
}
void drive(pros::controller_digital_e_t b){
  double lefts;
  double rights;
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
    if (abs(master.get_analog(ANALOG_LEFT_Y))>5){
      lefts = curvespeed(true,master.get_analog(ANALOG_LEFT_Y),10)*120;
      if (!reversed){
        leftfwd(lefts);
      }
      else {
        rightfwd(-lefts);
      }
    }
    else {
      if(!reversed){
        leftstop();
      }
      else{
        rightstop();
      }
    }


    if (abs(master.get_analog(ANALOG_RIGHT_Y))>5){
      rights = curvespeed(true,master.get_analog(ANALOG_RIGHT_Y),10)*120;
      if (!reversed){
        rightfwd(rights);
      }
      else {
        leftfwd(-rights);
      }
    }
    else {
      if(!reversed){
        rightstop();
      }
      else{
        leftstop();
      }
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
  void piston(e_button eb,pros::ADIDigitalOut p,bool &v,pros::Controller c){
    pros::controller_digital_e_t b = buttonmap(eb);
      if (c.get_digital_new_press(b)){
        v =! v;
        p.set_value(v);
    }
  }
  void oldmotor(e_button bf,e_button bb,pros::Motor m,pros::Controller c,int p){
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

PID turnpid;
void turnto(float target){
  std::uint32_t starttime = pros::millis();
  turnpid.kP = 1000;
  turnpid.integralstart = 30;
  while(true){

    turnpid.error = angle180(target - getorientation());

    turnpid.derivative = turnpid.error-turnpid.preverror;

    turnpid.integrate();

    if (fabs(turnpid.error)<0.5) {
    turnpid.counter += 1;
      if (turnpid.counter>=5){
        break;
      }
    }
    else{
      turnpid.counter = 0;
    }

    turn(turnpid.error*turnpid.kP + turnpid.integral*turnpid.kI + turnpid.derivative*turnpid.kD);

    turnpid.preverror = turnpid.error;
    pros::delay(10);
  }
  fwd(0);
  std::cout << "time taken to turn: " << std::to_string((pros::millis()-starttime)/1000) << std::endl;
  std::cout << "angle achieved: " << std::to_string(angle360(getorientation())) << std::endl;
}
