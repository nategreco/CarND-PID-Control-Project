#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double prev_err;
	double integ_err;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  double min;
  double max;
  double integ_min;
  double integ_max;
  double dead_band;
  double cmd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd, double min, double max, double integ_min, double integ_max, double dead_band);

  /*
  * Update the PID output given process value and setpoint.
  */
  double Update(double val, double sp);

private:
  /*
  * Internal function for checking limits.
  */
  double Limit(double val, double min, double max);
	
};

#endif /* PID_H */
