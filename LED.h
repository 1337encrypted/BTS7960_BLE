/*Cannot create a .cpp file as inline prototypes need the function to be present in the same file as they are defined*/
#ifndef led_h
#define led_h

#if (ARDUINO >= 100) 
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class led
{
  private:
  //ledPin pins for function feedback
  byte ledPin;

  public:
  uint8_t pwm;
  
  //Function prototypes
  inline led() __attribute__((always_inline));
  inline led(byte, uint8_t) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void ledOn() __attribute__((always_inline));
  inline void ledOff() __attribute__((always_inline));
};

//Default constructor
led::led()
{
  //Initilize the ledPin pins
  this->ledPin = 13;
  this->pwm = 255;
}

//parametrized constructor
led::led(byte ledPin, uint8_t pwm)
{
  //Initilize the ledPin pins
  this->ledPin = ledPin;
  this->pwm = pwm;
}

void led::begin()
{
  // ledPin pins set as output
  pinMode(ledPin, OUTPUT);
}

void led::ledOn()
{
  analogWrite(ledPin, pwm); 
}

void led::ledOff()
{
  digitalWrite(ledPin, LOW);
}
#endif  //END led_h
