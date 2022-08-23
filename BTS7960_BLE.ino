#include "GLOBALS.h"

BTS7960 motor1(L_EN1, R_EN1, LPWM1, RPWM1);                           //Create an object of class motor1
BTS7960 motor2(L_EN2, R_EN2, LPWM2, RPWM2);                           //Create an object of class motor2
led redLed(redLedPin, motor1.pwm);                                    //Create object for red led
led blueLed(blueLedPin, motor1.pwm);                                  //Create object for blue led
buzzer buzz(buzzpin);                                                 //Create object for buzzer
uint8_t key;                                                          //Key for the switch case

/*================================================Function prototyping section=======================================================*/
inline void initSystem();
/*===================================================================================================================================*/


void initSystem()
{
  motor1.enable();                                                    //Makes all enable pins go high
  motor2.enable();                                                    //Makes all enable pins go high
  blueLed.ledOn();                                                    //Turns the blue led on
  redLed.ledOn();                                                     //Turns the red led on
  buzz.initBuzzer();                                                  //puts the buzzer on
  delay(2);
  blueLed.ledOff();                                                   //Turns the blue led on
  redLed.ledOff();                                                    //Turns the red led on
  buzz.buzzOff();                                                     //Shutsdown the buzzer
}

void setup(){
  Serial.begin(9600);
  motor1.begin();
  motor2.begin();
  redLed.begin();
  blueLed.begin();
  buzz.begin();

  //initilize the system by turing on the leds and buzzer
  initSystem();
}

void loop()
{
  blueLed.ledOn();
  redLed.ledOff();
  motor1.Stp();
  motor2.Stp();
  if (Serial.available())
  {  
    key=Serial.read();
    switch(key)
    {
      case 'F':
      blueLed.ledOn();
      redLed.ledOff();
      motor1.front();
      motor2.front();
      debug("Foreward: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case 'B':
      blueLed.ledOn();
      redLed.ledOff();
      motor1.back();
      motor2.back();
      debugln("Backward");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case 'L':
      blueLed.ledOn();
      redLed.ledOff();
      motor1.back();
      motor2.front();
      debugln("Left");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case 'R':
      blueLed.ledOn();
      redLed.ledOff();
      motor1.front();
      motor2.back();
      debugln("Right");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      /*
      case 'I':
      blueLed.ledOn();
      redLed.ledOff();
      //motor1.
      debugln("Right Shift");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case 'G':
      blueLed.ledOn();
      redLed.ledOff();
      //motor1.
      debugln("Left Shift");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      */
      
      case '0':
      buzz.buzzOn();
      motor1.pwm = 115;
      motor2.pwm = 115;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case '1':
      buzz.buzzOff();
      motor1.pwm = 130;
      motor2.pwm = 130;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case '2':
      buzz.buzzOff();
      motor1.pwm = 143;
      motor2.pwm = 143;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case '3':
      buzz.buzzOff();
      motor1.pwm = 157;
      motor2.pwm = 157;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case '4':
      buzz.buzzOff();
      motor1.pwm = 170;
      motor2.pwm = 170;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case '5':
      buzz.buzzOff();
      motor1.pwm = 185;
      motor2.pwm = 185;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case '6':
      buzz.buzzOff();
      motor1.pwm = 200;
      motor2.pwm = 200;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case '7':
      buzz.buzzOff();
      motor1.pwm = 213;
      motor2.pwm = 213;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case '8':
      buzz.buzzOff();
      motor1.pwm = 227;
      motor2.pwm = 227;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case '9':
      buzz.buzzOff();
      motor1.pwm = 240;
      motor2.pwm = 240;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      case 'q':
      buzz.buzzOff();
      motor1.pwm = 255;
      motor2.pwm = 255;
      debugln("Speed: ");
      debug(motor1.pwm);
      debug(" : ");
      debugln(motor2.pwm);
      break;
      
      default: 
      debugln("Invalid input, please choose 1 - 9,q");
      break;
    }
  }
}
