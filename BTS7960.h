/*Cannot create a .cpp file as inline prototypes need the function to be present in the same file as they are defined*/
#ifndef BTS7960_H
#define BTS7960_H

class BTS7960
{
  private:

  //L_IS1,R_IS1 are not included
  byte L_EN;
  byte R_EN;
  byte L_PWM;
  byte R_PWM;
  
  public:
  volatile uint8_t pwm;                                       //pwm variable to control the speed of motor
/*================================================Functin prototyping section========================================================*/
  inline BTS7960() __attribute__((always_inline));
  inline BTS7960(byte, byte, byte, byte) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void enable() __attribute__((always_inline));
  inline void disable() __attribute__((always_inline));
  inline void Stp() __attribute__((always_inline));
  inline void front() __attribute__((always_inline));
  inline void back() __attribute__((always_inline));
  //inline void print() __attribute__((always_inline));
/*===================================================================================================================================*/
};

//Default constructor
BTS7960::BTS7960()
{
  //Motor driver 1 pin definitions
  this->L_EN = 2;
  this->L_EN = 4;
  this->L_PWM = 3;
  this->R_PWM = 5;
  //this->L_IS1 = L_IS1   //Alarm pin
  //this->R_IS1 = R_IS1   //Alarm pin

  //Set the global pwm variable to 255 
  this->pwm = 255;
}

//Parametrised constructor
BTS7960::BTS7960(byte L_EN, byte R_EN, byte L_PWM, byte R_PWM)
{
  //Motor driver 1 pin definitions
  this->L_EN = L_EN;
  this->L_EN = R_EN;
  this->L_PWM = L_PWM;
  this->R_PWM = R_PWM;
  //this->L_IS1 = L_IS1   //Alarm pin
  //this->R_IS1 = R_IS1   //Alarm pin

  //Set the global pwm variable to 255 
  this->pwm = 255;
}

void BTS7960::enable()
{
  //Setting the BTS7960 enable pins high
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
}

void BTS7960::disable()
{
  //Setting the BTS7960 enable pins high
  digitalWrite(R_EN, LOW);
  digitalWrite(L_EN, LOW);
}

void BTS7960::begin()
{
  //Motor driver enable pins set as output and high 
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  
  //PWM is for direction and pwm
  pinMode(R_PWM, OUTPUT);
  pinMode(L_PWM, OUTPUT);
}

void BTS7960::Stp()
{
  analogWrite(R_PWM,0);
  analogWrite(L_PWM,0);
}

void BTS7960::front()
{
  analogWrite(R_PWM,pwm);
  delayMicroseconds(100);
  analogWrite(L_PWM,0);
  delayMicroseconds(100);
}

void BTS7960::back()
{
  analogWrite(R_PWM,0);
  delayMicroseconds(100);
  analogWrite(L_PWM,pwm);
  delayMicroseconds(100);
}
#endif  //END BTS7960_H
