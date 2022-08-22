#include "BTS7960.h"
#include "BUZZER.h"
#include "LIGHTS.h"

//BTS7960 motor driver 2 pin definitions
#define R_EN1 2
#define L_EN1 4
#define RPWM1 3   //PWM 490hz
#define LPWM1 5   //PWM 980hz
//#define R_IS1   //Alarm pin
//#define L_IS1   //Alarm pin

//BTS7960 motor driver 2 pin definitions
#define R_EN2 7
#define L_EN2 8
#define RPWM2 6   //PWM 980hz
#define LPWM2 9   //PWM 490hz
//#define R_IS2   //Alarm pin
//#define L_IS2   //Alarm pin

//Led definition section
#define redLed 10
#define blueLed 11

//Buzzer definition section
#define buzzpin A5

BTS7960 motor1(L_EN1, R_EN1, LPWM1, RPWM1);                           //Create an object of class motor1
BTS7960 motor2(L_EN2, R_EN2, LPWM2, RPWM2);                           //Create an object of class motor2
lights light(redLed,blueLed);                                         //Create object for light
buzzer buzz(buzzpin);                                                 //Create object for buzzer
uint8_t key;                                                          //Key for the switch case

/*================================================Functin prototyping section========================================================*/
inline void initSystem();
/*===================================================================================================================================*/


void initSystem()
{
  motor1.enable_BTS7960();                                            //Makes all enable pins go high
  motor2.enable_BTS7960();                                            //Makes all enable pins go high
  light.lightsOn();                                                   //Turns all the lights on
  buzz.initBuzzer();                                                  //puts the buzzer on
  delay(2);
  light.stopMotors(motor1.pwm);                                       //Keeprs red led on while making blue go off
  buzz.buzzOff();                                                     //Shutsdown the buzzer
}

void setup(){
  Serial.begin(9600);
  motor1.begin();
  motor2.begin();
  light.begin();
  buzz.begin();

  //initilize the system by turing on the lights and buzzer
  initSystem();
}

void loop()
{
  if (Serial.available())
  {  
    key=Serial.read();
    light.stopMotors(motor1.pwm);
    motor1.Stp();
    motor2.Stp();
    switch(key)
    {
      case 'F':
      light.runMotors(motor1.pwm);
      motor1.front();
      motor2.front();
      Serial.println("Foreward");
      break;
      
      case 'B':
      light.runMotors(motor1.pwm);
      motor1.back();
      motor2.back();
      Serial.println("Backward");
      break;
      
      case 'L':
      light.runMotors(motor1.pwm);
      motor1.back();
      motor2.front();
      Serial.println("Left");
      break;
      
      case 'R':
      light.runMotors(motor1.pwm);
      motor1.front();
      motor2.back();
      Serial.println("Right");
      break;
      
      /*
      case 'I':
      light.runMotors(Speed);
      //motor1.
      Serial.println("Right Shift");
      break;
      
      case 'G':
      light.runMotors(Speed);
      //motor1.
      Serial.println("Left Shift");
      break;
      */
      
      case '0':
      buzz.buzzOn();
      motor1.pwm = 115;
      motor2.pwm = 115;
      Serial.println("motor1.pwm = 115");
      break;
      
      case '1':
      buzz.buzzOff();
      motor1.pwm = 130;
      motor2.pwm = 130;
      Serial.println("motor1.pwm = 130");
      break;
      
      case '2':
      buzz.buzzOff();
      motor1.pwm = 143;
      motor2.pwm = 143;
      Serial.println("motor1.pwm = 143");
      break;
      
      case '3':
      buzz.buzzOff();
      motor1.pwm = 157;
      motor2.pwm = 157;
      Serial.println("motor1.pwm = 157");
      break;
      
      case '4':
      buzz.buzzOff();
      motor1.pwm = 170;
      motor2.pwm = 170;
      Serial.println("motor1.pwm = 170");
      break;
      
      case '5':
      buzz.buzzOff();
      motor1.pwm = 185;
      motor2.pwm = 185;
      Serial.println("motor1.pwm = 185");
      break;
      
      case '6':
      buzz.buzzOff();
      motor1.pwm = 200;
      motor2.pwm = 200;
      Serial.println("motor1.pwm = 200");
      break;
      
      case '7':
      buzz.buzzOff();
      motor1.pwm = 213;
      motor2.pwm = 213;
      Serial.println("motor1.pwm = 213");
      break;
      
      case '8':
      buzz.buzzOff();
      motor1.pwm = 227;
      motor2.pwm = 227;
      Serial.println("motor1.pwm = 227");
      break;
      
      case '9':
      buzz.buzzOff();
      motor1.pwm = 240;
      motor2.pwm = 240;
      Serial.println("motor1.pwm = 240");
      break;
      
      case 'q':
      buzz.buzzOff();
      motor1.pwm = 255;
      motor2.pwm = 255;
      Serial.println("motor1.pwm = 255");
      break;
      
      default: 
      Serial.println("Invalid input, please choose 1 - 9,q");
      break;
    }
  }
}
