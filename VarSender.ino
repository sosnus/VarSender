#include <Arduino.h>  
#include "VarSenderLib.h"

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(1000);
    
  for (uint8_t i = 0; i < 5; i++)
  {
   BANK.printVar(i);
   //BANK.getVar(i);
  } 
}


void serialEvent()
{ //new char on serialport

  uint8_t destination, value;
  while (Serial.available())
  {
    //start trans [!] variabl. [A-Z] value [100-199]
    if ((char)Serial.read() == '!') //start transmission
    {
      do
      {
        destination = Serial.read(); //-64;
      } while (destination < 0);
      destination -= 65;
      do
      {
        value = Serial.read(); //-100;
      } while (value < 0);
      value -= 100;
      BANK.setVar(destination,value);
      //values[destination] = value;
    }
  }
}

