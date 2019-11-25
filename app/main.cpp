/**
 *  @brief    File used to input setpoint and actual velocity
 *  @file     main file
 *  @Created on: Nov 25, 2019
 *  @author  Vamshi Kumar Bogoju
 *  @copyright Vamshi Kumar Bogoju
 */


#include <iostream>
#include "memory"
#include "../include/PIdControl.h"
#include "../include/Pid.h"

/**
 * @brief This is the main file which takes the set point and
 * current velocity as user input and prints the new velocity after calculating using the function
 */
int main() {
	// Instantiate a object
	  Pid pid;
	  // point the virtual class object to the Pid class
	  std::unique_ptr<PIdControl> pidc = std::make_unique<Pid>();

	  // variables to hold user input
	  float fVal, iVal;

	  // input Target setpoint velocity
	  std::cout << "Enter the Target velocity" << std::endl;
	  std::cin >> fVal;

	  // input actual velocity
	  std::cout << "Enter the current velocity" << std::endl;
	  std::cin >> iVal;

	  // PID gains
	  pidc->setKD(1);
	  pidc->setKI(0.1);
	  pidc->setKP(2);

	  // compute the control input
	  float inc = pid.computePID(fVal, iVal);

	  // output the input to the screen
	  std::cout << "Input value: " << inc << std::endl;

	  return 0;
	}
