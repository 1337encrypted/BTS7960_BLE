#include "BTS7960.h"
#include "BUZZER.h"
#include "LED.h"

/* 
 * Debug on and off enables code optimization
 * DEBUG 0 will ignore all Serial.print functions
 * DEBUG 1 will will add back Serial.print functions back to the code
 */
 
#define DEBUG 1

#if DEBUG == 1
  #define debug(x) Serial.print(x)
  #define debugln(x) Serial.println(x)
#else
  #define debug(x)
  #define debugln(x) 
#endif

//Led definition section
#define redLedPin A4  //use between 150 ohms to 330 ohms resistor
#define blueLedPin 3

//Buzzer definition section
#define buzzpin 2 //Active buzzer use 100 ohms resistor

//BTS7960 motor driver 2 pin definitions
#define R_EN1 7
#define L_EN1 8
#define RPWM1 6   //PWM 490hz
#define LPWM1 5   //PWM 980hz
//#define R_IS1   //Alarm pin
//#define L_IS1   //Alarm pin

//BTS7960 motor driver 2 pin definitions
#define R_EN2 A0
#define L_EN2 A1
#define RPWM2 9   //PWM 980hz
#define LPWM2 10  //PWM 490hz
//#define R_IS2   //Alarm pin
//#define L_IS2   //Alarm pin                                                     //Key for the switch case

/*=====================================================  Object declaration=============================================================*/
BTS7960 motor1(L_EN1, R_EN1, LPWM1, RPWM1);                           //Create an object of class motor1
BTS7960 motor2(L_EN2, R_EN2, RPWM2, LPWM2);                           //Create an object of class motor2 should have been LPWM2, RPWM2
led redLed(redLedPin);                                                //Create object for red led
led blueLed(blueLedPin);                                              //Create object for blue led
buzzer buzz(buzzpin);                                                 //Create object for buzzer

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++MOTOR STATES++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

enum class motorStates : uint8_t
{
   FRONT = 'F',
   BACK = 'B',
   LEFT = 'L',
   RIGHT = 'R',
   LEFTSHIFT = 'G',
   RIGHTSHIFT = 'I',
   BACKLEFT = 'H',
   BACKRIGHT = 'J',
   STOP = 'S',
   STOPALL = 'D',
   FRONTLIGHTSON = 'W',
   FRONTLIGHTSOFF = 'w',
   BACKLIGHTSON = 'U',
   BACKLIGHTSOFF = 'u',
   HORNON = 'V',
   HORNOFF = 'v',
   EXTRAON = 'X',
   EXTRAOFF = 'x',
   SPEED0 = '0',
   SPEED1 = '1',
   SPEED2 = '2',
   SPEED3 = '3',
   SPEED4 = '4',
   SPEED5 = '5',
   SPEED6 = '6',
   SPEED7 = '7',
   SPEED8 = '8',
   SPEED9 = '9',
   MAXSPEED = 'q'
};

enum class buzzStates : uint8_t
{
  OFF,
  ON,
  PASS
};

enum class ledStates : uint8_t
{
  STOP,
  RUN,
  PASS
};

motorStates motorStatus = motorStates::STOPALL;                   //State variable set to STOP initially
//motorStates motorPrevStatus;                                    //Previous motor state
buzzStates buzzStatus = buzzStates::PASS;                         //Buzzer state initilally is set to pass
ledStates ledStatus = ledStates::PASS;                            //Led state initilally is set to pass

/*==================================================Function prototyping section========================================================*/
inline void initSystem() __attribute__((always_inline));
inline void standbySystem() __attribute__((always_inline));

/*======================================================================================================================================*/

void initSystem()
{
  debugln("System initlized, waiting for bluetooth connection...");
  motor1.enable();                                                 //Makes all enable pins go high
  motor2.enable();                                                 //Makes all enable pins go high
  blueLed.on();                                                    //Turns the blue led on
  redLed.on();                                                     //Turns the red led on
  buzz.initBuzzer();                                               //puts the buzzer on
  delay(2);
  blueLed.off();                                                   //Turns the blue led on
  redLed.on();                                                     //Turns the red led on
  motorStatus = motorStates::STOP;                                 //State variable set to STOP initially
  buzzStates buzzStatus = buzzStates::PASS;                        //Buzzer state initilally is set to pass
  ledStates ledStatus = ledStates::STOP;                           //Led state initilally is set to pass 
}

void standbySystem()
{
  debugln("Bluetooth disconnected...");
  blueLed.off();
  redLed.off();
  motor1.disable();
  motor2.disable();
  buzz.deinitBuzzer();  
}



//namespace light
//{
//  void stopMotors()
//  {
//    redLed.ledOff();
//    blueLed.ledOff();  
//  }
//  
//  void runMotors()
//  {
//    redLed.ledOn();
//    blueLed.ledOn();
//  }
//}
