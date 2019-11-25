/**
 * Pid.cpp
 *  @brief  this file defines constructors and functions
 *  @Created on: Nov 25, 2019
 *  @author  Vamshi Kumar Bogoju
 *  @copyright Vamshi Kumar Bogoju
 */


#include "../include/PIdControl.h"
#include "../include/Pid.h"

Pid::Pid() {
	kP = 2;
	kD = 1;
	kI = 0.1;
	dT = 0.5;
	prevError = 0;
	inte = 0;
}

Pid::Pid(float kp, float kd, float ki, float dt) {
	kP = kp;
	kD = kd;
	kI = ki;
	dT = dt;
	prevError = 0;
	inte = 0;
}


Pid::~Pid() {
}

float Pid::getKD() {
  return kD;
}

float Pid::getKI() {
  return kI;
}

float Pid::getKP() {
  return kP;
}

float Pid::computePID(float spVel, float curVel) {
  // calculate error
    float error = spVel - curVel;
    // calculate inte for integral
    inte += error * dT;
    // calculate final output
    // Proportional term = kp* error
    // integral term  = kI * inte
    // derivative term = kD * ((error - prevError) / dT)
    float output = kP * error + kI * inte + kD * ((error - prevError) / dT);
    prevError = error;
    return output;
}
