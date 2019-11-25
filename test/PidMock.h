/*
 * PidMock.h
 *
 *  Created on: Nov 25, 2019
 *      Author: vamshi
 */

#ifndef TEST_PIDMOCK_H_
#define TEST_PIDMOCK_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/PIdControl.h"

/**
 * @brief PidMock class
 * class to initializes the mock method
 * that are yet to be tested using gmock
 */
class PidMock : public PIdControl {
 public:
  /**
   * @brief computePID mock
   * @param float currVel
   * @param float spvel
   * @return none
   * initializes the computePID mock
   */
  MOCK_METHOD2(computePID, float(float,float));

  /**
   * @brief setKP mock
   * @param float kp
   * @return bool
   * initializes the setKP mock
   */
  MOCK_METHOD1(setKP, bool(float kp));

  /**
   * @brief setKI mock
   * @param float kI
   * @return bool
   * initializes the setKI mock
   */
  MOCK_METHOD1(setKI, bool(float ki));

  /**
   * @brief setKD mock
   * @param float kD
   * @return bool
   * initializes the setKD mock
   */
  MOCK_METHOD1(setKD, bool(float kd));
};



#endif /* TEST_PIDMOCK_H_ */
