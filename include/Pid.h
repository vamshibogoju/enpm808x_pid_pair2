/**
 *  @brief    File including the class definition and stub
 *  @file Pid
 *  @Created on: Nov 25, 2019
 *  @author  Vamshi Kumar Bogoju
 *  @copyright Vamshi Kumar Bogoju
 */

#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_
#include "../include/PIdControl.h"

class Pid: public PIdControl {
public:
	/**
	 *  @brief This is the constructor to initialize the default values
	 */
	Pid();

	/**
	 * @brief constructor PID class
	 * @param kp of type float
	 * @param kd of type float
	 * @param ki of type float
	 * @param dt of type float
	 * @return none
	 * Initializes gains and dt to the values passed
	 * to the constructor
	 */
	Pid(float kp, float kd, float ki, float dt);
	/**
	 * @brief This is the destructor
	 */
	virtual ~Pid();

	/**
	 * @brief getKP function
	 * @param none
	 * @return kp gain of type float
	 * returns the kp gain upon request
	 */
	float getKP();

	/**
	 * @brief getKD function
	 * @param none
	 * @return kd gain of type float
	 * returns the kd gain upon request
	 */
	float getKD();

	/**
	 * @brief getKI function
	 * @param none
	 * @return ki gain of type float
	 * returns the ki gain upon request
	 */
	float getKI();

	/**
	 * @brief computePID function
	 * @param spVel of type float
	 * @param curVel of type float
	 * @return input of type float
	 */
	float computePID(float spVel, float curVel);
};

#endif /* INCLUDE_PID_H_ */
