/*!
 *  \brief    This is the test file in the test folder
 *  \file     Test file - test.cpp
 *  \author   part1: Vamshi Kumar Bogoju(driver) Achal Pragneshkumar Vyas(navigator)
 *  \copyright  Vamshi Kumar Bogoju and Achal Pragneshkumar Vyas
 */

#include <gtest/gtest.h>
#include "../include/PIdControl.h"
/*
TEST(dummy, should_pass) {
  EXPECT_EQ(1, 1);
}
*/

PIdControl pid;


/**
 * @brief This is the unit test 1,where setpoint is more than actual velocity
 */

TEST(test, should_pass) {
  EXPECT_DOUBLE_EQ(pid.compute(12, 10), 22.0);
}

/**
 * @brief This is the unit test-2,where setpoint is less than actual velocity
 */

TEST(test2, should_pass) {
  EXPECT_DOUBLE_EQ(pid.compute(12, 14), -22.0);
}

/**
 * @brief This is the unit test-3,where setpoint is equal to actual velocity
 */

TEST(test3, should_pass) {
  EXPECT_DOUBLE_EQ(pid.compute(12, 12), 0.0);
}

