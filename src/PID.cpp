#include "PID.h"
#include <cmath>


using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double min, double max, double integ_min, double integ_max, double dead_band) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->min = min;
  this->max = max;
  this->integ_min = integ_min;
  this->integ_max = integ_max;
  this->dead_band = dead_band;
  prev_err = 0;
  integ_err = 0;
}

double PID::Update(double val, double sp) {
  // Get error
  double err = sp - val;
  integ_err += Ki * err;                   // Integrate
  if (Ki != 0.0) integ_err = Limit(integ_err, integ_min, integ_max);
  double diff_err = (err - prev_err);      // Get diff
  prev_err = err;                          // Save error

  // Check deadband
  if (fabs(err) < dead_band) return cmd;
  
  // Get pd command
  double command = 0.0; 
  if (Kp != 0.0) command += Kp * err;
  if (Kd != 0.0) command += Kd * diff_err;
  
  // Limit integral to prevent wind-up
  if (Ki != 0.0) integ_err = Limit(integ_err, (command - min), (command - max));
  if (Ki != 0.0) command += Ki * integ_err;
  
  // Return output checking limits
  cmd = Limit(command, min, max);
  return cmd;
}

double PID::Limit(double val, double min, double max) {
  if (val > max) return max;
  if (val < min) return min;
  return val;
}
