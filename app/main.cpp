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
