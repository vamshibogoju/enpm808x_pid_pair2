/**
 * PIdControl.cpp
 *
 *  Created on: Sep 27, 2019
 *  \author   part1: Vamshi Kumar Bogoju(driver) Achal Pragneshkumar Vyas(navigator)
 *  \author   part2: Achal Pragneshkumar Vyas(driver) Vamshi Kumar Bogoju(navigator)
 *  \copyright  Vamshi Kumar Bogoju and Achal Pragneshkumar Vyas
 */


#include <iostream>
#include "../include/PIdControl.h"

/**
 * @brief This is the constructor, which is used to initialize the PID controller system values.These values are hard coded as:kp = 2, kd = 5, ki = 4, dt = 1
 */
PIdControl::PIdControl() {
  kp = 2, kd = 5, ki = 4, dt = 1;
}


/**
 * @brief This compute function used to calculate the error between the setPoint and the actual velocity and uses this error to compute new velocity
 * @param setPoint This is the reference value which needs to be attained
 * @param actualVelocity This is the velocity which is currently running
 * @return newVel The new velocity which is computed by the PID controller
 */
double PIdControl::compute(double setPoint, double actualVelocity) {
    double error = setPoint - actualVelocity;  // compute the error
    std::cout << "Difference between setpoint and actual velocity is : " << error << "m/s" << std::endl;

    double newVel = 0;
    newVel = (kp * error) + (ki * error * dt)+ (kd * error / dt);

    return newVel;
}
/**
 * @brief Destructor
 */
PIdControl::~PIdControl() {
}
