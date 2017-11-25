# **PID Control Project**

### Vehicle steering control with PID controller

---

**PID Project**

The goals / steps of this project are the following:

* Complete starter code to succesfully navigate course in vehicle simulator


---

### Writeup / README

#### 1. Provide a Writeup / README that includes all the rubric points and how you addressed each one.

My project includes the following files:
* [main.cpp](../src/main.cpp) main program that runs the IO server (given from starter code)
* [PID.cpp](../src/PID.cpp) contains the PID implementation
* [PID.h](../src/PID.h) header file for [PID.cpp](../src/PID.cpp)

### Discussion

#### 1. Implementation

PID implementation used a slightly different structure than what was provided in the starter code and some features that were not discussed in the course. Specifically, I added the following features to my PID controller:
* Integral limiting to prevent wind-up
* Dead-band to prevent excessive movements at near-zero error
* Output limiting to prevent invalid commands
Addtionally I also utilized a PID for speed control as well.

Details regarding some of the parameters behaviors:
* Proportional gain (Kp)
  * The effects of proptional gain were the most obvious and intuitive during tuning.  Because of a direct corellation of cte and Kp, larger Kp values produced larger responses to steering error.  However, since the proportional component of the PID loop is the only component that isn't time dependent, it was the most likely to cause oscillation and overshoot conditions.
* Integral gain (Ki)
 * Integral gain was found to be the most difficult to tune becase of all the parameters.  While reducing steady-state error, it can also create overshoot and oscillations due to wind-up of the integrator.  This effect was reduced by implementing integrator limits.  This allowed for the benefit of reducing steady-state error while greatly reducing wind-up and overshoot.
* Derivative gain (Kd)
 * Increasing derivative grain was very effective in reducing the tendency to overshoot and oscillate.  This made achieving a critically damped system much easier.
* Dead-band
 * The dead band parameter allows creation of a window where the command was held constant.  This is another tool for reducing oscillation and in real mechanical systems can be useful for deterring excessive movements in the system.

The approach for determing parameters for the PID's was done with a manual tuning process.  Initial all gains were at 0 and limits fully opened.  From there proportional gain was increased until adequate steering responses were created, and as a tendency to oscillate began, the derivative gain was increased to compensate.  Finally integral gain was increased to remove the steady-state error and the 3 were adjusted accordingly.


#### 2. Results

Results were very succesful.  The vehicle drives without crossing any road markings of any kind and has no noticable osccilations.  It quickly returns to the road center and a good stead state position afer sharp turns and seems to have very natural, continuous control.
