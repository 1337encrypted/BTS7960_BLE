/*Cannot create a .cpp file as inline prototypes need the function to be present in the same file as they are defined*/
#ifndef buzzer_h
#define buzzer_h

#if (ARDUINO >= 100) 
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class buzzer
{
  private:
  //buzzer for low speed feedback
  uint8_t buzzpin;

  public:
  //Function prototype
  inline buzzer() __attribute__((always_inline));
  inline buzzer(uint8_t) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void initBuzzer() __attribute__((always_inline));
  inline void on() __attribute__((always_inline));
  inline void off() __attribute__((always_inline));
};


//Default constructor
buzzer::buzzer()
{
  //Initilize the buzzer
  this->buzzpin = A5;
  //__initBuzzer();
}

//Parametrized constructor
buzzer::buzzer(uint8_t buzzpin)
{
  //Initilize the buzzer
  this->buzzpin = buzzpin;
  //__initBuzzer();
}

void buzzer::begin()
{
  //buzzer pin as output
  pinMode(buzzpin, OUTPUT);
}

void buzzer::initBuzzer()
{
  //InitBuzzer is for active buzzer
  tone(buzzpin, 3000, 500);
  delay(800);
  tone(buzzpin, 3000, 500);
  delay(800);
  noTone(buzzpin);
}

void buzzer::on()
{
  digitalWrite(buzzpin, HIGH);
  //delay(1000);
}


void buzzer::off()
{
  digitalWrite(buzzpin, LOW);  
}

#endif  //END BUZZER_H
