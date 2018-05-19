

#include <RedBot.h>
RedBotSensor left = RedBotSensor(A0);   // initialize a left sensor object on A3
RedBotSensor center = RedBotSensor(A4); // initialize a center sensor object on A6
RedBotSensor right = RedBotSensor(A5);  // initialize a right sensor object on A7

// constants that are used in the code. LINETHRESHOLD is the level to detect 
// if the sensor is on the line or not. If the sensor value is greater than this
// the sensor is above a DARK line.
//
// SPEED sets the nominal speed

#define LINETHRESHOLD 100
#define SPEED 120  // sets the nominal speed. Set to any number from 0 - 255.

RedBotMotors motors;
int leftSpeed;   // variable used to store the leftMotor speed
int rightSpeed;  // variable used to store the rightMotor speed

#include "DualVNH5019MotorShield.h"
 
DualVNH5019MotorShield md;
 

void setup()
{
  Serial.begin(115200);
  Serial.println("Dual VNH5019 Motor Shield");
  md.init();
  
	Serial.begin(9600);
	Serial.println(" Tripple Reflective Sensors Online: Authored By Connor Buchel");
	Serial.println("------------------------------------------");
	delay(2000);
	Serial.println("IR Sensor Readings: ");
	delay(500);
   
}

void loop()
{
  
	Serial.print(left.read());
	Serial.print("\t");  // tab character
	Serial.print("\t");  // tab character
	Serial.print(right.read());
	Serial.println();

 if(center.read() > LINETHRESHOLD)
 {
    for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i);
    if (i%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(0);
  }
for (int i = 0; i <= 400; i++)
  {
    md.setM2Speed(i);
    if (i%200 == 100)
    {
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(0);
  }
  }



	
	// if the line is under the right sensor, adjust relative speeds to turn to the right
	else if(right.read() > LINETHRESHOLD)
	{
    for (int i = 0; i <= 400; i++)
  {
    md.setM2Speed(i);
   
    if (i%200 == 100)
    {
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(0);
  }
   for (int i = -400; i <= 0; i++)
  {
    md.setM1Speed(i);
    if (i%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(0);
  }

  
	}

	// if the line is under the left sensor, adjust relative speeds to turn to the left
	else if(left.read() > LINETHRESHOLD)
	{

    for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i);
    if (i%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(0);
  }
  for (int i = -400; i <= 0; i++)
  {
    md.setM2Speed(i);
    if (i%200 == 100)
    {
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }
    delay(0);
  }

  }
    
    
	
	
	// if all sensors are on black or up in the air, stop the motors.
	// otherwise, run motors given the control speeds above.
	if((left.read() > LINETHRESHOLD) && (center.read() > LINETHRESHOLD) && (right.read() > LINETHRESHOLD) )
	{
		 digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
	}
}

	
