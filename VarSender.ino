#include <Arduino.h>

uint8_t values[100]; //from A to Z


void setup()
{
  Serial.begin(9600);


}

void loop()
{

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
      values[destination] = value;
    }
  }
}

