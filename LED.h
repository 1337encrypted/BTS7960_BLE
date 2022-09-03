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
  uint8_t ledPin;

  public:
  //uint8_t pwm;
  
  //Function prototypes
  inline led() __attribute__((always_inline));
  inline led(uint8_t) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void on() __attribute__((always_inline));
  inline void off() __attribute__((always_inline));
  inline void toggle() __attribute__((always_inline));
};

//Default constructor
led::led()
{
  //Initilize the ledPin pins
  this->ledPin = 13;
  //this->pwm = 255;
}

//parametrized constructor
led::led(uint8_t ledPin)
{
  //Initilize the ledPin pins
  this->ledPin = ledPin;
  //this->pwm = pwm;
}

void led::begin()
{
  // ledPin pins set as output
  pinMode(ledPin, OUTPUT);
}

void led::on()
{
  digitalWrite(ledPin, HIGH); 
}

void led::off()
{
  digitalWrite(ledPin, LOW);
}

void led::toggle()
{
  static unsigned long ledMillis = millis();                    //Assigns the current snapshot of time only the first
                                                                //time this code executes
  if(millis() - ledMillis > 700)
  {
    digitalWrite(ledPin, !digitalRead(ledPin));
    ledMillis = millis();  
  }
}
#endif  //END led_h
