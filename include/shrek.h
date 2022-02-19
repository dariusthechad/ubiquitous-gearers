#pragma once
#include "api.h"

enum e_button{
  L1,L2,R1,R2,UP,DOWN,LEFT,RIGHT,X,B,Y,A
};
enum e_brake{
    coast,brake,hold,invalid
};
pros::controller_digital_e_t buttonmap(e_button b);
pros::motor_brake_mode_e_t brakemap(e_brake b);
namespace shrek{

class digitalout: public pros::ADIDigitalOut{

    private:
    bool m_value;

    public:

    explicit digitalout(std::uint8_t adi_port, bool init_state = 0)
    :pros::ADIDigitalOut{adi_port,init_state},
    m_value {init_state}
    {}

    explicit digitalout(pros::ext_adi_port_pair_t port_pair, bool init_state = 0)
    :pros::ADIDigitalOut{port_pair,init_state},
    m_value {init_state}
    {}

    void set_value(std::int32_t val){
        pros::ADIDigitalOut::set_value(val);
        m_value = bool(val);
    }

    bool get(){
        return m_value;
    }

    void toggle(){
        m_value =! m_value;
        pros::ADIDigitalOut::set_value(m_value);
    }

}; //class piston

class motor: public pros::Motor{
    private:
    pros::motor_brake_mode_e_t m_brake;

    public:
    explicit motor(const std::uint8_t port, const pros::motor_gearset_e_t gearset, const bool reverse, const pros::motor_encoder_units_e_t encoder_units
    , pros::motor_brake_mode_e_t brake = pros::E_MOTOR_BRAKE_COAST)

    :pros::Motor {port,gearset,reverse,encoder_units},
    m_brake {brake}
    {pros::Motor::set_brake_mode(m_brake);}

	explicit motor(const std::uint8_t port, const pros::motor_gearset_e_t gearset, const bool reverse
    , pros::motor_brake_mode_e_t brake = pros::E_MOTOR_BRAKE_COAST)

    :pros::Motor {port,gearset,reverse},
    m_brake {brake}
    {pros::Motor::set_brake_mode(m_brake);}

	explicit motor(const std::uint8_t port, const pros::motor_gearset_e_t gearset
    , pros::motor_brake_mode_e_t brake = pros::E_MOTOR_BRAKE_COAST)

    :pros::Motor {port,gearset},
    m_brake {brake}
    {pros::Motor::set_brake_mode(m_brake);}

	explicit motor(const std::uint8_t port, const bool reverse
    , pros::motor_brake_mode_e_t brake = pros::E_MOTOR_BRAKE_COAST)

    :pros::Motor {port,reverse},
    m_brake {brake}
    {pros::Motor::set_brake_mode(m_brake);}

	explicit motor(const std::uint8_t port, pros::motor_brake_mode_e_t brake = pros::E_MOTOR_BRAKE_COAST)
    :pros::Motor {port},
    m_brake {brake}
    {pros::Motor::set_brake_mode(m_brake);}

    void stop(e_brake b = invalid){
        if (b == invalid){
            move_velocity(0);
        }
        else{
            pros::Motor::set_brake_mode(brakemap(b));
            move_velocity(0);
            pros::Motor::set_brake_mode(m_brake);
        }
    }

    void set_brake_mode(e_brake b){
        m_brake = brakemap(b);
        pros::Motor::set_brake_mode(m_brake);
    }
    void sus(e_button b1, e_button b2, pros::Controller c){
        pros::controller_digital_e_t button1 = buttonmap(b1);
        pros::controller_digital_e_t button2 = buttonmap(b2);
        if (c.get_digital(button1)){
            move_voltage(12000);
        }
        else if (c.get_digital(button2)){
            move_voltage(-12000);
        }
        else{
            move_velocity(0);
        }
    }
}; //class motor

} //namespace shrek
