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

#include <IBusBM.h>
#include <Arduino.h>

class BTS7960TH9x
{
  private:

  //Encoder pins for the motors
  //#define ENCA 2             //Encoder A attached to interrupt pin 2
//  //#define ENCB 3             //Encoder B attached to interrupt pin 3
//  #define ENCC 18            //Encoder A attached to interrupt pin 2
//  #define ENCD 19            //Encoder B attached to interrupt pin 3
//  #define ENCE 25            //Encoder A attached to interrupt pin 2
//  #define ENCF 26            //Encoder B attached to interrupt pin 3
//  #define ENCG 27            //Encoder A attached to interrupt pin 2
//  #define ENCH 28            //Encoder B attached to interrupt pin 3

  //Enable pins for the motor driver
  #define R_EN1 2
  #define L_EN1 4
  #define R_EN2 7
   #define L_EN2 8
//  #define R_EN3 30
//  #define L_EN3 31
//  #define R_EN4 24
//  #define L_EN4 25

  //PWM pins for the motor driver
  #define RPWM1 3
  #define LPWM1 6
  #define RPWM2 9
  #define LPWM2 10
//  #define RPWM3 6
//  #define LPWM3 7
//  #define RPWM4 8
//  #define LPWM4 9
  
  //Alarm pins
  /*
  #define R_IS1
  #define L_IS1
  #define R_IS2
  #define L_IS2
  #define R_IS3
  #define L_IS3
  #define R_IS4
  #define L_IS4
  */
  
  public:

  volatile int Speed;                 //volatile as it shouldn't be ignored by the compiler, speed variable to control the speed
  /*
  volatile int pos;                   //Position variable to count the encoder steps
  volatile long prevT;                //Previous time
  volatile float eprev;
  volatile float eintegral;

  */
  inline BTS7960TH9x() __attribute__((always_inline));
  inline void Stp() __attribute__((always_inline));
  inline void front() __attribute__((always_inline));
  inline void back() __attribute__((always_inline));
  inline void leftTurn() __attribute__((always_inline));
  inline void rightTurn() __attribute__((always_inline));
//  inline void leftShift() __attribute__((always_inline));
//  inline void rightShift() __attribute__((always_inline));
};

BTS7960TH9x::BTS7960TH9x()
{
  //Motor driver enable pins set as output and high 
  pinMode(R_EN1, OUTPUT);
  pinMode(L_EN1, OUTPUT);
  pinMode(R_EN2, OUTPUT);
  pinMode(L_EN2, OUTPUT);
//  pinMode(R_EN3, OUTPUT);
//  pinMode(L_EN3, OUTPUT);
//  pinMode(R_EN4, OUTPUT);
//  pinMode(L_EN4, OUTPUT);
//   

  //PWM is for direction and speed
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);
//  pinMode(RPWM3, OUTPUT);
//  pinMode(LPWM3, OUTPUT);
//  pinMode(RPWM4, OUTPUT);
//  pinMode(LPWM4, OUTPUT);

  //Encoder pins 
  //pinMode(ENCA, INPUT);                 //Encoder set as input
  //pinMode(ENCB, INPUT);                 //Encoder set as input
  /*
  pinMode(ENCC, INPUT);                 //Encoder set as input
  pinMode(ENCD, INPUT);                 //Encoder set as input
  pinMode(ENCE, INPUT);                 //Encoder set as input
  pinMode(ENCF, INPUT);                 //Encoder set as input
  pinMode(ENCG, INPUT);                 //Encoder set as input
  pinMode(ENCH, INPUT);                 //Encoder set as input
   */
   
  //attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);

  digitalWrite(R_EN1, HIGH);
  digitalWrite(L_EN1, HIGH);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH);
//  digitalWrite(R_EN3, HIGH);
//  digitalWrite(L_EN3, HIGH);
//  digitalWrite(R_EN4, HIGH);
//  digitalWrite(L_EN4, HIGH); 

  this->Speed=0;
}

/*
void BTS7960TH9x:: readEncoder()
{
  int temp = digitalRead(ENCA);
  if(temp>0)
    pos++;
   else
    pos--;
}
*/

void BTS7960TH9x::Stp()
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

void BTS7960TH9x::front()
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

void BTS7960TH9x::back()
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

void BTS7960TH9x::rightTurn()
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

void BTS7960TH9x::leftTurn()
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
void BTS7960TH9x::rightShift()
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

void BTS7960TH9x::leftShift()
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
void BTS7960TH9x::rightDiagonal()
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

void BTS7960TH9x::leftDiagonal()
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
