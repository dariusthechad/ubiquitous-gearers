#include "main.h"

pros::controller_digital_e_t buttonmap(e_button b){
  switch (b) {
  case L1:return pros::E_CONTROLLER_DIGITAL_L1;
  case L2:return pros::E_CONTROLLER_DIGITAL_L2; break;
  case R1:return pros::E_CONTROLLER_DIGITAL_R1; break;
  case R2:return pros::E_CONTROLLER_DIGITAL_R2; break;
  case UP:return pros::E_CONTROLLER_DIGITAL_UP; break;
  case DOWN:return pros::E_CONTROLLER_DIGITAL_DOWN; break;
  case LEFT:return pros::E_CONTROLLER_DIGITAL_LEFT; break;
  case RIGHT:return pros::E_CONTROLLER_DIGITAL_RIGHT; break;
  case X:return pros::E_CONTROLLER_DIGITAL_X; break;
  case B:return pros::E_CONTROLLER_DIGITAL_B; break;
  case Y:return pros::E_CONTROLLER_DIGITAL_Y; break;
  case A:return pros::E_CONTROLLER_DIGITAL_A; break;
  default:return pros::E_CONTROLLER_DIGITAL_X;
  }
}
pros::motor_brake_mode_e_t brakemap(e_brake b){
    switch (b){
        case coast:return pros::E_MOTOR_BRAKE_COAST;
        case brake:return pros::E_MOTOR_BRAKE_BRAKE;
        case hold:return pros::E_MOTOR_BRAKE_HOLD;
        case invalid:return pros::E_MOTOR_BRAKE_INVALID;
        default:return pros::E_MOTOR_BRAKE_INVALID;
    }
}