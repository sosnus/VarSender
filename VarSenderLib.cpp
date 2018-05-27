
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
      v.setVar(destination,value);
      //values[destination] = value;
    }
  }
}


