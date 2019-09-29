/**
 *  @brief    File used to input setpoint and actual velocity
 *  @file     main file
 *  @author   part1: Vamshi Kumar Bogoju(driver) Achal Pragneshkumar Vyas(navigator)
 *  @author   part2: Akwasi A. Obeng(driver) and Sayan Brahma(navigator)
 *  @copyright Akwasi A. Obeng(driver) and Sayan Brahma(navigator)
 */

#include <iostream>
#include "../include/PIdControl.h"

/**
 * @brief This is the main file which takes the set point and
 * current velocity as user input and prints the new velocity after calculating using the function
 */
int main() {
    double setPoint, actualVelocity;
    std::cout << "Enter the Setpoint " << std::endl;
    std::cin >> setPoint;  // User input the reference value
    std::cout << "Enter the actual velocity " << std::endl;
    std::cin >> actualVelocity;  // User entering the actual velicity


    PIdControl pid;
    double newVel = pid.compute(setPoint, actualVelocity);
