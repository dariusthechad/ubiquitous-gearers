#include "main.h"
#include "auton.h"
#include "functions.h"
#include "pros/rtos.hpp"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	starttracking();
	fourbar.set_brake_mode(brake);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	leftgoalfast();
}


void opcontrol() {
	master.clear();
	pros::delay(50);
	master.set_text(2, 0, "normal");


	while (true) {
		pros::lcd::set_text(0,std::to_string(getorientation()));

		drive(DIGITAL_B);
		
		if (master.get_digital_new_press(DIGITAL_R2)){
			backclamp.toggle();
		}

		if (master.get_digital_new_press(DIGITAL_R1)){
			jankpistontoggle();
		}
		if(limitswitch.get_new_press()){
			clawe.set_value(1);
		}
		if (master.get_digital_new_press(DIGITAL_X)){
			master.set_text(0,0,std::to_string(getorientation()));
		}
		
		fourbar.control(L1,L2,master);
		conveyor.togglecontrol(UP,DOWN,master);
		pros::delay(10);
	}
}
