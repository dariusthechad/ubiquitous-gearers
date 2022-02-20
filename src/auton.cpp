#include "main.h"


void leftgoaltime(){
    claw.set_value(0);
	fwd(-12000);
	pros::delay(1100);
	claw.set_value(1);
	fwd();
	pros::delay(900);
	stop();
}