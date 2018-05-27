#include <Arduino.h>  
#include "VarSenderLib.h"


//VSL v = VSL();



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
  }
  
}

