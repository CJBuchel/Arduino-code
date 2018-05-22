/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#include "DualVNH5019MotorShield.h"
 
DualVNH5019MotorShield md;
#define LS 2      // left sensor
#define RS 3      // right sensor
#define CS 4      // Center sensor

#define RSL 13    // Robot Safety Light
/*-------definning Outputs------*/
#define LM1 4       // left motor
#define LM2 5       // left motor
#define RM1 6       // right motor
#define RM2 7       // right motor

void setup()
{
  pinMode(RSL, OUTPUT);
  digitalWrite(RSL, HIGH);
  Serial.begin(115200);
  Serial.println("Dual VNH5019 Motor Shield");
  
  Serial.println("Digital Sensor graphs -Prototype-v4");
  md.init();
  
  Serial.begin(9600);
  Serial.println("Tessa's Line Follower: Authored By Connor Buchel");
  Serial.println("------------------------------------------");
  delay(5000);
  Serial.println("IR Sensor Readings: ");
  delay(500);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
 
}

void loop()
{
  /*-------------------------------------------------------------------------------*/

  if(digitalRead(LS) && (!(digitalRead(CS) && (digitalRead(RS) ))))     // Move Forward
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
  /*----------------------------------------------------------------------*/
  if(!(digitalRead(LS) && (digitalRead(CS) && (digitalRead(RS) ))))     // Turn right
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
    /*----------------------------------------------------------------------*/
  if(digitalRead(LS) && (digitalRead(CS) && (!(digitalRead(RS) ))))     // turn left
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
    /*----------------------------------------------------------------------*/
  
}

