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
  BANK.temp = Serial.read();
  if (BANK.temp < 64); //nothing
  else if (BANK.temp < 100)BANK.destination = BANK.temp - 65; //var
  else if (BANK.temp < 201) //val
  {
    BANK.value = BANK.temp - 100;
    BANK.setVarBuff();
  }
  else;
}
void serialEvent()
{
  BANK.temp = Serial.read();
  if (BANK.temp < 64); //nothing
  else if (BANK.temp < 100)BANK.destination = BANK.temp - 65; //var
  else if (BANK.temp < 201) //val
  {
    BANK.value = BANK.temp - 100;
    BANK.setVarBuff();
  }
  else;
}
