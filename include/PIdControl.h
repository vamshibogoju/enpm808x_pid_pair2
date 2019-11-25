/**
 *  @brief    File including the class definition and stub
 *  @Created on: Nov 25, 2019
 *  @author  Vamshi Kumar Bogoju
 *  @copyright Vamshi Kumar Bogoju
 */

#ifndef INCLUDE_PIDCONTROL_H_
#define INCLUDE_PIDCONTROL_H_

/**
 *  @brief This is the class used to implement PID controller functionality
 */

class PIdControl {
	/**
	 *  @brief This contains the class members which are protected.In this,PID system variables are in protected.
	 */

protected:
	// variable to store proportional gain
	float kP;
	// variable to store derivative gain
	float kD;
	// variable to store integral gain
	float kI;
	// variable to store time constant
	float dT;
	// variable to store error values for integration
	float prevError;
	// variable used to store integration values
	float inte;

	/**
	 *  @brief This contains the class members which are public.It consists of constructors and functions
	 */
public:
	/**
	 *  @brief This is the constructor to initialize the default values
	 */
	PIdControl();
	/**
	 * @brief This is the destructor
	 */
	virtual ~PIdControl();
	/**
	 * @brief pure virtual computePID method
	 * @param spVel
	 * @param curVel
	 * @return input of type float
	 * a pure virtual function to be derived for
	 * cascaded PID classes
	 */
	virtual float computePID(float spVel, float curVel) =0;
	/**
	 * @brief virtual function setKP
	 * @param kp of type float
	 * @return boolean
	 * function to set the kp value
	 */
	virtual bool setKP(float kp);
	/**
	 * @brief virtual function setKI
	 * @param kI of type float
	 * @return boolean
	 * function to set the kI value
	 */
	virtual bool setKI(float ki);

	/**
	 * @brief virtual function setKD
	 * @param kd of type float
	 * @return boolean
	 * function to set the kd value
	 */
	virtual bool setKD(float kd);
};

#endif  // INCLUDE_PIDCONTROL_H_

