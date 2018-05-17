/*The tripple sensor board you have should work with this. However, the middle sesor would be obsolete.  

/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS 1      // left sensor
#define RS 13      // right sensor

/*-------definning Outputs------*/
#define LM1 2       // left motor // you can change the pin numbers to suit you best

#define RM1 7       // right motor

#define RSL 5   // Robot signal light (RSL), if you choose to include it.  it's on pin 5, it can change to a different pin or no pin at all if you don't want a safty light


#include "DualVNH5019MotorShield.h" //This includes a library in the code, that way we can use the motor shield
 
// configure library with pins as remapped for single-channel operation
// this lets the single motor be controlled as if it were "motor 1"
DualVNH5019MotorShield md;

void stopIfFault()
{
  if (md.getM1Fault())
  {
    Serial.println("M1 fault"); //<==Prints out faults to the serial monitor. if there are any faults with the motors
    while(1);
  }
  if (md.getM2Fault())
  {
    Serial.println("M2 fault");
    while(1);
  }
}
 
void setup()
{

   Serial.begin(115200);
  Serial.println("Dual VNH5019 Motor Shield");
  md.init();
  // remaining setup code goes here
  pinMode(LS, INPUT); //<=====
  pinMode(RS, INPUT);//<===^sensors
  
  pinMode(LM1, OUTPUT);  //these two define that we will be using the Lm1 variable and the Rm1 as outputs (motors). as shown above when we defined Lm1 and Rm1 as pins 2 and 7, however we are not using pins on the arduino board for the motors.
  // so technically we don't need this code. But we can utilize it for something else in the future.
  
  pinMode(RM1, OUTPUT);
  
  
}
 
void loop()
{
  // loops endlessly; main loop goes here
  // the following code is a simple example:


    

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>
 if(digitalRead(LS) && digitalRead(RS))     // Move Forward if no sensors see black
  {
    digitalWrite(RSL, HIGH);   // turn the LED on (HIGH is the voltage level, which is a max of 5 volts)
  delay(0);   
     for (int i = 0; i <= 400; i++)
  {/*-------------------------------------------------------------------------*/
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)                                
    {                                                                         /* <<== Motor 1 - 100% power*/
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }/*-------------------------------------------------------------------------*/
                                                                                                                                                            // <<== This block makes it move forward.
    for (int i = 0; i <= 400; i++)
  {/*-------------------------------------------------------------------------*/
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {                                                                         /* <<== Motor 2 - 100% power*/
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }/*-------------------------------------------------------------------------*/  
    
    
  }
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>


  
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------> 
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right if the left sensor sees black
  {
    digitalWrite(RSL, HIGH);   // turn the LED on (HIGH is the voltage level, which is a max of 5 volts)
  delay(0);   
    for (int i = 0; i <= 400; i++)
  {/*-------------------------------------------------------------------------*/
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {                                                                        /* <<== Motor 2 - 100% power*/                                                 //<<== This block makes it turn right.
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }/*-------------------------------------------------------------------------*/
     
  }

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>
  
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left if right sensor sees black
  {
    digitalWrite(RSL, HIGH);   // turn the LED on (HIGH is the voltage level, which is a max of 5 volts)
  delay(0);   
       for (int i = 0; i <= 400; i++)
  {/*-------------------------------------------------------------------------*/
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)                                
    {                                                                         /* <<== Motor 1 - 100% power*/                                               //<<== This block makes it turn left.
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }/*-------------------------------------------------------------------------*/ 
  }

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>
  
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop if both sensors see black <==== i put this in here as a safty sort of thing. if you want to stop the robot at the end of a line. just great a large black patch on the ground
  {/*-------------------------------------------------------------------------*/
    
  digitalWrite(RSL, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(RSL, LOW);    // turn the LED off by making the voltage LOW                                                                                       //<<== Stops and Blinks Light on pin 5
  delay(1000);                       // wait for a second
    
  }/*-------------------------------------------------------------------------*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>
}


