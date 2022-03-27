
#include "main.h"
#include "motors.h"
#include "pros/rtos.hpp"

void jankpistontoggle(){
	clawr.set_value(clawe.get());
	clawe.toggle();
}


void leftgoaltime(){
	fourbar.move(-127);
    jankpistontoggle();
	fwd();
	pros::delay(820);
	fwd(0);
	pros::delay(350);
	jankpistontoggle();
	pros::delay(100);
	fwd(-12000);
	pros::delay(900);
	stop();
	fourbar.move(0);
}


void middlegoaltime(){
	fwd();
	pros::delay(500);
	turn();
	pros::delay(150);
	fwd();
	pros::delay(700);
	stop();
}
void leftgoalfast(){
	fourbar.move(-127);
    jankpistontoggle();
	fwd();
	pros::delay(940);
	jankpistontoggle();
	pros::delay(300);
	fwd(-12000);
	pros::delay(900);
	stop();
	fourbar.move(0);
}
void skills(){
	backclamp.set_value(1);
	fwd();
	pros::delay(1500);
	turn(12000);
	pros::delay(150);
	fwd(-12000);
	pros::delay(2000);
	stop();
}
void awp(){
	backclamp.set_value(1);
	jankpistontoggle();
	fwdto(-5); //check this distance
	backclamp.set_value(0);
	conveyor.move(127);
	pros::delay(250);
	conveyor.move(0);
	backclamp.set_value(1);
	fwdto(5);
	turnto(0);
	fwdto(24);
	turnto(-90);
	fwdto(-96);
	backclamp.set_value(1);
	conveyor.move(127);
	turnto(-25); //check this angle
	conveyor.move(0);
	fwdto(60); //check this distance
	jankpistontoggle();
	turnto(0);
	fwd(-12000);
	pros::delay(500);
	fwd(0);
}
