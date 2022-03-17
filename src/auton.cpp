
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
