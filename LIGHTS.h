#ifndef LIGHTS_H
#define LIGHTS_H

#include <Arduino.h>

class lights
{
  private:
  //LED pins for function feedback
  byte redLed;
  byte blueLed; 

  public:
  //Function prototypes
  inline lights() __attribute__((always_inline));
  inline lights(byte, byte) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void lightsOn() __attribute__((always_inline));
  inline void lightsOff() __attribute__((always_inline));
  inline void runMotors(uint8_t) __attribute__((always_inline));
  inline void stopMotors(uint8_t) __attribute__((always_inline));
};
//Default constructor
lights::lights()
{
  //Initilize the led pins
  this->redLed = 10;
  this->blueLed = 11;
}

//parametrized constructor
lights::lights(byte redLed, byte blueLed)
{

  //Initilize the led pins
  this->redLed = redLed;
  this->blueLed = blueLed;
}

void lights::begin()
{
  // Led pins set as output
  pinMode(redLed, OUTPUT);
  pinMode(blueLed,OUTPUT);

  //Initlize the LED's
  //__initLights();
}

void lights::lightsOn()
{
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, HIGH);  
}

void lights::lightsOff()
{
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
}

void lights::runMotors(uint8_t Speed)
{
  //LED's
  digitalWrite(redLed, LOW);
  analogWrite(blueLed, Speed);
}

void lights::stopMotors(uint8_t Speed)
{
  //LED's
  analogWrite(redLed, Speed);
  digitalWrite(blueLed, LOW);
}
  
#endif  //END LIGHTS_h
