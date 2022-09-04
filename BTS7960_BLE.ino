#include "GLOBALS.h"

void initSystem()
{
  debugln("System initlized, waiting for bluetooth connection...");
  motor1.enable();                                                 //Makes all enable pins go high
  motor2.enable();                                                 //Makes all enable pins go high
  blueLed.on();                                                    //Turns the blue led on
  redLed.on();                                                     //Turns the red led on
  buzz.initBuzzer();                                               //puts the buzzer on
  delay(2);
  blueLed.off();                                                   //Turns the blue led on
  redLed.on();                                                     //Turns the red led on
  buzz.off();                                                      //Shutsdown the buzzer
}

void setup(){
  Serial.begin(9600);
  motor1.begin();
  motor2.begin();
  redLed.begin();
  blueLed.begin();
  buzz.begin();

  //initilize the system by turing on the leds and buzzer
  initSystem();
  
  //State variable set to STOP initially
  state = STOP;
}

void loop()
{   
  switch(state)
  {
    case FRONT:
    blueLed.on();
    redLed.off();
    motor1.front();
    motor2.front();
    debug("Front: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case BACK:
    blueLed.on();
    redLed.off();
    motor1.back();
    motor2.back();
    debug("Back: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case LEFT:
    blueLed.on();
    redLed.off();
    motor1.back();
    motor2.front();
    debug("Left: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case RIGHT:
    blueLed.on();
    redLed.off();
    motor1.front();
    motor2.back();
    debug("Right: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
         
    case RIGHTSHIFT:
    blueLed.on();
    redLed.off();
    motor1.front();
    motor2.stop();
    debug("Right shift: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case LEFTSHIFT:
    blueLed.on();
    redLed.off();
    motor1.stop();
    motor2.front();
    debug("Left shift: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
   
    case BACKRIGHT:
    blueLed.on();
    redLed.off();
    motor1.stop();
    motor2.back();
    debug("Right Back: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case BACKLEFT:
    blueLed.on();
    redLed.off();
    motor1.back();
    motor2.stop();
    debug("Left Back: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;

    case STOP:
    buzz.off();
    blueLed.off();
    redLed.on();
    motor1.stop();
    motor2.stop();
    debug("Stop: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    if (Serial.available()) 
      state = Serial.read();        //Read the state
    break;
    
    case SPEED0:
    buzz.on();
    motor1.pwm = 0;
    motor2.pwm = 0;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case SPEED1:
    buzz.off();
    motor1.pwm = 25;
    motor2.pwm = 25;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case SPEED2:
    buzz.off();
    motor1.pwm = 51;
    motor2.pwm = 51;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case SPEED3:
    buzz.off();
    motor1.pwm = 76;
    motor2.pwm = 76;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case SPEED4:
    buzz.off();
    motor1.pwm = 102;
    motor2.pwm = 102;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case SPEED5:
    buzz.off();
    motor1.pwm = 127;
    motor2.pwm = 127;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case SPEED6:
    buzz.off();
    motor1.pwm = 153;
    motor2.pwm = 153;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case SPEED7:
    buzz.off();
    motor1.pwm = 178;
    motor2.pwm = 178;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case SPEED8:
    buzz.off();
    motor1.pwm = 204;
    motor2.pwm = 204;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case SPEED9:
    buzz.off();
    motor1.pwm = 229;
    motor2.pwm = 229;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;
    
    case MAXSPEED:
    buzz.off();
    motor1.pwm = 255;
    motor2.pwm = 255;
    debug("Speed: ");
    debug(motor1.pwm);
    debug(" : ");
    debugln(motor2.pwm);
    break;

    case STOPALL:
    buzz.off();
    blueLed.off();
    redLed.off();
    motor1.disable();
    motor2.disable();
    buzz.deinitBuzzer();
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
    
    default:
    debugln("Invalid input");
    break;
  }
}
