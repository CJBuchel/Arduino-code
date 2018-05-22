/*created by Mostafa Zaghloul with a helper library called RedBot.h you can find 
 * it on this link https://github.com/sparkfun/RedBot 
 *--------------------------- thanks a million --------------------------------- 
 *you can find me on 
 *FaceBook::https://www.facebook.com/mostafa.zaghlol3
 *Twitter::https://twitter.com/Mostafazaghlul
 *to Contact for hardware or software questions 
 */
#include "DualVNH5019MotorShield.h"
 
DualVNH5019MotorShield md;
#include <RedBot.h>

RedBotSensor left_sen = RedBotSensor(A0);   
RedBotSensor center_sen = RedBotSensor(A3); 
RedBotSensor right_sen = RedBotSensor(A5);  
//data_sheet
// constants that are used in the code. lineStandard is the level to detect 
// if the sensor is on the line or not. If the sensor value is greater than this
// the sensor is above a DARK line.
//
// SPEED sets the nominal speed
//motor A

int lineStandard = 800;



void setup()
{ 
  Serial.begin(9600);
  Serial.println("IR Sensor Readings:: ");
  delay(1000);
}

void loop()
{
  Serial.print(left_sen.read());
  Serial.print("\t");  
  Serial.print(center_sen.read());
  Serial.print("\t"); 
  Serial.print(right_sen.read());
  Serial.println();

//data_sheet
  // if on the line drive left and right at the same speed (left is CCW / right is CW)
  if(center_sen.read() > lineStandard)
  {//right
   
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

  //data_sheet
  // if the line is under the right sensor, adjust relative speeds to turn to the right
  else if(right_sen.read() > lineStandard)
  {//left
  
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
  //data_sheet
  // if the line is under the left sensor, adjust relative speeds to turn to the left
  else if(left_sen.read() > lineStandard)
  {//right
  
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
  //data_sheet
  // if all sensors are on black or up in the air, stop the motors.
  // otherwise, run motors given the control speeds above.
  if((left_sen.read() > lineStandard) && (center_sen.read() > lineStandard) && (right_sen.read() > lineStandard) )
  {
    //stop
    
  }
  else
  {
  //any dir
    
  }
  delay(0);  // add a delay to decrease sensitivity.
}



