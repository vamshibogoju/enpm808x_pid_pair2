/**
 *  @brief    File including the class definition and stub
 *  @file     Header file - pid_controller
 *  @author   part1: Vamshi Kumar Bogoju(driver) Achal Pragneshkumar Vyas(navigator)
 *  @copyright  Vamshi Kumar Bogoju and Achal Pragneshkumar Vyas
 */

#ifndef INCLUDE_PIDCONTROL_H_
#define INCLUDE_PIDCONTROL_H_

/**
 *  @brief This is the class used to implement PID controller functionality
 */

class PIdControl {
  /**
   *  @brief This contains the class members which are private.In this,PID system variables are in private.
   */

 private:
    double kp, ki, kd, dt;

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
    ~PIdControl();
  /**
   * @brief This is the function to implement PID functionality
   */
    double compute(double setPoint, double actualVelocity);
};

#endif  // INCLUDE_PIDCONTROL_H_

