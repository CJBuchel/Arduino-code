/*The tripple sensor board you have should work with this. However, the middle sesor would be obsolete.  

/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS 1      // left sensor
#define RS 13      // right sensor

/*-------definning Outputs------*/
#define LM1 2       // left motor // you can change the pin numbers to suit you best

#define RM1 7       // right motor


#include "DualVNH5019MotorShield.h"
 
// configure library with pins as remapped for single-channel operation
// this lets the single motor be controlled as if it were "motor 1"
DualVNH5019MotorShield md;
 
void setup()
{
  md.init();
  // remaining setup code goes here
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);//<==sensors
  
  pinMode(LM1, OUTPUT);
  
  pinMode(RM1, OUTPUT);
  
}
 
void loop()
{
  // loops endlessly; main loop goes here
  // the following code is a simple example:


 if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    
     md.setM1Speed(400);  // single-channel motor (left) full-speed "forward"
  delay(0);  

     md.setM2Speed(400);  // single-channel motor (right) full-speed "forward"
  delay(0);  
    
    
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
    
     md.setM1Speed(0);  
  delay(0);  
    
    
     md.setM2Speed(400);  
  delay(0);  
    
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
    
     md.setM1Speed(400); 
  delay(0);  
   
    
     md.setM2Speed(0); 
  delay(0);  
    
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    
     md.setM1Speed(0);  
  delay(0);  
    
    
     md.setM1Speed(0);  
  delay(0);  
    
  }
}



