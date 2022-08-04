#include "BTS7960_BLE.h"

BTS7960TH9x car;                                   //Create an object of class car
uint8_t key;                                  //Key for the switch case
  
void setup(){
  
  Serial.begin(9600); 
  
}

void loop()
{
  if (Serial.available() > 0)
  {  
    key=Serial.read();
    car.Stp();
    switch(key)
    {
      case 'F':
        car.front();
        Serial.println("Foreward");
        break;
      case 'B':
        car.back();
        Serial.println("Backward");
        break;
      case 'L':
        car.leftTurn();
        Serial.println("Left");
        break;
      case 'R':
        car.rightTurn();
        Serial.println("Right");
        break;
      /*
      case 'I':
        car.rightShift();
        Serial.println("Right Shift");
        break;
      case 'G':
        car.leftShift();
        Serial.println("Left Shift");
        break;
        */
      case '0':
        car.Speed = 115;
        Serial.println("car.Speed = 115");
        break;
      case '1':
        car.Speed = 130;
        Serial.println("car.Speed = 130");
        break;
      case '2':
        car.Speed = 143;
        Serial.println("car.Speed = 143");
        break;
      case '3':
        car.Speed = 157;
        Serial.println("car.Speed = 157");
        break;
      case '4':
        car.Speed = 170;
        Serial.println("car.Speed = 170");
        break;
      case '5':
        car.Speed = 185;
        Serial.println("car.Speed = 185");
        break;
      case '6':
        car.Speed = 200;
        Serial.println("car.Speed = 200");
        break;
      case '7':
        car.Speed = 213;
        Serial.println("car.Speed = 213");
        break;
      case '8':
        car.Speed = 227;
        Serial.println("car.Speed = 227");
        break;
      case '9':
        car.Speed = 240;
        Serial.println("car.Speed = 240");
        break;
      case 'q':
        car.Speed = 255;
        Serial.println("car.Speed = 255");
        break;
      default: Serial.println("Invalid input, please choose 1 - 9,q");
    }
  }
}
