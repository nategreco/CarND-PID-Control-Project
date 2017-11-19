#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double min, double max, double integ_min, double integ_max) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->min = min;
  this->max = max;
  this->integ_min = integ_min;
  this->integ_max = integ_max;
  prev_err = 0;
  integ_err = 0;
}

double PID::Update(double val, double sp) {
  // Get error
  double err = sp - val;
  
  // Get pd command
  double command = Kp * err;
  if (Kd != 0.0) command += Kd * (err - prev_err);
  
  // Inetgrate error
  integ_err += err;
  
  // Limit integral to prevent wind-up
  if (Ki != 0.0) integ_err = Limit(integ_err, integ_min / Ki, integ_max / Ki);
  if (Ki != 0.0) command += Ki * integ_err;
  
  // Set previous error
  prev_err = err;
  
  // Return output checking limits
  return Limit(command, min, max);
}

double PID::Limit(double val, double min, double max) {
  if (val > max) return max;
  if (val < min) return min;
  return val;
}
