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

void autoclampf(){
	bool enabled = false;
	while(true){
		if(pros::Task::notify_take(true,20)){
			enabled =! enabled;
		}
		if (enabled){
			if(limitswitch.get_new_press()){
				claw.set_value(1);
			}
		}
		pros::delay(10);
	}
}

void turnpid(float target){
  
  double error = angle180(target - getorientation());
  double preverror = error;
  double derivative = 0;
  double integral = 0;
  double power = 0;

  const float kP = 1000;
  const float kI = 0;
  const float kD = 0;

  if(error>0){//clockwise turning
    while(fabs(error)>0.5 && pros::competition::is_autonomous()){
      error = angle180(target - getorientation());
      derivative = error-preverror;
      integral += error;

      //integral windup
      if (error<=0) {
        integral = 0;
      }
      if (error>20){
        integral =0;
      }
    

      power = error*kP + integral*kI + derivative*kD;
      turn(power);
      preverror = error;
      pros::delay(10);
    }
  }
  else{//anti-clockwise turning
    while(fabs(error)>0.5 && pros::competition::is_autonomous()){
      error = angle180(target - getorientation());
      derivative = error-preverror;
      integral += error;

      //integral windup
      if (error>=0){
        integral = 0;
      }
      if (error<20){
        integral =0;
      }
    

      power = error*kP + integral*kI + derivative*kD;
      turn(power);
      preverror = error;
      pros::delay(10);
    }
  }
  fwd(0);
}
