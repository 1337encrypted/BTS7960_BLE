/*
 * Motor 1 = R_EN1, L_EN1; RPWM1 = RPWM1, LPWM1 = LPWM1;
 * Motor 2 = R_EN2, L_EN2; RPWM2 = RPWM1, LPWM2 = LPWM1;
 * Motor 3 = R_EN3, L_EN3; RPWM3 = RPWM1, LPWM3 = LPWM1;
 * Motor 4 = R_EN4, L_EN4; RPWM4 = RPWM1, LPWM4 = LPWM1;
 * 
 * Initial spd is set to 0
 * 
 */

#ifndef BTS7960_BLE_H
#define BTS7960_BLE_H

//#define <Arduino.h>

class BTS7960_BLE
{
  private:

  //LED pins for function feedback
  #define redLed A0
  #define blueLed A1
  
  //Enable pins for the motor driver
  #define R_EN1 2
  #define L_EN1 4
  #define R_EN2 7
  #define L_EN2 8
//  #define R_IS1   Alarm pin
//  #define L_IS1   Alarm pin

  //PWM pins for the motor driver
  #define RPWM1 3
  #define LPWM1 6
  #define RPWM2 9
  #define LPWM2 10
//  #define R_IS2   Alarm pin
//  #define L_IS2   Alarm pin
  
  public:

  volatile int Speed;                 //volatile as it shouldn't be ignored by the compiler, speed variable to control the speed

  inline BTS7960_BLE() __attribute__((always_inline));
  inline void Stp() __attribute__((always_inline));
  inline void front() __attribute__((always_inline));
  inline void back() __attribute__((always_inline));
  inline void leftTurn() __attribute__((always_inline));
  inline void rightTurn() __attribute__((always_inline));
  inline void sharpLeftTurn() __attribute__((always_inline));
  inline void sharpRightTurn() __attribute__((always_inline));
//  inline void leftShift() __attribute__((always_inline));
//  inline void rightShift() __attribute__((always_inline));
};

BTS7960_BLE::BTS7960_BLE()
{
  // Led pins set as output
  pinMode(redLed, OUTPUT);
  pinMode(blueLed,OUTPUT);
  
  //Motor driver enable pins set as output and high 
  pinMode(R_EN1, OUTPUT);
  pinMode(L_EN1, OUTPUT);
  pinMode(R_EN2, OUTPUT);
  pinMode(L_EN2, OUTPUT);
  
  //PWM is for direction and speed
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);
   
  digitalWrite(R_EN1, HIGH);
  digitalWrite(L_EN1, HIGH);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH); 

  this->Speed=0;
}

void BTS7960_BLE::Stp()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,0);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,0);
//  analogWrite(RPWM3,0);
//  analogWrite(LPWM3,0);
//  analogWrite(RPWM4,0);
//  analogWrite(LPWM4,0);
}

void BTS7960_BLE::front()
{
  analogWrite(RPWM1,Speed);
  analogWrite(LPWM1,0);
  analogWrite(RPWM2,Speed);
  analogWrite(LPWM2,0);
//  analogWrite(RPWM3,Speed);
//  analogWrite(LPWM3,0);
//  analogWrite(RPWM4,Speed);
//  analogWrite(LPWM4,0);
}

void BTS7960_BLE::back()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
//  analogWrite(RPWM3,Speed);
//  analogWrite(LPWM3,0);
//  analogWrite(RPWM4,Speed);
//  analogWrite(LPWM4,0);
}

void BTS7960_BLE::rightTurn()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
//  analogWrite(RPWM3,0);
//  analogWrite(LPWM3,Speed);
//  analogWrite(RPWM4,0);
//  analogWrite(LPWM4,Speed);
}

void BTS7960_BLE::leftTurn()
{
  analogWrite(RPWM1,Speed);
  analogWrite(LPWM1,0);
  analogWrite(RPWM2,Speed);
  analogWrite(LPWM2,0);
//  analogWrite(RPWM3,Speed);
//  analogWrite(LPWM3,0);
//  analogWrite(RPWM4,Speed);
//  analogWrite(LPWM4,0);
}

/*
void BTS7960_BLE::rightShift()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,Speed);
  analogWrite(LPWM2,0);
  analogWrite(RPWM3,Speed);
  analogWrite(LPWM3,0);
  analogWrite(RPWM4,0);
  analogWrite(LPWM4,Speed);
}

void BTS7960_BLE::leftShift()
{
  analogWrite(RPWM1,Speed);
  analogWrite(LPWM1,0);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
  analogWrite(RPWM3,0);
  analogWrite(LPWM3,Speed);
  analogWrite(RPWM4,Speed);
  analogWrite(LPWM4,0);
}

/*
void BTS7960_BLE::rightDiagonal()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
  analogWrite(RPWM3,Speed);
  analogWrite(LPWM3,0);
  analogWrite(RPWM4,Speed);
  analogWrite(LPWM4,0);
}

void BTS7960_BLE::leftDiagonal()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
  analogWrite(RPWM3,Speed);
  analogWrite(LPWM3,0);
  analogWrite(RPWM4,Speed);
  analogWrite(LPWM4,0);
}
*/
#endif
