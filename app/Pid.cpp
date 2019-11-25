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
