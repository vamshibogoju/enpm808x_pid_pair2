/**
 *  MIT License
 *
 *  Copyright (c) 2019 Vamshi Bogoju
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without
 *  limitation the rights to use, copy, modify, merge, publish, distribute,
 *  sublicense, and/or sell copies of the Software, and to permit persons to
 *  whom the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */


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
