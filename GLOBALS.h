//#include <LibPrintf.h> 
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

//state for switch case
uint8_t state;                                                

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
led redLed(redLedPin);                                    //Create object for red led
led blueLed(blueLedPin);                                  //Create object for blue led
buzzer buzz(buzzpin);                                                 //Create object for buzzer
/*======================================================================================================================================*/

/*==================================================Function prototyping section========================================================*/
inline void initSystem();
/*======================================================================================================================================*/


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++STATES+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define FRONT 'F'
#define BACK 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define LEFTSHIFT 'G'
#define RIGHTSHIFT 'I'
#define BACKLEFT 'H'
#define BACKRIGHT 'J'
#define STOP 'S'
#define STOPALL 'D'
#define FRONTLIGHTSON 'W'
#define FRONTLIGHTSOFF 'w'
#define BACKLIGHTSON 'U'
#define BACKLIGHTSOFF 'u'
#define HORNON 'V'
#define HORNOFF 'v'
#define EXTRAON 'X'
#define EXTRAOFF 'x'
#define SPEED0 '0'
#define SPEED1 '1'
#define SPEED2 '2'
#define SPEED3 '3'
#define SPEED4 '4'
#define SPEED5 '5'
#define SPEED6 '6'
#define SPEED7 '7'
#define SPEED8 '8'
#define SPEED9 '9'
#define MAXSPEED 'q'

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

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
