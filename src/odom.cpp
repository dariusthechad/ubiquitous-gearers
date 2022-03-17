#include "main.h"


//4.389763 original measurement
#define WHEELDIA 2.75
#define RWIDTH  4.55408568
#define LWIDTH 4.55408568

//constants for performance
const float halfdia = WHEELDIA/2;
const float totalwidth = RWIDTH + LWIDTH;
const float halfdiaoverwidth = halfdia/totalwidth;

// inches/tick (diam*pi)/360
const float rratio = 0.02399827721492203; 
const float lratio = 0.02399827721492203;
const float radtodeg = 180/pi;

float currentr;
float currentl;

float prevr = 0;
float prevl = 0;

float deltar; 
float deltal;

float absorientation; 



long double angle360(long double angle) { //makes an angle between 0 and 360
  while(!(angle >= 0 && angle < 360)) {
    if( angle < 0 ) { angle += 360; }
    if(angle >= 360) { angle -= 360; }
  }
  return(angle);
}

long double angle180(long double angle) { // makes an angle between -180 and 180
  while(!(angle >= -180 && angle < 180)) {
    if( angle < -180 ) { angle += 360; }
    if(angle >= 180) { angle -= 360; }
  }
  return(angle);
}

void updateencoders(){// calculates change in encoders values
    currentr = trackr.get_value()*rratio;
    currentl = trackl.get_value()*lratio;

    deltar = currentr - prevr;
    deltal = currentl - prevl;

    prevr = currentr;
    prevl = currentl;
}

void updatepos(){
    float absorientation = angle360(radtodeg*(currentl-currentr)/(totalwidth));

}
float startorientation;
void starttracking(float o){
    startorientation = o;
    trackr.reset();
    trackl.reset();
}

long double getorientation(){
  return startorientation + (halfdiaoverwidth) * (trackl.get_value()-trackr.get_value());
}
