#include "GLOBALS.h"

void setup()
{
  Serial.begin(9600);
  motor1.begin();
  motor2.begin();
  redLed.begin();
  blueLed.begin();
  buzz.begin();

//initilize the system by turing on the leds and buzzer
//  initSystem();
}

void loop()
{     
  
/*==========================================================ROBOT STATE MACHINE========================================================*/  
  switch(motorStatus)
  {
    case motorStates::FRONT:
    motor1.front();
    motor2.front();
    debug("Front: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::PASS;
    ledStatus = ledStates::RUN;
    break;
    
    case motorStates::BACK:
    motor1.back();
    motor2.back();
    debug("Back: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::PASS;
    ledStatus = ledStates::RUN;
    break;
    
    case motorStates::LEFT:
    motor1.back();
    motor2.front();
    debug("Left: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::PASS;
    ledStatus = ledStates::RUN;
    break;
    
    case motorStates::RIGHT:
    motor1.front();
    motor2.back();
    debug("Right: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::PASS;
    ledStatus = ledStates::RUN;
    break;
         
    case motorStates::RIGHTSHIFT:
    motor1.front();
    motor2.stop();
    debug("Right shift: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::PASS;
    ledStatus = ledStates::RUN;
    break;
    
    case motorStates::LEFTSHIFT:
    motor1.stop();
    motor2.front();
    debug("Left shift: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::PASS;
    ledStatus = ledStates::RUN;
    break;
   
    case motorStates::BACKRIGHT:
    motor1.stop();
    motor2.back();
    debug("Right Back: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::PASS;
    ledStatus = ledStates::RUN;
    break;
    
    case motorStates::BACKLEFT:
    motor1.back();
    motor2.stop();
    debug("Left Back: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::PASS;
    ledStatus = ledStates::RUN;
    break;

    case motorStates::STOP:
    motor1.stop();
    motor2.stop();
    debug("Stop: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::PASS;
    ledStatus = ledStates::STOP;
    break;
    
    case motorStates::SPEED0:
    motor1.pwm = motor2.pwm = 0;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::ON;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::SPEED1:
    motor1.pwm = motor2.pwm = 25;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::SPEED2:
    motor1.pwm = motor2.pwm = 51;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::SPEED3:
    motor1.pwm = motor2.pwm = 76;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::SPEED4:
    motor1.pwm = motor2.pwm = 102;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::SPEED5:
    motor1.pwm = motor2.pwm = 127;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::SPEED6:
    motor1.pwm = motor2.pwm = 153;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::SPEED7:
    motor1.pwm = motor2.pwm = 178;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::SPEED8:
    motor1.pwm = motor2.pwm = 204;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::SPEED9:
    motor1.pwm = motor2.pwm = 229;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;
    
    case motorStates::MAXSPEED:
    motor1.pwm = motor2.pwm = 255;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    buzzStatus = buzzStates::OFF;
    ledStatus = ledStates::PASS;
    break;

    case motorStates::STOPALL:
    standbySystem();
    while(true)
    {
      if(Serial.available())
      {
        initSystem();
        break;
      }
      else
        redLed.toggle();
    }
    break;

    case motorStates::EXTRAON:                            //Same as EXTRAOFF
    standbySystem();
    while(true)
    {
      motorStatus = (motorStates)Serial.read();
      if(motorStates::EXTRAOFF == motorStatus)
      {
        initSystem();
        break;
      }
      else if(motorStates::STOPALL == motorStatus)
      {
        break;
      }
      else
        redLed.toggle();
    }
    break;
    
    case motorStates::EXTRAOFF:                           //Same as EXTRAON
    standbySystem();
    while(true)
    {
      motorStatus = (motorStates)Serial.read();
      if(motorStates::EXTRAOFF == motorStatus)
      {
        initSystem();
        break;
      }
      else if(motorStates::STOPALL == motorStatus)
      {
        break;
      }
      else
        redLed.toggle();
    }
    break;

    case motorStates::FRONTLIGHTSON:
    //Do nothing for now
    break;
    case motorStates::FRONTLIGHTSOFF:
    //Do nothing for now
    break;
    case motorStates::BACKLIGHTSON:
    //Do nothing for now
    break;
    case motorStates::BACKLIGHTSOFF:
    //Do nothing for now
    break;
    case motorStates::HORNON:
    //Do nothing for now
    break;
    case motorStates::HORNOFF:
    //Do nothing for now
    break;

    default: debugln("Invalid input");
  }

/*==========================================================BUZZER STATE MACHINE========================================================*/
  switch(buzzStatus)
  {
    case buzzStates::ON:
    buzz.on();
    break;

    case buzzStates::OFF:
    buzz.off();
    break;

    case buzzStates::PASS:
    //Do nothing
    break;

    default: debugln("Invalid input");
  }

/*===========================================================LED STATE MACHINE=========================================================*/
  switch(ledStatus)
  {
    case ledStates::STOP:
    blueLed.off();
    redLed.on();
    break;
    
    case ledStates::RUN:
    blueLed.on();
    redLed.off();
    break;

    case ledStates::PASS:
    //Do nothing
    break;

    default: debugln("Invalid input");
  }
  
  if (Serial.available()) 
    motorStatus = (motorStates)Serial.read();        //Read the state
}
