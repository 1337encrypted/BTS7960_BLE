#include "BTS7960.h"
#include "BUZZER.h"
#include "LIGHTS.h"

#define DEBUG 0

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

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
