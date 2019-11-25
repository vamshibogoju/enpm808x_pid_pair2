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
 *  @file      Gmock.h
 *  @author    Vamshi Bogoju
 *  @copyright Vamshi Kumar Bogoju
 *  @brief   Definition and implementation of
 *  the Gmock  class
 */
#ifndef TEST_GMOCK_H_
#define TEST_GMOCK_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/PIdControl.h"

/**
 * @brief Gmock Class
 * class to call functions of PIdControl mock class
 */
class Gmock: public ::testing::Test {
public:
	/**
	 * @brief set_Kp function
	 * @param instance of std::unique_ptr<PIdControl>
	 * @return none
	 * initializes the object and
	 * calls the setKP in the PIdControl class
	 */
	void set_KP(std::unique_ptr<PIdControl> instance) {
		instance->setKP(3);
	}

	/**
	 * @brief set_KD function
	 * @param instance of std::unique_ptr<PIdControl>
	 * @return none
	 * initializes the object and
	 * calls the setKD in the PIdControl class
	 */
	void set_KD(std::unique_ptr<PIdControl> instance) {
		instance->setKD(4);
	}

	/**
	 * @brief set_KI function
	 * @param instance of std::unique_ptr<PIdControl>
	 * @return none
	 * initializes the object and
	 * calls the setKI in the PIdControl class
	 */
	void set_KI(std::unique_ptr<PIdControl> instance) {
		instance->setKI(0.2);
	}

	/**
	 * @brief compute_PID function
	 * @param instance of std::unique_ptr<PIdControl>
	 * @return none
	 * initializes the object and
	 * calls the computePID in the PIdControl class
	 */
	void compute_PID(std::unique_ptr<PIdControl> instance) {
		instance->computePID(1, 2);
	}
};

#endif /* TEST_GMOCK_H_ */
