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

PID implementation used a slightly different structure than what was provided in the starter code and some features that were not discussed in the course.  Specifically, I added the following features to my PID controller:
* Integral limiting to prevent wind-up
* Dead-band to prevent excessive movements at near-zero error
* Output limiting to prevent invalid commands

Addtionally I also utilized a PID for speed control as well.


#### 2. Results

Results were very succesful.  The vehicle drives without crossing any road markings of any kind and has no noticable osccilations.  It quickly returns to the road center and a good stead state position afer sharp turns and seems to have very natural, continuous control.
