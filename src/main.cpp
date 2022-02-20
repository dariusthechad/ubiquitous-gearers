#include "main.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	fourbar.set_brake_mode(brake);	
	starttracking();
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
	leftgoaltime();
}



void opcontrol() {
	master.clear();
	master.set_text(2, 0, "normal");
	float prevword = 0;
	float word;
	while (true) {
		word = (getorientation());
		if (word != prevword){
			master.clear_line(0);
			pros::delay(50);
			master.set_text(0,0,std::to_string(word));
		}
		pros::lcd::clear_line(0);
		pros::lcd::set_text(0,std::to_string(word));
		prevword= word;

		drive(DIGITAL_B);
		if (master.get_digital_new_press(DIGITAL_R2)){
			goalmech1.toggle();
			goalmech2.toggle();
		}
		if(limitswitch.get_new_press()){
			claw.set_value(1);
		}
		if (master.get_digital_new_press(DIGITAL_R1)){
			claw.toggle();
		}
		fourbar.sus(L1,L2,master);
		conveyor.sus(UP,DOWN,master);
		pros::delay(10);
	}
}
