/**
 *  @brief    File used to input setpoint and actual velocity
 *  @file     main file
 *  @author   part1: Vamshi Kumar Bogoju(driver) Achal Pragneshkumar Vyas(navigator)
 *  @author   part2: Akwasi A. Obeng(driver) and Sayan Brahma(navigator)
 *  @copyright Akwasi A. Obeng(driver) and Sayan Brahma(navigator)
 */

#include <iostream>
#include "../include/PIdControl.h"

int main() {
    double setPoint, actualVelocity;
    std::cout << "Enter the Setpoint " << std::endl;
    std::cin >> setPoint;
    std::cout << "Enter the actual velocity " << std::endl;
    std::cin >> actualVelocity;


    PIdControl pid;
    double newVel = pid.compute(setPoint, actualVelocity);
    std::cout << "The new velocity is " << newVel << std::endl;
    return 0;
}

