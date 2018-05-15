#include "DualVNH5019MotorShield.h"
 
// configure library with pins as remapped for single-channel operation
// this lets the single motor be controlled as if it were "motor 1"
DualVNH5019MotorShield md(2, 7, 6, A0, 2, 7, 12, A1);
 
void setup()
{
  md.init();
  // remaining setup code goes here
  ...
}
 
void loop()
{
  // loops endlessly; main loop goes here
  // the following code is a simple example:
  md.setM1Speed(400);  // single-channel motor full-speed "forward"
  delay(2000);  // wait for 2 seconds
  md.setM1Speed(0);  // single-channel motor stop (coast)
  delay(500);  // wait for 0.5 s
  md.setM1Speed(-400);  // single-channel motor full-speed "reverse"
  delay(2000);  // wait for 2 seconds
  md.setM1Speed(0);  // single-channel motor stop (coast)
  delay(500);  // wait for 0.5 s
}
