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
{
    if ((char)Serial.read() == '!') //start transmission
    {
      do
      {
        BANK.destination = Serial.read(); //-64;
      } while (BANK.destination < 0);
      BANK.destination -= 65;
      do
      {
        BANK.value = Serial.read(); //-100;
      } while (BANK.value < 0);
      BANK.value -= 100;
      BANK.setVarBuff();
    }
}

