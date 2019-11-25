/**
 * PIdControl.cpp
 *  @brief  this file defines constructors and functions
 *  @Created on: Nov 25, 2019
 *  @author  Vamshi Kumar Bogoju
 *  @copyright Vamshi Kumar Bogoju
 */

#include <iostream>
#include "../include/PIdControl.h"

/**
 * @brief This is the constructor, which is used to initialize the PID controller system values.These values are hard coded as:kp = 2, kd = 5, ki = 4, dt = 1
 */
PIdControl::PIdControl() :
		kP(0), kD(0), kI(0), dT(0), prevError(0), inte(0) {
}


/**
 * @brief Destructor
 */
PIdControl::~PIdControl() {
}

bool PIdControl::setKD(float kd) {
  kD = kd;
  return true;
}

bool PIdControl::setKP(float kp) {
  // set the kp gain value
  kP = kp;
  // return true
  return true;
}

bool PIdControl::setKI(float ki) {
  // set ki gain value
  kI = ki;
  // return true
  return true;
}
