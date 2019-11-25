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
 *  @brief    This is the test file in the test folder
 *  @file     Test file - test.cpp
 *  @author   part1: Vamshi Kumar Bogoju
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/PIdControl.h"
#include "../include/Pid.h"
#include "../test/Gmock.h"
#include "../test/PidMock.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
/**
 *@brief Cases to test setting of kp gain by the mocked class
 *and the drived class
 *@param none
 *@return none
 */
TEST(Gmock, settingKPTest) {
Pid pid;
std::unique_ptr<PidMock> pidc(new PidMock);
std::unique_ptr<Gmock> gmock;

// expect a call of the mocked class and should return true
EXPECT_CALL(*pidc, setKP(3)).Times(1).WillOnce(Return(true));
gmock->set_KP(std::move(pidc));

// check if the expected return is equal to the actual output
EXPECT_EQ(1, pid.setKP(3));
}

/**
 *@brief Cases to test setting of kd gain by the mocked class
 *and the drived class
 *@param none
 *@return none
 */
TEST(Gmock, settingKDTest) {
Pid pid;
std::unique_ptr<PidMock> pidc(new PidMock);
std::unique_ptr<Gmock> gmock;

EXPECT_CALL(*pidc, setKD(4)).Times(1).WillOnce(Return(true));
gmock->set_KD(std::move(pidc));

EXPECT_EQ(1, pid.setKD(4));
}

/**
 *@brief Cases to test setting of ki gain by the mocked class
 *and the drived class
 *@param none
 *@return none
 */
TEST(Gmock, settingKITest) {
Pid pid;
std::unique_ptr<PidMock> pidc(new PidMock);
std::unique_ptr<Gmock> gmock;

EXPECT_CALL(*pidc, setKI(0.2)).Times(1).WillOnce(Return(true));
gmock->set_KI(std::move(pidc));

EXPECT_EQ(1, pid.setKI(0.2));
}

/**
 *@brief Cases to test setting of compute PID by the mocked class
 *and the drived class
 *@param none
 *@return none
 */
TEST(Gmock, computeMethodTest) {
Pid pid;
std::unique_ptr<PidMock> pidc(new PidMock);
std::unique_ptr<Gmock> gmock;

EXPECT_CALL(*pidc , computePID(1, 2)).Times(1).WillOnce(Return(0.0));
gmock->compute_PID(std::move(pidc));

float newVel = pid.computePID(1, 2);
EXPECT_NEAR(-4.05, newVel, 0.1);
}

/**
 *@brief Unit test to check if the returned gain
 *are the initialized gains
 *@param none
 *@return none
 */
TEST(PIDtest, getGainsTest) {
PidMock mdb;

// KP KD KI
Pid pid(3, 2, 4, 0.5);

// checking if the gains are properly set by Setkp method
EXPECT_EQ(3, pid.getKP());
EXPECT_EQ(2, pid.getKD());
EXPECT_EQ(4, pid.getKI());
}
