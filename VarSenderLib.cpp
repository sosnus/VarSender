
#include "VarSenderLib.h"
  
  void VarSender::printVar(uint8_t number);
  void VarSender::setVar(uint8_t var, uint8_t value);
  // void sendVar(uint8_t var);


  VarSender::VarSender(void)
  {
    if(1);
  }
  
//todo: func to print one value:
void VarSender::printVar(uint8_t number)
{
      Serial.print("v[");
      Serial.print(number);
      Serial.print("]=");
      Serial.println(values[number]);
}


void VarSender::setVar(uint8_t var, uint8_t value)
{
  values[var]=value;
}

