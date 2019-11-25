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
