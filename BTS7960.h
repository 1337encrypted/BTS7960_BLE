/*
 * Motor 1 = R_EN1, L_EN1; RPWM1 = RPWM1, LPWM1 = LPWM1;
 * Motor 2 = R_EN2, L_EN2; RPWM2 = RPWM1, LPWM2 = LPWM1;
 * Motor 3 = R_EN3, L_EN3; RPWM3 = RPWM1, LPWM3 = LPWM1;
 * Motor 4 = R_EN4, L_EN4; RPWM4 = RPWM1, LPWM4 = LPWM1;
 * 
 * Initial spd is set to 0
 * 
 */

#ifndef BTS7960_H
#define BTS7960_H

//#define <Arduino.h>

class BTS7960
{
  private:
  //BTS7960 1 module
  byte L_EN1,R_EN1,LPWM1,RPWM1;                                 //L_IS1,R_IS1 are not included
  
  //BTS7960 2 module
  byte L_EN2,R_EN2,LPWM2,RPWM2;                                 //L_IS2,R_IS2 are not included
  
  public:
  volatile uint8_t Speed;                                       //volatile as it shouldn't be ignored by the compiler, speed variable to control the speed
/*================================================Functin prototyping section========================================================*/
  inline BTS7960() __attribute__((always_inline));
  inline BTS7960(byte,byte,byte,byte,byte,byte,byte,byte) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void Stp() __attribute__((always_inline));
  inline void front() __attribute__((always_inline));
  inline void back() __attribute__((always_inline));
  inline void leftTurn() __attribute__((always_inline));
  inline void rightTurn() __attribute__((always_inline));
  inline void sharpLeftTurn() __attribute__((always_inline));
  inline void sharpRightTurn() __attribute__((always_inline));
//  inline void leftShift() __attribute__((always_inline));
//  inline void rightShift() __attribute__((always_inline));
/*===================================================================================================================================*/
};

//Default constructor
BTS7960::BTS7960()
{

  //Motor driver 1 pin definitions
  this->L_EN1 = 2;
  this->L_EN1 = 4;
  this->LPWM1 = 3;
  this->RPWM1 = 5;
  //this->L_IS1 = L_IS1   //Alarm pin
  //this->R_IS1 = R_IS1   //Alarm pin

  //Motor driver 2 pin definitions
  this->L_EN2 = 7;
  this->L_EN2 = 8;
  this->LPWM2 = 6;
  this->RPWM2 = 9;
  //this->L_IS2 = L_IS2   //Alarm pin
  //this->R_IS2 = R_IS2   //Alarm pin

  this->Speed = 255;
}

//Parametrised constructor
BTS7960::BTS7960(byte L_EN1, byte R_EN1, byte LPWM1, byte RPWM1, byte L_EN2, byte R_EN2, byte LPWM2, byte RPWM2)
{
  //Motor driver 1 pin definitions
  this->L_EN1 = L_EN1;
  this->L_EN1 = R_EN1;
  this->LPWM1 = LPWM1;
  this->RPWM1 = RPWM1;
  //this->L_IS1 = L_IS1   //Alarm pin
  //this->R_IS1 = R_IS1   //Alarm pin

  //Motor driver 2 pin definitions
  this->L_EN2 = L_EN2;
  this->L_EN2 = R_EN2;
  this->LPWM2 = LPWM2;
  this->RPWM2 = RPWM2;
  //this->L_IS2 = L_IS2   //Alarm pin
  //this->R_IS2 = R_IS2   //Alarm pin

  //Set the global speed variable to 255 
  this->Speed = 255;
}


void BTS7960::begin()
{
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

  //Setting the BTS7960 enable pins high
  digitalWrite(R_EN1, HIGH);
  digitalWrite(L_EN1, HIGH);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH);
}

void BTS7960::Stp()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,0);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,0);
}

void BTS7960::front()
{
  analogWrite(RPWM1,Speed);
  analogWrite(LPWM1,0);
  analogWrite(RPWM2,Speed);
  analogWrite(LPWM2,0);
}

void BTS7960::back()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
}

void BTS7960::rightTurn()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
}

void BTS7960::leftTurn()
{
  analogWrite(RPWM1,Speed);
  analogWrite(LPWM1,0);
  analogWrite(RPWM2,Speed);
  analogWrite(LPWM2,0);
}

/*
void BTS7960::rightShift()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,Speed);
  analogWrite(LPWM2,0);
}

void BTS7960::leftShift()
{
  analogWrite(RPWM1,Speed);
  analogWrite(LPWM1,0);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
}

/*
void BTS7960::rightDiagonal()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
}

void BTS7960::leftDiagonal()
{
  analogWrite(RPWM1,0);
  analogWrite(LPWM1,Speed);
  analogWrite(RPWM2,0);
  analogWrite(LPWM2,Speed);
}
*/
#endif
