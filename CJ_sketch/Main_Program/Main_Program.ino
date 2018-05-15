/* Arduino main program for running line follower robot.
 *  
 *  
 */
#define LED_PIN 13

A4990MotorShield motors;

/* 
 * For safety, it is good practice to monitor motor driver faults and handle
 * them in an appropriate way. If a fault is detected, both motor speeds are set
 * to zero and it is reported on the serial port.
 */
void stopIfFault()
{
  if (motors.getFault())
  {
    motors.setSpeeds(0,0);
    Serial.println("Fault");
    while(1);
  }
}
 
