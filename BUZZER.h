/*Cannot create a .cpp file as inline prototypes need the function to be present in the same file as they are defined*/
#ifndef BUZZER_H
#define BUZZER_H

class buzzer
{
  private:
  //buzzer for low speed feedback
  byte buzzpin;

  public:
  //Function prototype
  inline buzzer() __attribute__((always_inline));
  inline buzzer(byte) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void initBuzzer() __attribute__((always_inline));
  inline void buzzOn() __attribute__((always_inline));
  inline void buzzOff() __attribute__((always_inline));
};


//Default constructor
buzzer::buzzer()
{
  //Initilize the buzzer
  this->buzzpin = A5;
  //__initBuzzer();
}

//Parametrized constructor
buzzer::buzzer(byte buzzpin)
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
  digitalWrite(buzzpin, HIGH); 
}

void buzzer::buzzOn()
{
  digitalWrite(buzzpin, HIGH);  
}


void buzzer::buzzOff()
{
  digitalWrite(buzzpin, LOW);  
}

#endif  //END BUZZER_H
