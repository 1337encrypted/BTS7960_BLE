#include "BTS7960_BLE.h"
#include <IBusBM.h>

#define DEBUG 0

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

BTS7960_BLE car;                                   //Create an object of class car
uint8_t key;                                       //Key for the switch case
  
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
        debugln("Foreward");
        break;
      case 'B':
        car.back();
        debugln("Backward");
        break;
      case 'L':
        car.leftTurn();
        debugln("Left");
        break;
      case 'R':
        car.rightTurn();
        debugln("Right");
        break;
      /*
      case 'I':
        car.rightShift();
        debugln("Right Shift");
        break;
      case 'G':
        car.leftShift();
        debugln("Left Shift");
        break;
        */
      case '0':
        car.Speed = 115;
        debugln("car.Speed = 115");
        break;
      case '1':
        car.Speed = 130;
        debugln("car.Speed = 130");
        break;
      case '2':
        car.Speed = 143;
        debugln("car.Speed = 143");
        break;
      case '3':
        car.Speed = 157;
        debugln("car.Speed = 157");
        break;
      case '4':
        car.Speed = 170;
        debugln("car.Speed = 170");
        break;
      case '5':
        car.Speed = 185;
        debugln("car.Speed = 185");
        break;
      case '6':
        car.Speed = 200;
        debugln("car.Speed = 200");
        break;
      case '7':
        car.Speed = 213;
        debugln("car.Speed = 213");
        break;
      case '8':
        car.Speed = 227;
        debugln("car.Speed = 227");
        break;
      case '9':
        car.Speed = 240;
        debugln("car.Speed = 240");
        break;
      case 'q':
        car.Speed = 255;
        debugln("car.Speed = 255");
        break;
      default: debugln("Invalid input, please choose 1 - 9,q");
    }
  }
}
